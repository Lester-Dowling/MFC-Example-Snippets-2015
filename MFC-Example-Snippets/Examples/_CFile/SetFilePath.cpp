#include "pch-MFC-Example-Snippets.hpp"
#include "SetFilePath.hpp"
namespace Examples {

	void _CFile::SetFilePath::run()
	{
		wchar_t* pstrName = L"C:/Users/ljdowling/studies/MFC/MFC-Example-Snippets-2015/MFC-Example-Snippets/SetPath_File.txt";

		m_text_output(L"Opening file with CreateFile...");
		HANDLE hFile = ::CreateFile(pstrName, GENERIC_WRITE, FILE_SHARE_READ, NULL, CREATE_ALWAYS, 0, NULL);

		if (hFile == INVALID_HANDLE_VALUE)
		{
			m_text_output(L"*** [Error] Invalid handle returned from CreateFile.");
			return;
		}

		m_text_output(L"Attaching a CFile to file handle...");
		CFile myFile(hFile);

		// At this point, myFile doesn't know the path name for the file
		// it owns because Windows doesn't associate that information
		// with the handle. Any CFileExceptions thrown by this object
		// won't have complete information.

		// Calling SetFilePath() remedies that problem by letting CFile
		// know the name of the file that's associated with the object.

		m_text_output(L"Invoking SetFilePath...");
		myFile.SetFilePath(pstrName);

		m_text_output(L"Writing a little something to the file...");
		DWORD dwValue = 1234;
		myFile.Write(&dwValue, sizeof(dwValue));

		m_text_output(L"Flushing the file immediately...");
		myFile.Flush();

		m_text_output(L"Destroying the CFile as it goes out of scope here will call ::CloseHandle() on the file.");
	}

}
