#include "pch-MFC-Example-Snippets.hpp"
#include "Write.hpp"


IMPLEMENT_CRUNTIMECLASS_SUPPORT_DYNAMIC_CREATE(Examples::_CFile::Write)


namespace Examples {

	void _CFile::Write::run()
	{
		constexpr size_t data_size = 32;
		constexpr size_t data_buffer_size = data_size + 1;

		TEXT_OUT("Opening file for write access...");
		CFile cfile; cfile.Open(L"Write_File.dat", CFile::modeCreate | CFile::modeReadWrite);

		TEXT_OUT("Setting up sample buffer of data...");
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

		TEXT_OUT("Writing sample data to file...");
		cfile.Write(pbufWrite, data_size);

		TEXT_OUT("Flushing file...");
		cfile.Flush();

		TEXT_OUT("Seeking to the beginning of the file...");
		cfile.SeekToBegin();

		TEXT_OUT("Reading back in the file contents...");
		char pbufRead[data_buffer_size] = {};
		cfile.Read(pbufRead, data_size);

		TEXT_OUT("Comparing read-back with original...");
		ASSERT(0 == memcmp(pbufWrite, pbufRead, data_size));

		TEXT_OUT("Original data : " << pbufWrite);
		TEXT_OUT("Data read back: " << pbufRead);
	}


}

