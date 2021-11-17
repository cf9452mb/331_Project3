//------------------------------------------------------------------
// block.h
// Block class 
// Author: Myint Aung
//------------------------------------------------------------------
// This header file includes the block class
// It includes the data members of the block class and the functios to read and write headers.
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
int block_count, record_count, headblock_no;
std::vector<int>avail_list;
std::string sequence_set, index_file;

public:
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
#endif

