#include "pch-MFC-Example-Snippets.hpp"
#include "GetStatus.hpp""
namespace Examples {


	void _CFile::GetStatus::run()
	{
		m_text_output(L"Opening file...");
		CFile cfile; cfile.Open(_T("SetLength_File.dat"), CFile::modeCreate | CFile::modeReadWrite);
		
		m_text_output(L"Setting new length...");
		ULONGLONG dwNewLength = 10000;
		cfile.SetLength(dwNewLength);

		m_text_output(L"Getting status via member method...");
		CFileStatus status;
		if (cfile.GetStatus(status))    // Member method.
		{
			std::wostringstream oss;
			oss << "File size = " << status.m_size;
			m_text_output(oss.str());
		}

		m_text_output(L"Getting status via class method...");
		TCHAR* pszFileName = _T("SetLength_File.dat");
		if (CFile::GetStatus(pszFileName, status))   // Class method.
		{
			std::wostringstream oss;
			oss << "Full file name = " << status.m_szFullName;
			m_text_output(oss.str());
		}
	}


}

