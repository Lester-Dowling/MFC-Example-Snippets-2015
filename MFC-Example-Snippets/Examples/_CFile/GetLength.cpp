#include "pch-MFC-Example-Snippets.hpp"
#include "GetLength.hpp"
namespace Examples {

	void _CFile::GetLength::run()
	{
		CFile* pFile = NULL;
		// Constructing a CFile object with this override may throw
		// a CFile exception, and won't throw any other exceptions.
		// Calling CString::Format() may throw a CMemoryException,
		// so we have a catch block for such exceptions, too. Any
		// other exception types this function throws will be
		// routed to the calling function.
		try
		{
			TEXT_OUT("Opening file for read-only...");
			pFile = new CFile(_T("C:\\WINDOWS\\SYSTEM.INI"), CFile::modeRead | CFile::shareDenyNone);

			TEXT_OUT("Getting length...");
			ULONGLONG dwLength = pFile->GetLength();

			std::wostringstream oss;
			TEXT_OUT("The SYSTEM.INI file is " << dwLength << " bytes long.");
		}
		catch (CFileException* pEx)
		{
			pEx->ReportError();
			pEx->Delete();
		}
		catch (CMemoryException* pEx)
		{
			pEx->ReportError();
			pEx->Delete();
			// We can't recover from this memory exception, so we'll
			// just terminate the app without any cleanup. Normally,
			// an application should do everything it possibly can to
			// clean up properly and _not_ call AfxAbort().
			AfxAbort();
		}

		// If an exception occurs in the CFile constructor,
		// the language will free the memory allocated by new
		// and will not complete the assignment to pFile.
		// Thus, our clean-up code needs to test for NULL.
		if (pFile != NULL)
		{
			TEXT_OUT("Closing file...");
			pFile->Close();
			delete pFile;
		}
	}


}
