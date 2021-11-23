
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

BlockNode::BlockNode()
{
	blockNumber = 0;
	numberOfRecords = 0;
	succeededBlock = 0;
	precededBlock = 0;
	datasize = 0;
}

int BlockNode::getBlockNumber()
{
	return blockNumber;
}

int BlockNode::getDataSize()
{
	return datasize;
}

int BlockNode::getNumRecs()
{
	return numberOfRecords;
}

dataType BlockNode::getData(const int num){
dataType datas;
if (num < data.size() && num>=0)
{
	datas = data[num];
}
return datas;
}
