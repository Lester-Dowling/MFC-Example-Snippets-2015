#include "pch-MFC-Example-Snippets.hpp"
#include "AddHead.hpp"
#include <random>
// https://msdn.microsoft.com/en-us/library/bb982398.aspx
// https://msdn.microsoft.com/en-us/library/bb982250.aspx
// https://msdn.microsoft.com/en-us/library/398ax69y.aspx
// https://msdn.microsoft.com/en-us/library/hh567368.aspx

// https://msdn.microsoft.com/en-us/library/425sx0t2.aspx

IMPLEMENT_CRUNTIMECLASS_SUPPORT_DYNAMIC_CREATE(Examples::_CObList::AddHead)

// Simple CObject-derived class for CObList and other examples
class CAge : public CObject
{

	int   m_years;

public: // Ctors et al --------------------------------------------------------

	CAge() { m_years = 0; }
	CAge(int age) { m_years = age; }
	CAge(const CAge& a) { m_years = a.m_years; }
	const CAge& operator=(const CAge& a) { m_years = a.m_years; return *this; }
	DECLARE_SERIAL(CAge);

public: // Accessors and Mutators ---------------------------------------------

	int years() const { return m_years; }

	void set_years(int years) { m_years = years; }

public: // Overrides ----------------------------------------------------------

	void Serialize(CArchive& ar) override
	{
		if (ar.IsStoring())
		{
			ar << m_years;
		}
		else
		{
			ar >> m_years;
		}
	}


	friend bool operator==(const CAge& lhs, const CAge& rhs)
	{
		return lhs.m_years == rhs.m_years;
	}
};


IMPLEMENT_SERIAL(CAge, CObject, 1);


/**
 *  Extension of the output operator for CAge.
 */
inline std::wostream& operator<<(std::wostream& o, const CAge& p)
{
	return o << '{' << p.years() << '}';
}



namespace Examples {
	namespace _CObList {

		void AddHead::run()
		{
			TEXT_OUT("Creating list...");
			CObList list;
			list.AddHead(new CAge{ 21 });
			list.AddHead(new CAge{ 40 });

			TEXT_OUT("List:");
			int idx = 0;
			for (POSITION pos = list.GetHeadPosition(); pos != NULL; ++idx)
			{
				CAge *pAge = dynamic_cast<CAge*>(list.GetNext(pos));
				TEXT_OUT("list[" << idx << "] == " << *pAge);
			}
		}
	}
}
