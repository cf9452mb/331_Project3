//------------------------------------------------------------------
// BlockNode.h
// BlockNode class 
// Author: Anuja Modi, Jordan Hebler, Myint Aung, Justine Canlas
//------------------------------------------------------------------
// This header file includes the block node class

#ifndef BLOCKNODE_H
#define BLOCKNODE_H

#include <string>
#include <vector>
#include <iostream>
using namespace std;

template<class dataType>
class BlockNode 
{
private:
	/// Vector stores data
	vector<dataType> data;
	/// Block number
	int blockNumber = 0;
	/// Number of records in this block
	int numberOfRecords = 0;
	/// Succeeded block
	int succeededBlock = 0;
	/// Preceded block
	int precededBlock = 0;
	///DataSize
	int datasize = 0;


public:
	/// @brief Default Constructor
	BlockNode();
	
	/// @brief Constructor
	BlockNode(const int &bNum, const int &sBlock, const int &pBlock);

	/// @brief string to int converter
	/// @return int value of the string s
	int str2int (const string &s) const;
	
	/// @brief Get block number
	/// @return Block number
	int getBlockNumber() const;
	
	/// @brief Get block's size
	/// @return An int of block size
	int getDataSize() const;
		
	/// @brief Get number of records
	/// @return An int of number of records
	int getNumRecs() const;
		
	/// @brief Get i-th data
	/// @return A record
	dataType getData(const int num) const;
	
	// @brief Add new data entry
	// @param anEntry An data entry
	//bool addData(const dataType &anEntry);	This will be used for adding to the block
		
	// @brief Remove a data entry by position
	// @param position The position need to be removed
	//bool removeData(const int &position);		This will be used for removing from the block

	/// @brief Get succeeded block
	/// @return A block
	int getSBlockNumber() const;
		
	/// @brief Get preceded block
	/// @return A block
	int getPBlockNumber() const;
		
	/// @brief Set succeeded block
	/// @param A block
	void setSBlock(const int &val);
		
	/// @brief Set preceded block
	/// @param A block
	void setPBlock(const int &val);
};

#endif
