//------------------------------------------------------------------
// buffer.h
// Buffer class 
// Author: Justine Canlas, Jordan Hebler
//------------------------------------------------------------------
// This header file includes a class called the BlockBuffer which
// includes functions that will set the number of records, set the
// block number, get the number of records, get the block number, 
// get the succeeded block number, get the preceeded block number, 
// clear the buffer, as well as read and unpack functions. 
//------------------------------------------------------------------

#ifndef BLOCK_BUFFER_H
#define BLOCK_BUFFER_H
#define UINT_MAX2   4294967295

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

/**
 * @file buffer.h
 * @brief This is the header file for the buffer class
 *
 * @author Justine Canlas, Jordan Hebler
 */

class BlockBuffer
{
  private:
  
  	/// Delimiter
  	char delim = ',';
	/// The buffer
	string buffer; 
	/// Size of the buffer string
	unsigned long bufferSize = 0; 
	/// Largest buffer size, default = size of string
	unsigned int maxByte = UINT_MAX2;
	/// Index of next char
	int nextCharIndex = 0;
	/// Number of records
	int numRecs = 0;
	/// Block number
	int blockNumber = 0;
	/// Succeeded block number
	int sBlockNumber = 0;
	/// Succeeded block number
	int pBlockNumber = 0;
	
	/// @brief Set the current block's size to a certain value
	/// @param This function takes an integer value called val as parameter. 
	/// @pre None
	/// @post This function sets the value of numRecs.
	/// @return None
	void setNumRecs(const int &val);
	
	/// @brief Set the current block's number to a certain value
	/// @param This function takes an integer value called val as a parameter. 
	/// @pre None
	/// @post This function sets the value of blockNumber.
	/// @return None
	void setBlockNumber(const int &val);
  
  public:
  
  	/// @brief default constructor
  	BlockBuffer(char del = ',');
  
  	/// @brief This gets the current block's size.
	/// @param None
	/// @pre None
	/// @post This function returns the blockSize.
	/// @return blockSize
  	int getNumRecs() const;
	
	/// @brief This gets the current block's number.
	/// @param None
	/// @pre None
	/// @post This function returns the blockNumber.
	/// @return blockNumber
	int getBlockNumber() const;
		
	/// @brief This gets the succeeded block's number.
	/// @param None
	/// @pre None
	/// @post This function returns the sBlockNumber.
	/// @return sBlockNumber
	int getSBlockNumber() const;
		
	/// @brief This gets the preceded block's number.
	/// @param None
	/// @pre None
	/// @post This function returns the pBlockNumber.
	/// @return pBlockNumber
	int getPBlockNumber() const;
  
  	/// @brief Read from the file stream block by block
	/// @param infile file stream is passed in
	/// @pre infile must be declared first in the program, the header must be eliminated.
	/// @post Read the data in infile to buffer
	/// @return Returns true if the stream is opened and the buffer is not overflow, false otherwise.
	bool read(istream& infile);
		
	/// @brief Get the next field from readed file stream
	/// @param A string& aStr
	/// @pre None
	/// @post Pass the next field in buffer to aStr
	/// @return Returns true if the next field is readed, false otherwise.
	bool unpackField(string &aStr);
	
	/// @brief Clear the buffer
	/// @param No parameters passed
	/// @pre None
	/// @post bufferSize and nextCharIndex are set to 0
	/// @return 
	void clear();
	
	/// @brief Increment the nextChar index
        void increment();
	
};

#include "buffer.cpp"
#endif
