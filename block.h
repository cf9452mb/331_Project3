//------------------------------------------------------------------
// block.h
// Block class 
// Author: Myint Aung
//------------------------------------------------------------------
// This header file includes the block class
// It includes the data members of the block class and the functions to read and write headers.
//------------------------------------------------------------------

#ifndef BLOCK_H
#define BLOCK_H
/**
 * @file block.h
 * @brief This is the header file for the block class
 *
 * @author Myint Aung
 */
 
 /**
 * @brief This class is used to create blocks using the functions from the block class
 * @details This Block class includes functions that will set the values of block count, record count, head block number,
 *			available list, sequence set file and index file.
 * @author Myint Aung
*/
class Block
{ 
private:
int blockCount, record_count, headblock_no, maxBlockSize, totalRec, availBlock; 
std::vector<int>avail_list;
std::string sequence_set, indexFile;

public:
/**
 *  Constructor
 *
 * @param String s
 * @return This function sets the string to the data member sequence_set
 * @pre None
 * @post This function sets the string to the data member sequence_set
*/
Block(string s);
/**
 *  accessor for block_count
 *
 * @param None
 * @return This function returns the number of block counts.
 * @pre None
 * @post This function returns the number of block counts.
*/
const int getblockcount();
/**
 *  accessor for record_count
 *
 * @param None
 * @return This function returns the number of record counts.
 * @pre None
 * @post This function returns the number of record counts.
*/
const int getrecordcount();
/**
 *  accessor for headblock_no
 *
 * @param None
 * @return This function returns the number of head blocks.
 * @pre None
 * @post This function returns the number of head blocks.
*/
const int getheadblock_no();
/**
 *  Mutator for the available list
 *
 * @param Integer This function takes an int value called list as parameter to set the value of avaialable list.
 * @return None
 * @pre None
 * @post This function sets the value of available list.
*/
void setavail_list(std::vector<int> list);
/**
 *  Mutator for the block count
 *
 * @param Integer This function takes an int value called bcount as parameter to set the value of block count.
 * @return None
 * @pre None
 * @post This function sets the value of block count.
 */
void setblockcount(int bcount);
/**
 *  Mutator for the record count
 *
 * @param Integer This function takes an int value called rcount as parameter to set the value of record count.
 * @return None
 * @pre None
 * @post This function sets the value of record count.
 */
void setrecordcount(int rcount);
/**
 *  Mutator for the head block number
 *
 * @param Integer This function takes an int value called hblock as parameter to set the value of head block number
 * @return None
 * @pre None
 * @post This function sets the value of head block number
 */
void setheadblock_no(int hblock);

/**
 *  accessor for index file
 *
 * @param None
 * @return This function returns the index file
 * @pre None
 * @post This function returns the index file
*/
 const std::string getindex();
 
 /**
 *  Mutator for the index file
 *
 * @param String This function takes a string value called index_file as parameter to set the value of the index file
 * @return None
 * @pre None
 * @post This function sets the value of index file
*/
void setindex(std::string index_file);

/**
 * Reads a record from the inputted file
 *
 * @param ifstream The file stream where the record is to be read from
 * @return 0 if no more records are to be read from file, 1 otherwise
 * @pre 
 * @post The size and contents of the buffer are read and set.
*/
int Read(std::istream& in_s);

/**
 * Writes the record to get the desired outputs
 *
 * @param ostream The file stream to be written too
 * @return This returns 1 on success
 * @pre None
 * @post The record is written to the file 
*/
int Write(std::ostream &out_s);

/**
* Function to convert string to integer
*/
int str2int (const string &s) const;

bool findRecord(const string &keyStr);
 
void sortRecords();
};
#endif

