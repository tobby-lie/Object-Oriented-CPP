*******************************************************
*  Name      :  Tobby Lie       
*  Student ID:  103385744              
*  Class     :  CSCI 2312           
*  HW#       :  5                
*  Due Date  :  Oct. 24, 2017
*******************************************************


                 Read Me


*******************************************************
*  Description of the program
*******************************************************

The program “Maze” will utilize a graph data structure
to implement a game where a user must traverse a graph
that represents a maze. The winner starts at node A and
wins once they have made it to node L.


*******************************************************
*  Source files
*******************************************************

Name:  main.cpp
   Main program.  This is the driver program that calls sub-functions
   to read data from a user, use the data to compute and display
   plants sold at certain temperature ranges.

Name:  Maze.h
   Contains the prototypes and implementation for maze functions

   
*******************************************************
*  Circumstances of programs
*******************************************************

   The program runs successfully.  
   
   The program was developed and tested on Xcode. It was 
   compiled, run, and tested on gcc 4.8 on csegrid.ucdenver.pvt.


*******************************************************
*  How to build and run the program
*******************************************************

1. Uncompress the homework.  The homework file is compressed.  
   To uncompress it use the following commands 
       % unzip LieHW5.zip

   Now you should see a directory named LieHW5 with the files:
        main.cpp
	Maze.h
        makefile
        Readme.txt

2. Build the program.

    Change to the directory that contains the file by:
    % cd LieHW5

    Compile the program by:
    % make

3. Run the program by:
   % ./hw5

4. Delete the obj files, executables, and core dump by
   %./make clean
