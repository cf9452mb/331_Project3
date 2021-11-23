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

//Converting int to string
template<class dataType>
int BlockNode::str2int (const string &s) const
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
//  default constructor for block node
//
// @param None
// @return This function sets the default values of the data members of block node
// @pre None
// @post None
//
template<class dataType>
BlockNode::BlockNode()
{
	blockNumber = 0;
	numberOfRecords = 0;
	succeededBlock = 0;
	precededBlock = 0;
	datasize = 0;
}

//
//  accessor for Block Number
//
// @param None
// @return This function returns the block number
// @pre None
// @post This function returns the block number
//
template<class dataType>
int BlockNode::getBlockNumber()
{
	return blockNumber;
}

//
//  accessor for data size
//
// @param None
// @return This function returns the size of the data
// @pre None
// @post This function returns the size of the data
//
template<class dataType>
int BlockNode::getDataSize()
{
	return datasize;
}

//
//  accessor for number of records
//
// @param None
// @return This function returns the number of records
// @pre None
// @post This function returns the number of records
//
template<class dataType>
int BlockNode::getNumRecs()
{
	return numberOfRecords;
}

//
//  accessor for data
//
// @param None
// @return This function returns the data
// @pre None
// @post This function returns the data
//
template<class dataType>
dataType BlockNode::getData(const int num){
dataType datas;
if (num < data.size() && num>=0)
{
	datas = data[num];
}
return datas;
}

template<class dataType>
int BlockNode::getSBlockNumber() const;
{
	return succeededBlock;
}

template<class dataType>
int BlockNode::getPBlockNumber() const;
{
	return precededBlock;
}

template<class dataType>
void BlockNode::setSBlock(const int &val)
{
	succeededBlock = val;
}

template<class dataType> 
void BlockNode::setPBlock(const int &val)
{
	precededBlock = val;
}
