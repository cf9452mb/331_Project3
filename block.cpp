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
#include "block.h"
//
// @file block.cpp
// @brief This is the implementation file for the class Block
//
// @author Myint Aung
//

//
//  accessor for block_count
//
// @param None
// @return This function returns the number of block counts.
// @pre None
// @post This function returns the number of block counts.
//
const int Block::getblockcount(){
    return block_count;
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
    block_count = bcount;
}
//
//  Mutator for the record count
//
// @param Integer This function takes an int value called rcount as parameter to set the value of record count.
// @return None
// @pre None
// @post This function sets the value of record count.
//
void Block::setrecordcount(int rcount)){
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
