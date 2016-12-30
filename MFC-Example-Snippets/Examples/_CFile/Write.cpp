#include "pch-MFC-Example-Snippets.hpp"
#include "Write.hpp"
namespace Examples {

	void _CFile::Write::run()
	{
		constexpr size_t data_size = 32;
		constexpr size_t data_buffer_size = data_size + 1;

		m_text_output(L"Opening file for write access...");
		CFile cfile; cfile.Open(L"Write_File.dat", CFile::modeCreate | CFile::modeReadWrite);

		m_text_output(L"Setting up sample buffer of data...");
		char pbufWrite[data_buffer_size] = {};
		char * pBufferWalk = pbufWrite;
		const size_t data_chunk_size = data_size / 8;
		memset(pBufferWalk, 'a', data_chunk_size); pBufferWalk += data_chunk_size;
		memset(pBufferWalk, 'b', data_chunk_size); pBufferWalk += data_chunk_size;
		memset(pBufferWalk, 'c', data_chunk_size); pBufferWalk += data_chunk_size;
		memset(pBufferWalk, 'd', data_chunk_size); pBufferWalk += data_chunk_size;
		memset(pBufferWalk, 'e', data_chunk_size); pBufferWalk += data_chunk_size;
		memset(pBufferWalk, 'f', data_chunk_size); pBufferWalk += data_chunk_size;
		memset(pBufferWalk, 'g', data_chunk_size); pBufferWalk += data_chunk_size;
		memset(pBufferWalk, 'h', data_chunk_size); pBufferWalk += data_chunk_size;

		m_text_output(L"Writing sample data to file...");
		cfile.Write(pbufWrite, data_size);

		m_text_output(L"Flushing file...");
		cfile.Flush();

		m_text_output(L"Seeking to the beginning of the file...");
		cfile.SeekToBegin();

		m_text_output(L"Reading back in the file contents...");
		char pbufRead[data_buffer_size] = {};
		cfile.Read(pbufRead, data_size);

		m_text_output(L"Comparing read-back with original...");
		ASSERT(0 == memcmp(pbufWrite, pbufRead, data_size));

		std::wostringstream oss1;
		oss1 << "Original data : " << pbufWrite;
		m_text_output(oss1.str());

		std::wostringstream oss2;
		oss2 << "Data read back: " << pbufRead;
		m_text_output(oss2.str());
	}


}

