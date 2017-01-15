#include "pch-MFC-Example-Snippets.hpp"
#include "GetAt.hpp"

IMPLEMENT_CRUNTIMECLASS_SUPPORT_DYNAMIC_CREATE(Examples::_CArray::GetAt)


/**
 *  Extension of the output operator.
 */

	inline std::wostream& operator<<(std::wostream& o, const CPoint& p)
{
	return o << '(' << p.x << ", " << p.y << ')';
}


namespace Examples {
	namespace _CArray {

		void GetAt::run()
		{
			const int N = 8;
			TEXT_OUT("Creating array...");
			CArray<CPoint> myArray;
			// myArray.SetSize(N);
			TEXT_OUT("Array size  == " << myArray.GetSize());
			TEXT_OUT("Array count == " << myArray.GetCount());
			TEXT_OUT("Array upper bound == " << myArray.GetUpperBound());

			for (int ii = 0; ii < N; ii++)
			{
				CPoint pt{ ii, 2 * ii };
				TEXT_OUT("Adding pt" << pt << "...");
				myArray.Add(pt);
			}

			TEXT_OUT("Array size        == " << myArray.GetSize());
			TEXT_OUT("Array count       == " << myArray.GetCount());
			TEXT_OUT("Array upper bound == " << myArray.GetUpperBound());

			TEXT_OUT("Modifying all the points in the array...");
			for (int ii = 0; ii <= myArray.GetUpperBound(); ii++)
			{
				CPoint pt = myArray.GetAt(ii);
				pt.x = 0;
				myArray.SetAt(ii, pt);
			}

			TEXT_OUT("Modified array:");
			for (int ii = 0; ii <= myArray.GetUpperBound(); ++ii)
			{
				TEXT_OUT("myArray[" << ii << "] == " << myArray[ii]);
			}

		}
	}
}
