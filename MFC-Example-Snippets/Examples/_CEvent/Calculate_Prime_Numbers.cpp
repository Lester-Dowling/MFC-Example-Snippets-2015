#include "pch-MFC-Example-Snippets.hpp"
#include "Calculate_Prime_Numbers.hpp"
namespace Examples {


    _CEvent::Calculate_Prime_Numbers::Calculate_Prime_Numbers(std::wostringstream *text_out_stream)
        : m_pCalcNext(new CEvent(FALSE, FALSE))
        , m_pCalcFinished(new CEvent(FALSE, FALSE))
        , m_pTerminateThread(new CEvent(FALSE, FALSE))
        , m_iCurrentPrime(0)
    {}



    _CEvent::Calculate_Prime_Numbers::~Calculate_Prime_Numbers()
    {
        delete m_pCalcNext;
        delete m_pCalcFinished;
        delete m_pTerminateThread;
    }



	void _CEvent::Calculate_Prime_Numbers::run()
	{
		// Create a thread that will calculate the prime numbers
		CWinThread* pThread;
		pThread = ::AfxBeginThread(&PrimeCalcProc, this, 0, 0, CREATE_SUSPENDED, NULL);
		pThread->m_bAutoDelete = FALSE;
		pThread->ResumeThread();

		// Calcuate the first 10 prime numbers in the series on the thread
		for (UINT i = 0; i < 10; i++)
		{
			// Signal the thread to do the next work item
			m_pCalcNext->SetEvent();
			// Wait for the thread to complete the current task
			::WaitForSingleObject(m_pCalcFinished->m_hObject, INFINITE);
			// Print the result
			std::wostringstream oss;
			oss << "The value of m_iCurrentPrime is " << m_iCurrentPrime;
			m_text_output(oss.str());
		}

		// Notify the worker thread to exit and wait for it to complete
		m_pTerminateThread->SetEvent();
		::WaitForSingleObject(pThread->m_hThread, INFINITE);
		delete pThread;
	}



	BOOL _CEvent::Calculate_Prime_Numbers::IsPrime(INT ThisPrime)
    {
        if (ThisPrime < 2)
            return FALSE;

        for (INT n = 2; n < ThisPrime; n++)
            {
                if (ThisPrime % n == 0)
                    return FALSE;
            }
        return TRUE;
    }



    INT _CEvent::Calculate_Prime_Numbers::NextPrime(INT ThisPrime)
    {
        while (TRUE)
            {
                if (IsPrime(++ThisPrime))
                    {
                        return ThisPrime;
                    }
            }
    }



    UINT _CEvent::Calculate_Prime_Numbers::PrimeCalcProc(LPVOID lpParameter)
    {
        Calculate_Prime_Numbers* pThis = static_cast<Calculate_Prime_Numbers*>(lpParameter);
        VERIFY(pThis != NULL);
        VERIFY(pThis->m_pCalcNext != NULL);
        VERIFY(pThis->m_pCalcFinished != NULL);
        VERIFY(pThis->m_pTerminateThread != NULL);

        // Create a CMultiLock object to wait on the various events
        // WAIT_OBJECT_0 refers to the first event in the array, WAIT_OBJECT_0+1 refers to the second
        CSyncObject* pWaitObjects[] = { pThis->m_pCalcNext, pThis->m_pTerminateThread };
        CMultiLock MultiLock(pWaitObjects, 2L);
        while (MultiLock.Lock(INFINITE, FALSE) == WAIT_OBJECT_0)
            {
                // Calculate next prime
                pThis->m_iCurrentPrime = NextPrime(pThis->m_iCurrentPrime);
                // Notify main thread calculation is complete
                pThis->m_pCalcFinished->SetEvent();
            }

        // Terminate the thread
        ::AfxEndThread(0, FALSE);
        return 0L;
    }
}
