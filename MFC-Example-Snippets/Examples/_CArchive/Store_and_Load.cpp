#include "pch-MFC-Example-Snippets.hpp"
#include "Store_and_Load.hpp"


IMPLEMENT_CRUNTIMECLASS_SUPPORT_DYNAMIC_CREATE(Examples::_CArchive::Store_and_Load)


namespace Examples {
	namespace _CArchive {

		void Store_and_Load::run()
		{
			TEXT_OUT("Opening example data file...");
			CFile myFile(_T("My__test__file.dat"), CFile::modeCreate | CFile::modeReadWrite);
			CString str1{ "String-1" }, str2{ "String-2" }, str;
			CComBSTR str3{ "String 3 is a BSTR!" };

			TEXT_OUT("Creating an archive for storing...");
			CArchive arStore(&myFile, CArchive::store);

			TEXT_OUT("Writing str1 to the archive...");
			arStore.WriteString(str1);
			arStore.WriteString(_T("\n"));

			TEXT_OUT("Writing str2 to the archive...");
			arStore.WriteString(str2);
			arStore.WriteString(_T("\n"));

			TEXT_OUT("Writing str3 to the archive...");
			arStore.WriteString(str3);
			arStore.WriteString(_T("\n"));

			TEXT_OUT("Closing the storing archive...");
			arStore.Close();

			TEXT_OUT("Creating a loading archive...");
			myFile.SeekToBegin();
			CArchive arLoad(&myFile, CArchive::load);

			TEXT_OUT("Reading the 1st string...");
			arLoad.ReadString(str);
			TEXT_OUT(str.GetString() << " == " << str1.GetString());
			ASSERT(str == str1);

			TEXT_OUT("Reading the 2nd string...");
			arLoad.ReadString(str);
			TEXT_OUT(str.GetString() << " == " << str1.GetString());
			ASSERT(str == str2);

			TEXT_OUT("Reading the 3rd string...");
			arLoad.ReadString(str);
			TEXT_OUT(str.GetString() << " == " << (LPWSTR)str3);
			ASSERT(str == str3);
		}
	}
}
