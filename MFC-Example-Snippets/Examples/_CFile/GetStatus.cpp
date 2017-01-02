#include "pch-MFC-Example-Snippets.hpp"
#include "GetStatus.hpp"

IMPLEMENT_CRUNTIMECLASS_SUPPORT_DYNAMIC_CREATE(Examples::_CFile::GetStatus)

namespace Examples {


	void _CFile::GetStatus::run()
	{
		TEXT_OUT("Opening file...");
		CFile cfile; cfile.Open(_T("SetLength_File.dat"), CFile::modeCreate | CFile::modeReadWrite);
		
		TEXT_OUT("Setting new length...");
		ULONGLONG dwNewLength = 10000;
		cfile.SetLength(dwNewLength);

		TEXT_OUT("Getting status via member method...");
		CFileStatus status;
		if (cfile.GetStatus(status))    // Member method.
			TEXT_OUT("File size = " << status.m_size);

		TEXT_OUT("Getting status via class method...");
		TCHAR* pszFileName = _T("SetLength_File.dat");
		if (CFile::GetStatus(pszFileName, status))   // Class method.
			TEXT_OUT("Full file name = " << status.m_szFullName);
	}


}

