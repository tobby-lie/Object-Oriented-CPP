*******************************************************
*  Name      :  Tobby Lie        
*  Student ID:  103385744               
*  Class     :  CSCI 2312           
*  HW#       :  3                
*  Due Date  :  September 18, 2017
*******************************************************


                 Read Me


*******************************************************
*  Description of the program
*******************************************************

The program “WaterVehicle utilizes classes and inheritance
in order to develop a program Battleship program


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
   grid. This will “have a” submarine object.
   

Name: WaterVehicle.h
   Contains the definition for the WaterVehicle and Submarine
   classes

Name: WaterVehicle.cpp
   Defines and implements the WaterVehicle and Submarine classes.
   Provides routines to store information about a ship or 
   submarine that are variables mainly based off of int and boolean
   variables.

   
   
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
       % unzip LieHW3.zip

   Now you should see a directory named homework with the files:
        main.cpp
        Grid.cpp
	Grid.h
	WaterVehicle.cpp
	WaterVehicle.h
        makefile
        Readme.txt

2. Build the program.

    Change to the directory that contains the file by:
    % cd LieHW3 

    Compile the program by:
    % make

3. Run the program by:
   % ./hw3

4. Delete the obj files, executables, and core dump by
   %./make clean
