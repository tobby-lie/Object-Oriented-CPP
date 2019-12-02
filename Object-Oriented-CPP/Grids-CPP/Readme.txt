*******************************************************
*  Name      :  Tobby Lie        
*  Student ID:  103385744               
*  Class     :  CSCI 2312           
*  HW#       :  2                
*  Due Date  :  September 12, 2017
*******************************************************


                 Read Me


*******************************************************
*  Description of the program
*******************************************************

The program “Grid” takes two user inputs representing
the width and length of a grid. Two grids are then created
from the dimensions and 1/3 of their cells are populated
with 1’s. Using this information, a third grid is created
in which cells from the first two grids are compared, if
the two cells both have 1’s in them then the third grids
cell at that position will have a 1 as well. Finally, the
final grid is printed to the screen.


*******************************************************
*  Source files
*******************************************************

Name:  main.cpp
   Main program. This is the driver program that calls sub-functions
   to read data from the user, use the data to create three grids,
   and display various grids with 1’s and 0’s in their cells.

Name:  Grid.h
   Contains the definition for the class Grid.  

Name: Grid.cpp
   Defines and implements the Grid class for implementing a Grid.  
   This class provides routines to construct and get a grid and
   it’s dimensions. As well as compare individual cells in the
   grid.
   

Name: functions.h
   Contains the function for the Grid program. Only utilized a
   .h for this as there is only one function for this program
   that being an input validation function.

   
   
*******************************************************
*  Circumstances of programs
*******************************************************

   The program runs successfully.  
   
   The program was developed and tested on Xcode.  It was 
   compiled, run, and tested on gcc 4.8 on csegrid.ucdenver.pvt.


*******************************************************
*  How to build and run the program
*******************************************************

1. Uncompress the homework.  The homework file is compressed.  
   To uncompress it use the following commands 
       % unzip LieHW2.zip

   Now you should see a directory named homework with the files:
        main.cpp
        Grid.cpp
	Grid.h
	functions.h
        makefile
        Readme.txt

2. Build the program.

    Change to the directory that contains the file by:
    % cd LieHW2 

    Compile the program by:
    % make

3. Run the program by:
   % ./hw2

4. Delete the obj files, executables, and core dump by
   %./make clean
