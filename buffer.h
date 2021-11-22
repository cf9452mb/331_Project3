//------------------------------------------------------------------
// buffer.h
// Buffer class 
// Author: Justine Canlas
//------------------------------------------------------------------
// This header file includes the buffer class 
// It includes the data members needed for the 
//------------------------------------------------------------------

#ifndef BUFFER.H
#define BUFFER.H
/**
 * @file buffer.h
 * @brief This is the header file for the buffer class
 *
 * @author Justine Canlas
 * 
 */

#include <string>
#include <vector>
#include <iostream>
using namespace std;

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
	void setNumRecs(const int &val);
	/// @brief Set the current block's number to a certain value
	void setBlockNumber(const int &val);
  
  public:
  
  /**
   * Default Constructor
   */
  BlockBuffer();
  
  /**
  *
  * @param
  * @return
  * @pre
  * @post
  */
  int NumberofRecords
  
  /**
  *
  * @param
  * @return
  * @pre
  * @post
  */
  const int getNumRecs();
  
  /**
  *
  * @param
  * @return
  * @pre
  * @post
  */
  int Read(
  
  /**
  *
  * @param
  * @return
  * @pre
  * @post
  */
  int Unpack
