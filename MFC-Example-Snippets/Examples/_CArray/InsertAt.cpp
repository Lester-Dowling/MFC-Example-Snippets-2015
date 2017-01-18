#include "pch-MFC-Example-Snippets.hpp"
#include "InsertAt.hpp"

IMPLEMENT_CRUNTIMECLASS_SUPPORT_DYNAMIC_CREATE(Examples::_CArray::InsertAt)

/**
 *  Extension of the output operator for CPoint.
 */
	inline std::wostream& operator<<(std::wostream& o, const CPoint& p)
{
	return o << '(' << p.x << ", " << p.y << ')';
}


namespace Examples {
	namespace _CArray {

		void InsertAt::run()
		{
			const int N = 3;

			CArray<CPoint> ptArray;
			for (int idx = 0; idx < N; idx++) ptArray.Add(CPoint{ idx, 30 * idx });

			TEXT_OUT("Original array:");
			for (int idx = 0; idx < ptArray.GetSize(); ++idx)
				TEXT_OUT("ptArray[" << idx << "] == " << ptArray[idx]);

			TEXT_OUT("Inserting elements...");
			ptArray.InsertAt(1, CPoint{ 50, 60 });
			ptArray.InsertAt(2, CPoint{ 150, 260 });

			TEXT_OUT("Modified ptArray:");
			for (int idx = 0; idx < ptArray.GetSize(); ++idx)
				TEXT_OUT("ptArray[" << idx << "] == " << ptArray[idx]);

			TEXT_OUT("Creating more array:");
			CArray<CPoint> moreArray;
			for (int idx = 0; idx < N; idx++) moreArray.Add(CPoint{ 100 * idx, 10 * idx });
			for (int idx = 0; idx < moreArray.GetSize(); ++idx)
				TEXT_OUT("moreArray[" << idx << "] == " << moreArray[idx]);

			TEXT_OUT("Inserting more array...");
			ptArray.InsertAt(3, &moreArray);

			TEXT_OUT("Modified ptArray:");
			for (int idx = 0; idx < ptArray.GetSize(); ++idx)
				TEXT_OUT("ptArray[" << idx << "] == " << ptArray[idx]);
		}
	}
}
