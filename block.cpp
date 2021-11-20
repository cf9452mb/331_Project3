//-------------------------------------------------------------
// block.cpp
// This is the implementation file for the block.h
// Author: Myint Aung
//-------------------------------------------------------------
// This .cpp file contains the functions of the class Block
//
// This file makes use of the functions of the class Block which
// includes functions that will set the values of set the values of block count, record count, head block number,
//			available list, sequence set file and index file as well as functions to get those values after they are set.
//-------------------------------------------------------------
#include <string>
#include <vector>
#include <fstream>
#include <stdio.h>
#include <sstream>
#include "block.h"
//
// @file block.cpp
// @brief This is the implementation file for the class Block
//
// @author Myint Aung
//

//converting string to integer
int Block :: str2int (const string &s) const
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
//  accessor for block_count
//
// @param None
// @return This function returns the number of block counts.
// @pre None
// @post This function returns the number of block counts.
//
const int Block::getblockcount(){
    return blockCount;
}
//
//  accessor for record_count
//
// @param None
// @return This function returns the number of record counts.
// @pre None
// @post This function returns the number of record counts.
//
const int Block::getrecordcount(){
    return record_count;
}
//
//  accessor for headblock_no
//
// @param None
// @return This function returns the number of head blocks.
// @pre None
// @post This function returns the number of head blocks.
//
const int Block::getheadblock_no(){
    return headblock_no;
}
//
//  Mutator for the available list
//
// @param Integer This function takes an int value called list as parameter to set the value of avaialable list.
// @return None
// @pre None
// @post This function sets the value of available list.
//
void Block::setavail_list(std::vector<int> list){
    avail_list = list;
}
//
//  Mutator for the block count
//
// @param Integer This function takes an int value called bcount as parameter to set the value of block count.
// @return None
// @pre None
// @post This function sets the value of block count.
//
void Block::setblockcount(int bcount){
    blockCount = bcount;
}
//
//  Mutator for the record count
//
// @param Integer This function takes an int value called rcount as parameter to set the value of record count.
// @return None
// @pre None
// @post This function sets the value of record count.
//
void Block::setrecordcount(int rcount){
    record_count = rcount;
}
//
//  Mutator for the head block number
//
// @param Integer This function takes an int value called hblock as parameter to set the value of head block number
// @return None
// @pre None
// @post This function sets the value of head block number
//
void Block::setheadblock_no(int hblock){
    headblock_no = hblock;
}

//
//  accessor for index file
//
// @param None
// @return This function returns the index file
// @pre None
// @post This function returns the index file
//
const std::string Block::getindex(){
    return indexFile;
}

//
//  Mutator for the index file
//
// @param String This function takes a string value called index_file as parameter to set the value of the index file
// @return None
// @pre None
// @post This function sets the value of index file
//
void Block::setindex(std::string Indexfile){
    indexFile = Indexfile;
}

int Block::Read(std::istream& in_s){
	for (int i = 0; i < 17, i ++;){
		std::string line;
		getline(in_s, line);
		if (i = 5)
		{maxBlockSize = str2int(line);}
	if (i = 7)
		{indexFile = line;}
	if (i = 9)
		{totalRec = str2int(line);}
	if (i = 10)
		{blockCount = str2int(line);}
	if (i = 15)
	{headblock_no = str2int(line);}
	}
	return 0;
}

int Block::Write(std::ostream &out_s){
		out_s << "blocked sequence set with comma separated fields, length-indicated records" << endl
		 << "1" << endl
		 << "1024" << endl
		 << "512" << endl
		 << "ASCII" << endl
		 << maxBlockSize << endl
		 << "50" << endl
		 << indexFile << endl
		 << "primaryIndex,blockNumber" << endl
		 << totalRec << endl
		 << blockCount << endl
		 << '6' << endl
		 << "Zip Code,Place,State,County,Lat,Long" << endl
		 << "Zip Code" << endl
		 << avail_list[0];
		 for (int i = 1; i < avail_list; i++)
		 {
			out_s << ' ' << avail_list[i];
		 }
		 out_s << endl
		 << headblock_no << endl
		 << '1' << endl;
	return 1;
}
