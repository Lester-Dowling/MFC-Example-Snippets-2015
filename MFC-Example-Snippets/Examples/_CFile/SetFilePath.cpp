#include "pch-MFC-Example-Snippets.hpp"
#include "SetFilePath.hpp"

IMPLEMENT_CRUNTIMECLASS_SUPPORT_DYNAMIC_CREATE(Examples::_CFile::SetFilePath)

namespace Examples {

	void _CFile::SetFilePath::run()
	{
		wchar_t* pstrName = L"C:/Users/ljdowling/studies/MFC/MFC-Example-Snippets-2015/MFC-Example-Snippets/SetPath_File.txt";

		TEXT_OUT("Opening file with CreateFile...");
		HANDLE hFile = ::CreateFile(pstrName, GENERIC_WRITE, FILE_SHARE_READ, NULL, CREATE_ALWAYS, 0, NULL);

		if (hFile == INVALID_HANDLE_VALUE)
		{
			TEXT_OUT("*** [Error] Invalid handle returned from CreateFile.");
			return;
		}

		TEXT_OUT("Attaching a CFile to file handle...");
		CFile myFile(hFile);

		// At this point, myFile doesn't know the path name for the file
		// it owns because Windows doesn't associate that information
		// with the handle. Any CFileExceptions thrown by this object
		// won't have complete information.

		// Calling SetFilePath() remedies that problem by letting CFile
		// know the name of the file that's associated with the object.

		TEXT_OUT("Invoking SetFilePath...");
		myFile.SetFilePath(pstrName);

		TEXT_OUT("Writing a little something to the file...");
		DWORD dwValue = 1234;
		myFile.Write(&dwValue, sizeof(dwValue));

		TEXT_OUT("Flushing the file immediately...");
		myFile.Flush();

		TEXT_OUT("Destroying the CFile as it goes out of scope here will call ::CloseHandle() on the file.");
	}

}
