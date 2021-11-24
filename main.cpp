//--------------------------------------------------
// main.cpp
//--------------------------------------------------

#include "Block.h"
#include "BlockNode.h"
#include "Location.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main(int argc, const char* argv[])
{
	//get arguments
	string fileName = argv[1];
	Block<Location> aBlock(fileName);
	//BlockNode<Location> aNode = aBlock.readBlock(1);
	string command = argv[2];
	
	//commands
	if (command[0] == '-')
	{
		if(command[1] == 'z') 			aBlock.findRecord(argv[2]);
		else if (command[1] == 's')		aBlock.sortRecords();
		else
		{ 
			cout << "Invalid command..." << endl;
			return 0;
		}
	}
	else
	{ 
		cout << "Invalid command..." << endl;
		return 0;	
	}

	return 0;
}
