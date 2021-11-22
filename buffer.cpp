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
  
void BlockBuffer::setBlockNumber(const int &val);

BlockBuffer::BlockBuffer(char del = ',');

int BlockBuffer::getNumRecs() const;

int BlockBuffer::getBlockNumber() const;

int BlockBuffer::getSBlockNumber() const;

int BlockBuffer::getPBlockBuffer() const;

bool BlockBuffer::read(istream& infile);

bool BlockBuffer::unpackField(string &aStr);

void BlockBuffer::clear();
