#include "pch-MFC-Example-Snippets.hpp"
#include "Open.hpp"
namespace Examples {

	void _CFile::Open::run()
	{
		CFile f;
		CFileException ex;
		TCHAR* pszFileName = _T("Open_File.dat");
		m_text_output(L"Attempting to open file for read-only access...");
		if (!f.Open(pszFileName, CFile::modeRead, &ex))
		{
			const UINT err_buf_size = 1024;
			wchar_t err_buf[err_buf_size] = {};
			ex.GetErrorMessage(err_buf, err_buf_size);
			std::wostringstream oss;
			oss << "*** [Exception] File could not be opened: " << err_buf;
			m_text_output(oss.str());
		}
	}

}
