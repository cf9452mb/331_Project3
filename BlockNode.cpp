//-------------------------------------------------------------
// BlockNode.cpp
// This is the implementation file for the BlockNode.h
// Author: Anuja Modi, Jordan Hebler, Myint Aung, Justine Canlas
//-------------------------------------------------------------
// This .cpp file contains the functions of the class BlockNode
//
// This file makes use of the functions of the class BlockNode which
// will set and return the values of the data members of the class
//-------------------------------------------------------------
#include <string>
#include <vector>
#include <iostream>
using namespace std;
#include "BlockNode.h"

//
// @brief Default constructor for block node
//
// @param None
// @return This function sets the default values of the data members of block node
// @pre None
// @post None
//
template<class dataType>
BlockNode<dataType> ::BlockNode()
{
	blockNumber = 0;
	numberOfRecords = 0;
	succeededBlock = 0;
	precededBlock = 0;
	datasize = 0;
}

/// @brief Constructor
template<class dataType>
BlockNode<dataType> :: BlockNode(const int &bNum, const int &sBlock, const int &pBlock)
{
	blockNumber = bNum;
	setSBlock(sBlock);
	setPBlock(pBlock);
}

//Converting int to string
template<class dataType>
int BlockNode<dataType> ::str2int (const string &s) const
{
	int result = 0;
	for (int i = 0; i < s.length(); i++)
	{
		int num = s[i] - '0';
		result = result*10 + num;
	}
	return result;
}



//
// @brief Accessor for Block Number
//
// @param None
// @return This function returns the block number
// @pre None
// @post This function returns the block number
//
template<class dataType>
int BlockNode<dataType> ::getBlockNumber() const
{
	return blockNumber;
}

//
// @brief Accessor for data size
//
// @param None
// @return This function returns the size of the data
// @pre None
// @post This function returns the size of the data
//
template<class dataType>
int BlockNode<dataType> ::getDataSize() const
{
	return datasize;
}

//
// @brief Accessor for number of records
//
// @param None
// @return This function returns the number of records
// @pre None
// @post This function returns the number of records
//
template<class dataType>
int BlockNode<dataType> ::getNumRecs() const
{
	return numberOfRecords;
}

//
// @brief Accessor for data
//
// @param None
// @return This function returns the data
// @pre None
// @post This function returns the data
//
template<class dataType>
dataType BlockNode<dataType> ::getData(const int num) const{
	dataType datas;
	if (num < data.size() && num>=0)
	{
		datas = data[num];
	}
	return datas;
}

//
// @brief Accessor for the succeded block
//
// @param None
// @return This function returns the succeededBlock
// @pre None
// @post This function returns the succeded block
//
template<class dataType>
int BlockNode<dataType> ::getSBlockNumber() const
{
	return succeededBlock;
}

//
// @brief Accessor for the preceded block
//
// @param None
// @return This function returns the precededBlock
// @pre None
// @post This function returns the preceded block
template<class dataType>
int BlockNode<dataType> ::getPBlockNumber() const
{
	return precededBlock;
}

//
// @brief Setter for the succeeded block
//
// @param None
// @return This function sets the val of the succeededBlock
// @pre None
// @post This function sets the value of the succeeded block
template<class dataType>
void BlockNode<dataType> ::setSBlock(const int &val)
{
	succeededBlock = val;
}

//
// @brief Setter for the preceded block
//
// @param None
// @return This function sets the val of the precededBlock
// @pre None
// @post This function sets the value of the preceded block
template<class dataType> 
void BlockNode<dataType> ::setPBlock(const int &val)
{
	precededBlock = val;
}

/// @brief Add new data entry
template<class dataType>
bool BlockNode<dataType> :: addData(const dataType &anEntry)
{
	int position;
	dataType curEntry;
	string key = anEntry.getKey();
	for (position = 0; position < data.size(); position++)
	{
		curEntry = data[position];
		string curKey = curEntry.getKey();
		if(str2int(curKey) > str2int(key)) break;
	}
	auto itPos = data.begin() + position;
	auto newIt = data.insert(itPos, anEntry);
	
	numberOfRecords = data.size();
	return true;
}
