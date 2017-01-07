#include "pch-MFC-Example-Snippets.hpp"
#include "SerializeClass.hpp"


IMPLEMENT_CRUNTIMECLASS_SUPPORT_DYNAMIC_CREATE(Examples::_CArchive::SerializeClass)

/**
 *  BaseClass
 *
 *  Example base class.
 */
class BaseClass : public CObject
{
	/**
	 *  Piece of example data for the base class.
	 */
	__int64 m_base_data;

public:
	/**
	 *  Ctor to construct a BaseClass with the given piece of data.
	 */
	BaseClass(__int64 base_data = 0) : m_base_data{ base_data } {}
	DECLARE_SERIAL(BaseClass);

	/**
	 *  Serialize the base class.
	 */
	void Serialize(CArchive& ar) override;

	/**
	 *  Retrieve the example data held by the base class.
	 */
	__int64 base_data() const { return m_base_data; }
};



IMPLEMENT_SERIAL(BaseClass, CObject, 1)



void BaseClass::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		ar << m_base_data;
	}
	else
	{
		ar >> m_base_data;
	}
}


/**
 *  DerivedClass
 *
 *  Example class derived from the example base class.
 */
class DerivedClass : public BaseClass
{
	/**
	 *  Piece of example data for the derived class.
	 */
	__int64 m_derived_data;

public:
	/**
	 * No-arg ctor to construct an empty base class with data set to zero.
	 */
	DerivedClass() : BaseClass{}, m_derived_data{} {}

	/**
	*  Ctor to construct a DerivedClass with the given piece of data.
	*/
	DerivedClass(__int64 derived_data) : BaseClass{ derived_data - 1 }, m_derived_data { derived_data } {}
	DECLARE_SERIAL(DerivedClass);

	/**
	 *  Serialize the derived class.
	 */
	void Serialize(CArchive& ar) override;

	/**
	 *  Retrieve the data held by the derived class.
	 */
	__int64 derived_data() const { return m_derived_data; }
};



IMPLEMENT_SERIAL(DerivedClass, BaseClass, 1)



void DerivedClass::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		ar << m_derived_data;
	}
	else
	{
		ar >> m_derived_data;
	}
	// Now serialize the base class:
	ar.SerializeClass(RUNTIME_CLASS(BaseClass));
	BaseClass::Serialize(ar);
}



namespace Examples {
	namespace _CArchive {

		void SerializeClass::run()
		{
			TEXT_OUT("Creating new Derived Class...");
			auto derived_class = std::make_unique<DerivedClass>(49);

			TEXT_OUT("New derived class, base data    == " << derived_class->base_data());
			TEXT_OUT("New derived class, derived data == " << derived_class->derived_data());

			TEXT_OUT("Opening example data file...");
			CFile myFile(L"My__test__file.dat", CFile::modeCreate | CFile::modeReadWrite);

			TEXT_OUT("Creating an archive for storing...");
			CArchive arStore(&myFile, CArchive::store);

			TEXT_OUT("Writing Derived Class to the archive...");
			derived_class->Serialize(arStore);

			TEXT_OUT("Closing the storing archive...");
			arStore.Close();

			TEXT_OUT("Creating an archive for loading...");
			myFile.SeekToBegin();
			CArchive arLoad(&myFile, CArchive::load);

			TEXT_OUT("Creating new empty Derived Class...");
			auto my_loaded_class = std::make_unique<DerivedClass>();
			TEXT_OUT("Before load, base data    == " << my_loaded_class->base_data());
			TEXT_OUT("Before load, derived data == " << my_loaded_class->derived_data());

			TEXT_OUT("Loading class...");
			my_loaded_class->Serialize(arLoad);

			TEXT_OUT("After load, base data    == " << my_loaded_class->base_data());
			TEXT_OUT("After load, derived data == " << my_loaded_class->derived_data());
		}
	}
}
