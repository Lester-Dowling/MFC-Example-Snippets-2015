#include "pch-MFC-Example-Snippets.hpp"
#include "Trivial_Usage.hpp"


IMPLEMENT_CRUNTIMECLASS_SUPPORT_DYNAMIC_CREATE(Examples::_CEvent::Trivial_Usage)


namespace Examples {
    namespace _CEvent {



        UINT Trivial_Usage::MyThreadProc(LPVOID lpParameter)
        {
            CEvent* pEvent = (CEvent*)(lpParameter);
            VERIFY(pEvent != NULL);

            // Wait for the event to be signaled:
            ::WaitForSingleObject(pEvent->m_hObject, INFINITE);

            // Terminate the thread:
            ::AfxEndThread(0, FALSE);
            return 0L;
        }



        void Trivial_Usage::run()
        {
            TEXT_OUT("Creating the CEvent object that will be passed to the thread routine...");
            std::unique_ptr<CEvent> pEvent{ new CEvent(FALSE, FALSE) };

            TEXT_OUT("Creating a thread that will wait on the event...");
            std::unique_ptr<CWinThread> pThread{ AfxBeginThread(&MyThreadProc, pEvent.get(), 0, 0, CREATE_SUSPENDED, NULL) };
            pThread->m_bAutoDelete = FALSE;
            pThread->ResumeThread();

            TEXT_OUT("Signalling the thread to do the next work item...");
            pEvent->SetEvent();

            TEXT_OUT("Waiting for the thread to consume the event and return...");
            ::WaitForSingleObject(pThread->m_hThread, INFINITE);
        }
    }
}
