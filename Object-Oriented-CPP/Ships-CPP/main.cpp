//Tobby Lie 103385744
//CSCI 2312
//Homework 3
//September 18, 2017
//This program utilizes inheritance and classes
//to implement a battleship game

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cctype>
#include "Grid.h"

using namespace std;

int main(){
    
    srand((int)time(NULL)); // seed rand

    Grid g1;
    char choice;
    do{
    g1.playGame();
    cout << "Would you like to play again? (Y/N)" << endl;
    cin >> choice;
    choice = toupper(choice);
        // validate input
        while(choice != 'Y' && choice != 'N'){
            cout << "Invalid input! Input Y to play again or N to exit program: " << endl;
            cin >> choice;
            choice = toupper(choice);
        }// end while
    }while(choice == 'y' || choice == 'Y'); // end do while
    
return 0;
}
