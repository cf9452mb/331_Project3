//------------------------------------------------------------------
// buffer.cpp
// Buffer class 
// Author: Justine Canlas
//------------------------------------------------------------------
// This header file includes the buffer class 
// It includes the data members needed for the 
//------------------------------------------------------------------

#include "buffer.h"

void BlockBuffer::setNumRecs(const int &val)
{
	this->numRecs = val;
}

void BlockBuffer::setBlockNumber(const int &val);
{
	this->blockNumber = val;
}

BlockBuffer::BlockBuffer(char del )
{
	delim = del; 
	bufferSize = 0; 
	nextCharIndex = 0;
}

int BlockBuffer::getNumRecs() const;
{
	return this->numRecs;
}

int BlockBuffer::getBlockNumber() const;
{
	return this->blockNumber;
}

int BlockBuffer::getSBlockNumber() const;
{
	return this->sBlockNumber;
}

int BlockBuffer::getPBlockBuffer() const;
{
	return this->pBlockBuffer;
}

bool BlockBuffer::read(istream& infile);

bool BlockBuffer::unpackField(string &aStr);

void BlockBuffer::clear()
{
	bufferSize = 0;
	blockNumber = 0;
	sBlockNumber = 0;
	pBlockNumber = 0;
	nextCharIndex = 0;
	buffer = "";
	numRecs = 0;
}
