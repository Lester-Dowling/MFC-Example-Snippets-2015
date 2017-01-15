#include "pch-MFC-Example-Snippets.hpp"
#include "Add.hpp"

IMPLEMENT_CRUNTIMECLASS_SUPPORT_DYNAMIC_CREATE(Examples::_CArray::Add)


/**
*  Extension of the output operator.
*/

inline std::wostream& operator<<(std::wostream& o, const CPoint& p)
{
	return o << '(' << p.x << ", " << p.y << ')';
}


namespace Examples {
	namespace _CArray {

		void Add::run()
		{
			CArray<CPoint> ptArray;

			CPoint pt1(10, 20);
			TEXT_OUT("Adding pt1: " << pt1 << "...");
			ptArray.Add(pt1);

			ptArray.Add(CPoint(30, 40)); 
			TEXT_OUT("Added another point: " << ptArray.GetAt(ptArray.GetUpperBound()));

			TEXT_OUT("Size of ptArray == " << ptArray.GetCount());
		}
	}
}
