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

This program utilizes polymorphism and exception handling
in order to develop a program that can read in information
from files into objects and handle exceptional situations.


*******************************************************
*  Source files
*******************************************************

Name:  main.cpp
   Main program. This is the driver program that calls sub-functions
   to read data from the user, use the data to create three grids,
   and display various grids with 1’s and 0’s in their cells.

Name:  Animal.h
   Contains the definition for the class Animal.  

Name: Animal.cpp
   Defines and implements the Animal class and derived classes.  
   This class provides routines to read in information from various files
   which then are read into member variables of the classes.
   The classes then perform exception handling on the information.

   
   
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
       % unzip LieHW4.zip

   Now you should see a directory named LieHW4 with the files:
        main.cpp
        Animal.cpp
	Animal.h
        makefile
        Readme.txt
	Dog.csv
	Fish.csv
	Horse.csv
	Lizard.csv
	Monkey.csv

2. Build the program.

    Change to the directory that contains the file by:
    % cd LieHW4

    Compile the program by:
    % make

3. Run the program by:
   % ./hw4

4. Delete the obj files, executables, and core dump by
   %./make clean
