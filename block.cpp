//-------------------------------------------------------------
// block.cpp
// This is the implementation file for the block.h
// Author: Myint Aung, Jordan Hebler
//-------------------------------------------------------------
// This .cpp file contains the functions of the class Block
//
// This file makes use of the functions of the class Block which
// includes functions that will set the values of set the values of block count, record count, head block number,
//			available list, sequence set file and index file as well as functions to get those values after they are set.
//-------------------------------------------------------------

#include "block.h"

//
// @file block.cpp
// @brief This is the implementation file for the class Block
//
// @author Myint Aung
//

//Constructor
template<class dataType>
Block<dataType> ::Block(string s)
{
	sequence_set = s;
}
//converting string to integer
template<class dataType>
int Block<dataType> ::str2int (const string &s) const
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
template<class dataType>
const int Block<dataType> ::getblockcount(){
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
template<class dataType>
const int Block<dataType> ::getrecordcount(){
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
template<class dataType>
const int Block<dataType> ::getheadblock_no(){
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
template<class dataType>
void Block<dataType> ::setavail_list(std::vector<int> list){
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
template<class dataType>
void Block<dataType> ::setblockcount(int bcount){
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
template<class dataType>
void Block<dataType> ::setrecordcount(int rcount){
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
template<class dataType>
void Block<dataType> ::setheadblock_no(int hblock){
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
template<class dataType>
const std::string Block<dataType> ::getindex(){
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
template<class dataType>
void Block<dataType> ::setindex(std::string Indexfile){
    indexFile = Indexfile;
}
/**
 * Reads a record from the inputted file
 *
 * @param ifstream The file stream where the record is to be read from
 * @return 0 if no more records are to be read from file, 1 otherwise
 * @pre 
 * @post The size and contents of the buffer are read and set.
*/
template<class dataType>
int Block<dataType> ::Readheader(std::istream& in_s){
	for (int i = 0; i < 17; i ++){
		std::string line;
		getline(in_s, line);
		if (i == 5)
		{maxBlockSize = str2int(line);}
	if (i == 7)
		{indexFile = line;}
	if (i == 9)
		{totalRec = str2int(line);}
	if (i == 10)
		{blockCount = str2int(line);}
	if (i == 15)
	{headblock_no = str2int(line);}
	}
	return 0;
}
//
// Writes the record to get the desired outputs
//
// @param ostream The file stream to be written too
// @return This returns 1 on success
// @pre None
// @post The record is written to the file 
template<class dataType>
int Block<dataType> ::Writeheader(std::ostream &out_s){
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

// @brief Read block at a position
// @param The block need to be read position
template<class dataType>
BlockNode<dataType> Block<dataType> ::readBlock(const int &pos){
	ifstream readb;
	readb.open(sequence_set);
	    if(readb.fail()){
        cout << "Failed to open Data file! Exiting program" << endl;
        exit(1);
    }
	Readheader(readb);
	BlockBuffer buffer;
	int curblock = 1;
	while ( curblock <= blockCount)
	{
		buffer.read(readb);
		if (buffer.getBlockNumber() == curblock)
		{break;}
		curblock++;
	}
	BlockNode<dataType> thisBlock(buffer.getBlockNumber(), buffer.getSBlockNumber(), buffer.getPBlockNumber());
	for(int i = 0; i < buffer.getNumRecs(); i++)
	{
		dataType newEntry;
		newEntry.unpack(buffer);
		thisBlock.addData(newEntry);
	}
	return thisBlock;
}

/// @brief Find desired block based on key passed in
template<class dataType>
int Block<dataType> :: findDesiredBlock(const string &key)
{
	//open file
	ifstream file;
	file.open(indexFile);
	
	//get the desired block
	int desiredBlock = -1, i;
	string oldline, zip = "", blockStr = "";
	while (!file.eof())
	{
		string line;
		getline(file, line);
		if (line.length() == 0) continue;
		zip = ""; blockStr = "";
		for (i = 0; i < line.length(); i++)
		{
			if (line[i] == ',') break;
			else zip += line[i];
		}
		if (str2int(zip) >= str2int(key))
		{
			i++;
            for ( ; i < line.length(); i++) {
                blockStr += line[i];
            }
			desiredBlock = str2int(blockStr);
			return desiredBlock;
		}
		oldline = line;
	}
	
	for (i = 0; i < oldline.length(); i++)
	{
		if (oldline[i] == ',') break;
		else zip += oldline[i];
	}
	i++;
	for ( ; i < oldline.length(); i++) blockStr += oldline[i];
	desiredBlock = str2int(blockStr);
	return desiredBlock;
	
	//close and return
	file.close();
	return desiredBlock;
}
		
/// @brief Find records
template<class dataType>
bool Block<dataType> :: findRecord(const string &keyStr)
{
	//get the key zip code
	int key = 0;
	string keyS = "";
    	for (int i = 2; i < keyStr.length(); i++){
        	int num = keyStr[i] - '0';
        	key = key * 10 + num;
        	keyS += keyStr[i];
    	}
	
	//check if the record is found or not
	int pos = findDesiredBlock(keyS);
    
	if(pos < 0) 
		{cout << "Zip Code " << key << " is not found..." << endl; return false;}
	
	//target = desired output
	BlockNode<dataType> posBlock = readBlock(pos);
	dataType target;
	int i;
	for (i = 0; i < posBlock.getNumRecs(); i++)
	{
		target = posBlock.getData(i);
		if(target.getKey() == keyS) break;
	}
	
	//print result if found
	if (i == posBlock.getNumRecs())
		{cout << "Zip Code " << key << " is not found..." << endl; return false;}
	else
	{
		cout << "+---------------------------------------------------------------------------------------+" << endl
			 << '|' << setw(7) << "Zipcode"
			 << '|' << setw(5) << "State"
			 << '|' << setw(20) << "County"
			 << '|' << setw(30) << "Name"
			 << '|' << setw(10) << "Latitude"
			 << '|' << setw(10) << "Longitude"
			 << '|' << endl
			 << "+---------------------------------------------------------------------------------------+" << endl
			 << '|' << setw(7) << target.getZipCode()
			 << '|' << setw(5) << target.getState()
			 << '|' << setw(20) << target.getCounty()
			 << '|' << setw(30) << target.getPlace()
			 << '|' << setw(10) << target.getLat()
			 << '|' << setw(10) << target.getLong()
			 << '|' << endl
			 << "+---------------------------------------------------------------------------------------+" << endl;
		return true;
	}
}

template<class dataType>
void Block<dataType> ::sortRecords(){
	
	
	
	
	
}
