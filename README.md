# 331_Project3

1. Purpose
- The generator program helps convert the comma separated file to a block sequence set file to use in the main program
- The main program can be used to search for the information of a specific zip code given by the user
- The main program can also be used to get the 4 extreme latitude/longitude locations for each state
- The main program can be used to add or remove data from the blocked sequence set file
- The main program can be used to show the logical or physical ordering of the blocks

2. File location
- All necessary CSV, C++ files, header files, and .txt files are compressed and stored in Project 3 - Team 1 - files.zip.
- Compile the file generator.cpp to convert the .csv file.
- Compile the file main.cpp to run program.

3. Execution
- To compile the generator program, use g++ generator.cpp -std=c++11
	then execute the generator by: ./a.out *csv-file-name* *blocked-sequence-set-file-name* *max-block-size*
    (Ex. ./a.out us_postal_codes.csv block.txt 512      Creates a blocked sequence set file named block.txt that is created from the us_postal_codes.csv file with a max block size of 512 bytes. Running this program will also create a simple primary key index file which will be called simpleIndex.txt)
- To compile the main program, use: g++ main.cpp -std=c++11
- After successfully compiling the main program, you can use ./a.out followed by the blocked sequence set file and a flag to execute the program.
	* The file must be converted before by using generator.cpp
- Each flag indicates a different task:
	-s	: show a table of the 4 extreme latitude/longitude locations of each state.
        (Example shown below)
	-z00000	: find the information of a given zip code, replace 00000 by the desired zip code (no leading zero).
        (Example shown below)
	-a00000	additional-record-file: add data to the file. Here to simplify, records can be chosen from additiona-record-file
        to add. (Ex. If block.txt is the blocked sequence set file and toadd.txt is the additonal file of length-indicated records, then ./a.out block.txt -a1 toadd.txt    will add the record on the first line of toadd.txt)
	-d00000 : delete data from a file, replace 00000 by the zip code you want to delete (no leading zero). (Ex. If block.txt is the blocked sequence set file, then ./a.out block.txt -d56303    will delete the record with zip code 56303 if it exists)
    -l  : show the logical ordering of the blocks and RBN's of the head and avail block
        (Ex. ./a.out block.txt -l   will generate block.txt's logical dump)
    -p  : show the physical ordering of the blocks and RBN's of the head and avail block
        (Ex. ./a.out block.txt -p   will generate block.txt's physical dump)
    
- When adding or deleting, the change can be easily seen by running the logical dump (-l) and/or the physical dump (-p)

- The file storing the initial data is: us_postal_codes.csv
