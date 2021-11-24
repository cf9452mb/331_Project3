//------------------------------------------------------------------
// buffer.cpp
// Buffer class 
// Author: Justine Canlas, Jordan Hebler
//------------------------------------------------------------------
// This header file includes a class called the BlockBuffer which
// includes functions that will set the number of records, set the
// block number, get the number of records, get the block number, 
// get the succeeded block number, get the preceeded block number, 
// clear the buffer, as well as read and unpack functions. 
//------------------------------------------------------------------

#include "buffer.h"

// @brief Set the current block's size to a certain value
// @param This function takes an integer value called val as parameter. 
// @pre None
// @post This function sets the value of numRecs.
// @return None
void BlockBuffer::setNumRecs(const int &val)
{
	this->numRecs = val;
}

// @brief Set the current block's number to a certain value
// @param This function takes an integer value called val as a parameter. 
// @pre None
// @post This function sets the value of blockNumber.
// @return None
void BlockBuffer::setBlockNumber(const int &val)
{
	this->blockNumber = val;
}

// @brief default constructor
BlockBuffer::BlockBuffer(char del )
{
	delim = del; 
	bufferSize = 0; 
	nextCharIndex = 0;
}

// @brief This gets the current block's size.
// @param None
// @pre None
// @post This function returns the blockSize.
// @return blockSize
int BlockBuffer::getNumRecs() const
{
	return this->numRecs;
}

// @brief This gets the current block's number.
// @param None
// @pre None
// @post This function returns the blockNumber.
// @return blockNumber
int BlockBuffer::getBlockNumber() const
{
	return this->blockNumber;
}

// @brief This gets the succeeded block's number.
// @param None
// @pre None
// @post This function returns the sBlockNumber.
// @return sBlockNumber
int BlockBuffer::getSBlockNumber() const
{
	return this->sBlockNumber;
}

// @brief This gets the preceded block's number.
// @param None
// @pre None
// @post This function returns the pBlockNumber.
// @return pBlockNumber
int BlockBuffer::getPBlockNumber() const
{
	return this->pBlockBuffer;
}

// @brief Clear the buffer
// @param No parameters passed
// @pre None
// @post bufferSize and nextCharIndex are set to 0
// @return 
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

// @brief Read from the file stream block by block
// @param infile file stream is passed in
// @pre infile must be declared first in the program, the header must be eliminated.
// @post Read the data in infile to buffer
// @return Returns true if the stream is opened and the buffer is not overflow, false otherwise.
bool BlockBuffer::read(istream& infile)
{
	// clear buffer
	clear();
	
	if(infile.eof()) return false;
	
	// read block size
	string line;
	getline(infile,line);
	
	int dataCount = 1;
	for (int i = 1; i < line.length(); i++)
	{
		if (line[i] == ',') {dataCount++; continue;}
		if (dataCount == 1)
		{
			int num = line[i] - '0';
			blockNumber = blockNumber * 10 + num;
		}
		else if (dataCount == 2)
		{
			int num = line[i] - '0';
			numRecs = numRecs * 10 + num;
		}
		else if (dataCount == 3)
		{
			int num = line[i] - '0';
			pBlockNumber = pBlockNumber * 10 + num;
		}
		else if (dataCount == 4)
		{
			int num = line[i] - '0';
			sBlockNumber = sBlockNumber * 10 + num;
		}
		else
		{
			break;
		}
	}
	
	// get data in the block to buffer
	for (int i = 0; i < numRecs; i++)
	{
		getline(infile,line);
		bufferSize += line.length();
		buffer += line + '\n';
		if (bufferSize > maxByte)
			{cout << "Buffer overloaded" << endl; return false;}
	}
	bufferSize = buffer.length();
	return true;
}


// @brief Get the next field from readed file stream
// @param A string& aStr
// @pre None
// @post Pass the next field in buffer to aStr
// @return Returns true if the next field is readed, false otherwise.
bool BlockBuffer::unpackField(string &aStr)
{
	aStr = ""; //clear aStr
	if (nextCharIndex > bufferSize) return false;
	
	int len = -1; // length of unpacking string
	int start = nextCharIndex; // first character to be unpacked
	
	// look for delimiter
	for (int i = start; i < bufferSize; i++)
	{
    
        	if (buffer[i] == delim || buffer[i] == '\n'){
            		len = i - start;
            		break;
        	}
	}
	
	// delimeter not found
	// last item
	if (len == -1)
	{
		aStr = buffer.substr(nextCharIndex, bufferSize - nextCharIndex);
		return false;
	}
	
	// retrieve the field
	nextCharIndex += len + 1;
	aStr = buffer.substr(start, len);
	return true;
}

/// @brief Increments the index so the Length is not included in the Zip Code
void DelimBuffer :: increment()
{
    nextCharIndex += 2;
}
