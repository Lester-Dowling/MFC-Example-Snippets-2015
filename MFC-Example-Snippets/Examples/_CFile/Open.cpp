#include "pch-MFC-Example-Snippets.hpp"
#include "Open.hpp"


IMPLEMENT_CRUNTIMECLASS_SUPPORT_DYNAMIC_CREATE(Examples::_CFile::Open)


namespace Examples {

	void _CFile::Open::run()
	{
		CFile f;
		CFileException ex;
		TCHAR* pszFileName = _T("Open_File.dat");
		TEXT_OUT("Attempting to open file for read-only access...");
		if (!f.Open(pszFileName, CFile::modeRead, &ex))
		{
			const UINT err_buf_size = 1024;
			wchar_t err_buf[err_buf_size] = {};
			ex.GetErrorMessage(err_buf, err_buf_size);
			TEXT_OUT("*** [Exception] File could not be opened: " << err_buf);
		}
	}

}
