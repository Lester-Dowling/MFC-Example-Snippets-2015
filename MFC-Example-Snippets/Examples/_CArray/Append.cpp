#include "pch-MFC-Example-Snippets.hpp"
#include "Append.hpp"

IMPLEMENT_CRUNTIMECLASS_SUPPORT_DYNAMIC_CREATE(Examples::_CArray::Append)

/**
 *  Extension of the output operator.
 */
	inline std::wostream& operator<<(std::wostream& o, const CPoint& p)
{
	return o << '(' << p.x << ", " << p.y << ')';
}


namespace Examples {
	namespace _CArray {

		void Append::run()
		{
			CArray<CPoint, CPoint> myArray1, myArray2;

			TEXT_OUT("Adding elements to the second array...");
			myArray2.Add(CPoint(11, 22));
			myArray2.Add(CPoint(12, 42));
			TEXT_OUT("Second array:");
			for (int ii = 0; ii <= myArray2.GetUpperBound(); ++ii)
			{
				TEXT_OUT("myArray2[" << ii << "] == " << myArray2[ii]);
			}


			TEXT_OUT("Adding elements to the first array...");
			myArray1.Add(CPoint(1, 2));
			TEXT_OUT("First array:");
			for (int ii = 0; ii <= myArray1.GetUpperBound(); ++ii)
			{
				TEXT_OUT("myArray1[" << ii << "] == " << myArray1[ii]);
			}

			TEXT_OUT("Appending elements of the second array...");
			myArray1.Append(myArray2);
			TEXT_OUT("First array:");
			for (int ii = 0; ii <= myArray1.GetUpperBound(); ++ii)
			{
				TEXT_OUT("myArray1[" << ii << "] == " << myArray1[ii]);
			}
		}
	}
}
