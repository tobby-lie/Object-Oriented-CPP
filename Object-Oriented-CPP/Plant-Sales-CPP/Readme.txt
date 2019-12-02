*******************************************************
*  Name      :  Tobby Lie       
*  Student ID:  103385744              
*  Class     :  CSCI 2312           
*  HW#       :  1                
*  Due Date  :  Aug. 22, 2017
*******************************************************


                 Read Me


*******************************************************
*  Description of the program
*******************************************************

The program “plant sales“ receives input from a user, and uses
the data to calculate the estimated number of plants which
will be sold for temperature ranges. User input will be used
for number of available plants in the store. Will then output
number of plants sold in outdoor temperature ranges.


*******************************************************
*  Source files
*******************************************************

Name:  main.cpp
   Main program.  This is the driver program that calls sub-functions
   to read data from a user, use the data to compute and display
   plants sold at certain temperature ranges.

Name:  plantSales_functions.h
   Contains the prototypes for the plant sales program support functions.

Name: plantSales_functions.cpp
   Includes functions to ask for user input and to calculate number of 
   plants sold at certain temperature ranges.

   
*******************************************************
*  Circumstances of programs
*******************************************************

   The program runs successfully.  
   
   The program was developed and tested on xCode. It was 
   compiled, run, and tested on gcc 4.8 on csegrid.ucdenver.pvt.


*******************************************************
*  How to build and run the program
*******************************************************

1. Uncompress the homework.  The homework file is compressed.  
   To uncompress it use the following commands 
       % unzip LieHW1.zip

   Now you should see a directory named LieHW1 with the files:
        main.cpp
	plantSales_functions.h
	plantSales_functions.cpp
        makefile
        Readme.txt

2. Build the program.

    Change to the directory that contains the file by:
    % cd LieHW1 

    Compile the program by:
    % make

3. Run the program by:
   % ./hw1

4. Delete the obj files, executables, and core dump by
   %./make clean
