#include "pch-MFC-Example-Snippets.hpp"
#include "Compound.hpp"


IMPLEMENT_CRUNTIMECLASS_SUPPORT_DYNAMIC_CREATE(Examples::_CArchive::Compound)



class Part_A : public CObject
{
	int m_part_a_data;

public:

	Part_A(int ii = 0) : m_part_a_data{ ii } { }
	DECLARE_SERIAL(Part_A);
	void Serialize(CArchive& ar) override
	{
		if (ar.IsStoring())
		{
			ar << m_part_a_data;
		}
		else
		{
			ar >> m_part_a_data;
		}
	}

	/**
	 *  Retrieve the example data in Part A.
	 */
	__int64 data() const { return m_part_a_data; }
};



class Part_B : public CObject
{
	int m_part_b_data;

public:

	Part_B(int ii = 0) : m_part_b_data{ ii } { }
	DECLARE_SERIAL(Part_B);
	void Serialize(CArchive& ar) override
	{
		if (ar.IsStoring())
		{
			ar << m_part_b_data;
		}
		else
		{
			ar >> m_part_b_data;
		}
	}

	/**
	 *  Retrieve the example data in Part B.
	 */
	__int64 data() const { return m_part_b_data; }
};



class Compound_Part : public CObject
{
	int m_compound_data;

	/**
	 *  Embedded object for Part A.
	 */
	Part_A m_part_a;

	/**
	 *  Allocated object for Part B.  Allocation occurs in ctor.
	 */
	std::unique_ptr<Part_B> m_part_b;

	/**
	 *  Dynamically allocated object.
	 */
	std::unique_ptr<CObject> m_object;

public:

	Compound_Part(int ii = 0)
		: m_compound_data{ ii }
		, m_part_a{ ii - 1 }
		, m_part_b{ new Part_B{ ii - 2 } } // Exact type known and object allocated in ctor.
		, m_object{} // Will be allocated in a member function, if needed.
	{}


	DECLARE_SERIAL(Compound_Part);
	void Serialize(CArchive& ar) override;

	/**
	 *  Retrieve the example data in this compound part.
	 */
	__int64 data() const { return m_compound_data; }

	/**
	 *  Retrieve the example data from Part A.
	 */
	__int64 data_part_a() const { return m_part_a.data(); }

	/**
	 *  Retrieve the example data from Part B.
	 */
	__int64 data_part_b() const { return m_part_b->data(); }

	/**
	 *  Retrieve the example dynamically allocated object.
	 */
	CObject* dynamic_object() const { return m_object.get(); }

	/**
	 *  Allocate an example dynamically allocated object.
	 */
	CObject* allocate_dynamic_object()
	{
		m_object = std::make_unique<Part_A>( 31 );
		return m_object.get();
	}
};


IMPLEMENT_SERIAL(Part_A, CObject, 1)
IMPLEMENT_SERIAL(Part_B, CObject, 1)
IMPLEMENT_SERIAL(Compound_Part, CObject, 1)



void Compound_Part::Serialize(CArchive& ar)
{
	CObject::Serialize(ar);    // Always call base class Serialize.
	m_part_a.Serialize(ar);    // Call Serialize on embedded member.
	m_part_b->Serialize(ar);    // Call Serialize on objects of known exact type.

								// Serialize dynamic members and other raw data
	if (ar.IsStoring())
	{
		ar << m_object.get();
		ar << m_compound_data;
	}
	else
	{
		CObject * tmp_ptr;
		ar >> tmp_ptr; // Polymorphic reconstruction of persistent object.
		m_object.reset(tmp_ptr); 
		ar >> m_compound_data;
	}
}




namespace Examples {
	namespace _CArchive {

		void Compound::run()
		{
			TEXT_OUT("Creating new Compound Part...");
			auto compound_part = std::make_unique<Compound_Part>(49);

			TEXT_OUT("New Compound Part:");
			TEXT_OUT("          data == " << compound_part->data());
			TEXT_OUT("   Part A data == " << compound_part->data_part_a());
			TEXT_OUT("   Part B data == " << compound_part->data_part_b());
			TEXT_OUT(" Dynamic object is " << (compound_part->dynamic_object() == nullptr ? "null" : "NOT null"));

			TEXT_OUT("Allocating dynamic object...");
			compound_part->allocate_dynamic_object();
			TEXT_OUT(" Dynamic object is " << (compound_part->dynamic_object() == nullptr ? "null" : "NOT null"));
			auto dynamic_part_a = dynamic_cast<Part_A*>(compound_part->dynamic_object());
			ASSERT(dynamic_part_a != nullptr);
			TEXT_OUT("  Dynamic data == " << dynamic_part_a->data());

			TEXT_OUT("Opening example data file...");
			CFile myFile(L"My__test__file.dat", CFile::modeCreate | CFile::modeReadWrite);

			TEXT_OUT("Creating an archive for storing...");
			CArchive arStore(&myFile, CArchive::store);

			TEXT_OUT("Writing Compound Part to the archive...");
			compound_part->Serialize(arStore);

			TEXT_OUT("Closing the storing archive...");
			arStore.Close();

			TEXT_OUT("Creating an archive for loading...");
			myFile.SeekToBegin();
			CArchive arLoad(&myFile, CArchive::load);

			TEXT_OUT("Creating new empty Derived Class...");
			auto loaded_object = std::make_unique<Compound_Part>();
			TEXT_OUT("Before load:");
			TEXT_OUT("          data == " << loaded_object->data());
			TEXT_OUT("   Part A data == " << loaded_object->data_part_a());
			TEXT_OUT("   Part B data == " << loaded_object->data_part_b());
			TEXT_OUT(" Dynamic object is " << (loaded_object->dynamic_object() == nullptr ? "null" : "NOT null"));

			TEXT_OUT("Loading object...");
			loaded_object->Serialize(arLoad);

			TEXT_OUT("After load:");
			TEXT_OUT("          data == " << loaded_object->data());
			TEXT_OUT("   Part A data == " << loaded_object->data_part_a());
			TEXT_OUT("   Part B data == " << loaded_object->data_part_b());
			TEXT_OUT(" Dynamic object is " << (loaded_object->dynamic_object() == nullptr ? "null" : "NOT null"));
			auto dynamic_part_a_loaded = dynamic_cast<Part_A*>(loaded_object->dynamic_object());
			ASSERT(dynamic_part_a_loaded != nullptr);
			TEXT_OUT("  Dynamic data == " << dynamic_part_a_loaded->data());
		}
	}
}
