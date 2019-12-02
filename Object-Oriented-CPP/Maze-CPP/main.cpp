//Tobby Lie 103385744
//CSCI 2312
//Homework 5
//October 24, 2017
//Program utilizes graph in order
//to implement a maze

#include <iostream>
#include "Maze.h"

using namespace std;

int main(){

    char choice = ' ';
    do{
        if(choice == 'Y'){
            cout << "* Back so soon?... *" << endl;
        } // end if
        //originalMaze(); // commented out, this is the old function that I kept the code for just in case but is ineffective and so I decided not to use this code for program
        improvedMaze(); // play game with new and improved code
        cout << "Would you like to play again? (Y/N)" << endl;
        cin >> choice;
        choice = toupper(choice);
        while((choice != 'N' && choice != 'Y') || cin.fail()){
            cout << "Invalid input! Must input Y for yes or N for no." << endl;
            cin.clear();
            cin.ignore();
            cin >> choice;
            choice = toupper(choice);
        } // end while
    } // end do
    while(choice != 'N'); // end do while
    
return 0;
}
