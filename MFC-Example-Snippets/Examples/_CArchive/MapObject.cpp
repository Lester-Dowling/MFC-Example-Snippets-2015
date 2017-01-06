#include "pch-MFC-Example-Snippets.hpp"
#include "MapObject.hpp"


IMPLEMENT_CRUNTIMECLASS_SUPPORT_DYNAMIC_CREATE(Examples::_CArchive::MapObject)



//MyDocument.h
class MyDocument : public CDocument
{
public:
	DECLARE_SERIAL(MyDocument)

	CObList m_listOfSubItems;

	void Serialize(CArchive& ar) override;
};



//SubItem.h
class SubItem : public CObject
{
	DECLARE_SERIAL(SubItem)
	SubItem() : m_i(0) {};
	SubItem(int i) : m_i{ i } {}

public:
	SubItem(MyDocument * pDoc)
	{
		m_pDoc = pDoc;
	}

	// back pointer to owning document
	MyDocument* m_pDoc;
	int m_i; // other item data

	void Serialize(CArchive& ar) override;
};



//MyDocument.cpp
IMPLEMENT_SERIAL(MyDocument, CDocument, 1)

void MyDocument::Serialize(CArchive& ar)
{
	CDocument::Serialize(ar);

	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}

	ar.MapObject(this);

	//serialize the subitems in the document;
	//they will be able to serialize their m_pDoc
	//back pointer
	m_listOfSubItems.Serialize(ar);
}



//SubItem.cpp
IMPLEMENT_SERIAL(SubItem, CObject, 1);

void SubItem::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// will serialize a reference 
		// to the "mapped" document pointer
		ar << (CObject *)m_pDoc;
		ar << m_i;
	}
	else
	{
		// Will load a reference to
		// the "mapped" document pointer
		ar >> (CObject *&)m_pDoc;
		ar >> m_i;
	}
}



namespace Examples {
	namespace _CArchive {

		void MapObject::run()
		{
			TEXT_OUT("Creating new MyDocument...");
			auto mydoc = std::make_unique<MyDocument>();

			TEXT_OUT("Appending subitems...");
			mydoc->m_listOfSubItems.AddTail(new SubItem{ 1 });
			mydoc->m_listOfSubItems.AddTail(new SubItem{ 2 });
			mydoc->m_listOfSubItems.AddTail(new SubItem{ 3 });

			TEXT_OUT("SubItems that were appended: ");
			POSITION si_pos = mydoc->m_listOfSubItems.GetHeadPosition();
			while (si_pos)
			{
				CObject* sio = mydoc->m_listOfSubItems.GetNext(si_pos);
				SubItem *si = dynamic_cast<SubItem*>(sio);
				if (!si) continue;
				TEXT_OUT(si->m_i);
			}

			TEXT_OUT("Opening example data file...");
			CFile myFile(L"My__test__file.dat", CFile::modeCreate | CFile::modeReadWrite);

			TEXT_OUT("Creating an archive for storing...");
			CArchive arStore(&myFile, CArchive::store);

			TEXT_OUT("Writing MyDocument to the archive...");
			mydoc->Serialize(arStore);

			TEXT_OUT("Closing the storing archive...");
			arStore.Close();

			TEXT_OUT("Creating a loading archive...");
			myFile.SeekToBegin();
			CArchive arLoad(&myFile, CArchive::load);

			TEXT_OUT("Creating new MyDocument from loaded archive...");
			auto my_loaded_doc = std::make_unique<MyDocument>();
			my_loaded_doc->Serialize(arLoad);

			TEXT_OUT("SubItems that were loaded: ");
			POSITION lsi_pos = my_loaded_doc->m_listOfSubItems.GetHeadPosition();
			while (lsi_pos)
			{
				CObject* sio = my_loaded_doc->m_listOfSubItems.GetNext(lsi_pos);
				SubItem *si = dynamic_cast<SubItem*>(sio);
				if (!si) continue;
				TEXT_OUT(si->m_i);
			}

		}
	}
}
