#include "pch-MFC-Example-Snippets.hpp"
#include "Store_and_Load.hpp"


IMPLEMENT_CRUNTIMECLASS_SUPPORT_DYNAMIC_CREATE(Examples::_CArchive::Store_and_Load)


namespace Examples {
	namespace _CArchive {

		void Store_and_Load::run()
		{
			TEXT_OUT("Opening example data file...");
			CFile myFile(_T("My__test__file.dat"), CFile::modeCreate | CFile::modeReadWrite);
			CString str1("String1"), str2("String2"), str;

			TEXT_OUT("Creating an archive for storing...");
			CArchive arStore(&myFile, CArchive::store);

			TEXT_OUT("Writing str1 and str2 to the archive...");
			arStore.WriteString(str1);
			arStore.WriteString(_T("\n"));
			arStore.WriteString(str2);
			arStore.WriteString(_T("\n"));

			TEXT_OUT("Closing the storing archive...");
			arStore.Close();

			TEXT_OUT("Creating a loading archive...");
			myFile.SeekToBegin();
			CArchive arLoad(&myFile, CArchive::load);

			TEXT_OUT("Verifying the two strings are in the archive:");
			arLoad.ReadString(str);
			TEXT_OUT(str.GetString() << " == " << str1.GetString());
			ASSERT(str == str1);
			arLoad.ReadString(str);
			TEXT_OUT(str.GetString() << " == " << str1.GetString());
			ASSERT(str == str2);
		}
	}
}
