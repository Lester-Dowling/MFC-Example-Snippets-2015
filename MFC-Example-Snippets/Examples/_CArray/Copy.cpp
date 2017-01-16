#include "pch-MFC-Example-Snippets.hpp"
#include "Copy.hpp"

IMPLEMENT_CRUNTIMECLASS_SUPPORT_DYNAMIC_CREATE(Examples::_CArray::Copy)

/**
 *  Extension of the output operator.
 */
	inline std::wostream& operator<<(std::wostream& o, const CPoint& p)
{
	return o << '(' << p.x << ", " << p.y << ')';
}


namespace Examples {
	namespace _CArray {

		void Copy::run()
		{
			const int N = 3;
			TEXT_OUT("Creating original array...");
			CArray<CPoint> original_array; original_array.SetSize(N);
			TEXT_OUT("Original array size  == " << original_array.GetSize());
			for (int idx = 0; idx < original_array.GetSize(); ++idx)
			{
				CPoint pt{ idx, 2 * idx };
				TEXT_OUT("Adding pt " << pt << "...");
				original_array[idx] = pt;
			}

			TEXT_OUT("Original array:");
			for (int idx = 0; idx < original_array.GetSize(); ++idx)
			{
				TEXT_OUT("original_array[" << idx << "] == " << original_array[idx]);
			}

			const int M = 2;
			TEXT_OUT("Creating duplicate array...");
			CArray<CPoint> duplicate_array; duplicate_array.SetSize(M);
			TEXT_OUT("Duplicate array size == " << duplicate_array.GetSize());

			TEXT_OUT("Copying original array...");
			duplicate_array.Copy(original_array);
			TEXT_OUT("Duplicate array size == " << duplicate_array.GetSize());

			TEXT_OUT("Duplicate array:");
			for (int idx = 0; idx < duplicate_array.GetSize(); ++idx)
			{
				TEXT_OUT("duplicate_array[" << idx << "] == " << duplicate_array[idx]);
			}

		}
	}
}
