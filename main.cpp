//--------------------------------------------------
// main.cpp
//--------------------------------------------------

#include <iostream>
#include <cstdlib>

int main(int argc, const char* argv[])
{
	if(argc < 2)
	{
		cerr << "Invalid number of arguements!" << endl;
		exit(1);
	}
	
	while ((argc > 2) && (argv[2][0] == '-'))
	{
		switch (argv [2] [1])
		{
			case 'Z':
				number = atoi(&argv[2][2]);
				zipcodes.push_back(number);
				break;
				
			default:
				cerr << "invalid arguement: " << argv[2] << "\n";
		}
		
	++argv;
	--argc;
	}

	return 0;
}
