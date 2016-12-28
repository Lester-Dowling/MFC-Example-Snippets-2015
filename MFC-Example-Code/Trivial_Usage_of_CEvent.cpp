#include "pch-MFC-Example-Code.hpp"
#include "Trivial_Usage_of_CEvent.hpp"
namespace Example {


	UINT Trivial_Usage_of_CEvent::MyThreadProc(LPVOID lpParameter)
	{
		CEvent* pEvent = (CEvent*)(lpParameter);
		VERIFY(pEvent != NULL);

		// Wait for the event to be signaled:
		::WaitForSingleObject(pEvent->m_hObject, INFINITE);

		// Terminate the thread:
		::AfxEndThread(0, FALSE);
		return 0L;
	}



	void Trivial_Usage_of_CEvent::run()
	{
		// Create the CEvent object that will be passed to the thread routine
		std::unique_ptr<CEvent> pEvent{ new CEvent(FALSE, FALSE) };

		// Create a thread that will wait on the event:
		std::unique_ptr<CWinThread> pThread{ AfxBeginThread(&MyThreadProc, pEvent.get(), 0, 0, CREATE_SUSPENDED, NULL) };
		pThread->m_bAutoDelete = FALSE;
		pThread->ResumeThread();

		// Signal the thread to do the next work item:
		pEvent->SetEvent();

		// Wait for the thread to consume the event and return:
		::WaitForSingleObject(pThread->m_hThread, INFINITE);
	}

}
