
#include <string>
#include <vector>
#include <iostream>
using namespace std;
#include "BlockNode.h"

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


template<class dataType>
BlockNode::BlockNode()
{
	blockNumber = 0;
	numberOfRecords = 0;
	succeededBlock = 0;
	precededBlock = 0;
	datasize = 0;
}


template<class dataType>
int BlockNode::getBlockNumber()
{
	return blockNumber;
}


template<class dataType>
int BlockNode::getDataSize()
{
	return datasize;
}


template<class dataType>
int BlockNode::getNumRecs()
{
	return numberOfRecords;
}


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
