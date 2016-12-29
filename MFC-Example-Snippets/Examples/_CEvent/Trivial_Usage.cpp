#include "pch-MFC-Example-Snippets.hpp"
#include "Trivial_Usage.hpp"
namespace Examples {

	UINT _CEvent::Trivial_Usage::MyThreadProc(LPVOID lpParameter)
	{
		CEvent* pEvent = (CEvent*)(lpParameter);
		VERIFY(pEvent != NULL);

		// Wait for the event to be signaled:
		::WaitForSingleObject(pEvent->m_hObject, INFINITE);

		// Terminate the thread:
		::AfxEndThread(0, FALSE);
		return 0L;
	}



	void _CEvent::Trivial_Usage::run()
	{
		m_text_output(L"Creating the CEvent object that will be passed to the thread routine...");
		std::unique_ptr<CEvent> pEvent{ new CEvent(FALSE, FALSE) };

		m_text_output(L"Creating a thread that will wait on the event...");
		std::unique_ptr<CWinThread> pThread{ AfxBeginThread(&MyThreadProc, pEvent.get(), 0, 0, CREATE_SUSPENDED, NULL) };
		pThread->m_bAutoDelete = FALSE;
		pThread->ResumeThread();

		m_text_output(L"Signalling the thread to do the next work item...");
		pEvent->SetEvent();

		m_text_output(L"Waiting for the thread to consume the event and return...");
		::WaitForSingleObject(pThread->m_hThread, INFINITE);
	}

}
