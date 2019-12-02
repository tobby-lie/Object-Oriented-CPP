//Tobby Lie
//CSCI 2312
//Homework 3
//September 18, 2017
//Grid class implementation

#include <iostream>
#include <iomanip>
#include "Grid.h"

using namespace std;

/*********************************************************************
 ** FUNCTION: clearGrid
 ** DESCRIPTION: clears board and elements of values
 ** PARAMETERS: none
 ** PRE-CONDITIONS: none
 ** POST-CONDITIONS: board and submarine cleared
 ** RETURNS: nothing
 *********************************************************************/
void Grid::clearGrid(){
    for(int i = 0; i < ROWS; i++){
        for(int j = 0; j < COLS;j++){
            board[i][j] = ' ';
        }// end for
    }// end for
    w.setLength(0);
    w.setLocation_x(0);
    w.setLocation_y(0);
    w.setSunkStatus(false);
    w.setHitStatus(false);
    w.setOrientation(false);
    w.setDepth(0);
    w.setSurfaced(false);
} // end clearGrid
/*********************************************************************
 ** FUNCTION: printGrid
 ** DESCRIPTION: print grid and all values in it
 ** PARAMETERS: none
 ** PRE-CONDITIONS: none
 ** POST-CONDITIONS: none
 ** RETURNS: nothing
 *********************************************************************/
void Grid::printGrid(){
    cout << setw(2) << left << "  |1 |2 |3 |4 |5 |6 |7 |8 |9 |10|" << endl;;
    for(int i = 0; i < ROWS; i++){
        cout << "---------------------------------" << endl;
        cout << setw(2) << left << i + 1 << "|";
        for(int j = 0; j < COLS; j++){
            cout << setw(2) << left << board[i][j] << "|";
        }// end for
        cout << endl;
    }// end for
}// end printGrid
/*********************************************************************
 ** FUNCTION: orientationInput
 ** DESCRIPTION: get input for orientation from user
 ** PARAMETERS: none
 ** PRE-CONDITIONS: none
 ** POST-CONDITIONS: orientation updated
 ** RETURNS: nothing
 *********************************************************************/
void Grid::orientationInput(){
    int choice;
    cout << "Please specify the orientation of the submarine" << endl;
    cout << "Inputting a 0 means an orientation of horizontal." << endl;
    cout << "Inputing a 1 means an orientation of vertical." << endl;
    cout << "Please input 0 or 1: " << endl;
    cin >> choice;

    while((choice != 0 && choice != 1) || cin.fail()){
        cout << "Invalid input! Please input 0 for horizontal or 1 for vertical: " << endl;
        cin.clear();
        cin.ignore();
        cin >> choice;
    }// end while
    w.setOrientation(choice); // orientation
} // end orientationInput
/*********************************************************************
 ** FUNCTION: lengthInput
 ** DESCRIPTION: get input for length form user
 ** PARAMETERS: none
 ** PRE-CONDITIONS: none
 ** POST-CONDITIONS: length updated
 ** RETURNS: nothing
 *********************************************************************/
void Grid::lengthInput(){
    int _length;
    cout << "What is the length of this submarine?" << endl;
    cout << "Input a number between 1 - 10: " << endl;
    cin >> _length;
    // must be within 10
    while(_length < 1 || _length > 10 || cin.fail()){
        cout << "Invalid input! Length must be between 1 - 10." << endl;
        cout << "Please input another length: " << endl;
        cin.clear();
        cin.ignore();
        cin >> _length;
    }// end while
    w.setLength(_length); // length
} // end lengthInput
/*********************************************************************
 ** FUNCTION: locationInput
 ** DESCRIPTION: get input for location from user
 ** PARAMETERS: none
 ** PRE-CONDITIONS: none
 ** POST-CONDITIONS: x and y updated
 ** RETURNS: nothing
 *********************************************************************/
void Grid::locationInput(){
    int x, y;
    cout << "Enter the x coordinate of the starting position: " << endl;
    cin >> x;
    while(x > 10 || x < 1 || cin.fail()){
        cout << "Input must be a number between 1 - 10, try again: " << endl;
        cin.clear();
        cin.ignore();
        cin >> x;
    }// end while
    cout << "Enter the y coordinate of the starting position: " << endl;
    cin >> y;
    while(y > 10 || y < 1 || cin.fail()){
        cout << "Input must be a number between 1 - 10, try again: " << endl;
        cin.clear();
        cin.ignore();
        cin >> y;
    }// end while
    w.setLocation_x(x); // x
    w.setLocation_y(y); // y
} // end locationInput
/*********************************************************************
 ** FUNCTION: inBoundaries
 ** DESCRIPTION: check if input for x and y are within boundaries
 ** PARAMETERS: none
 ** PRE-CONDITIONS: none
 ** POST-CONDITIONS: none
 ** RETURNS: bool
 *********************************************************************/
bool Grid::inBoundaries(){
    int x, y;
    x = w.getLocation_x();
    y = w.getLocation_y();
    if(w.checkHorizontal() == true){
        for(int i = 0; i < w.getLength(); i++){
            if(x > 10){
                //cout << "Not in boundaries!" << endl;
                return false;
            }// end if
            x++;
        }// end for
    }// end if
    else{
        for(int i = 0; i < w.getLength(); i++){
            if(y > 10){
                //cout << "Not in boundaries!" << endl;
                return false;
            }// end if
            y++;
        }// end for
    }// end else
    return true;
} // end inBoundaries
/*********************************************************************
 ** FUNCTION: addShip
 ** DESCRIPTION: adds the current ship to the board, checks boundaries of board dimensions
 ** PARAMETERS: none
 ** PRE-CONDITIONS: none
 ** POST-CONDITIONS: none
 ** RETURNS: nothing
 *********************************************************************/
void Grid::addShip(){
    cout << "To add the submarine to the board keep in mind a couple of things." << endl;
    cout << endl;
    cout << "1: When asked for an x or y coordinate for the submarine's starting position" << endl;
    cout << "do not go over 10 as this will exceed the board's boundaries." << endl;
    cout << "2: The coordinate's of the starting position will represent the head" << endl;
    cout << "of the submarine." << endl;
    cout << "3: If orientation is horizontal, the submarine will extend from the head to the right." << endl;
    cout << "4: If the orientation is vertical, the submarine will extend from the head, down." << endl;
    cout << endl;
    
    // will loop until ship fits within the boundaries of the board dimensions of 10 x 10
    locationInput();
    while(inBoundaries() == false){
        cout << "Not in boundaries!" << endl;
        locationInput();
        inBoundaries();
    }// end while
    int x, y;
    x = w.getLocation_x() - 1;
    y = w.getLocation_y() - 1;
    if(w.checkHorizontal() == true){
        for(int i = 0; i < w.getLength(); i++){
            board[y][x] = 'o';
            x++;
        }// end for
    }// end if
    else{
        for(int i = 0; i < w.getLength(); i++){
            board[y][x] = 'o';
            y++;
        }// end for
    }// end else
} // end addShip
/*********************************************************************
 ** FUNCTION: subInput
 ** DESCRIPTION: submarine variable inputs
 ** PARAMETERS: none
 ** PRE-CONDITIONS: none
 ** POST-CONDITIONS: diveDepth and surfaced updated
 ** RETURNS: nothing
 *********************************************************************/
void Grid::subInput(){
    cout << "Please input the dive depth of the submarine. (0 - 1000)" << endl;
    int depth;
    cin >> depth;
    //just setting some sort of range to limit user input
    //0 depth means surfaced
    while(depth < 0 || depth > 1000 || cin.fail()){
        cout << "Invalid input! Must input between 0 - 1000" << endl;
        cin.clear();
        cin.ignore();
        cin >> depth;
    }// end while
    w.setDepth(depth);
    if(depth == 0){
        w.setSurfaced(true);
    }// end if
    else{
        w.setSurfaced((false));
    }// end else
} // end subInput
/*********************************************************************
 ** FUNCTION: randomShots
 ** DESCRIPTION: randomly generates 15 shots on board
 ** PARAMETERS: none
 ** PRE-CONDITIONS: none
 ** POST-CONDITIONS: none
 ** RETURNS: nothing
 *********************************************************************/
void Grid::randomShots(){
    int count = 0;
    int x, y, _length;
    _length = w.getLength();
    while(count < 15){
        x = (rand()%10) + 1;
        y = (rand()%10) + 1;
        if(board[y][x] == ' ' || board[y][x] == 'o'){
            if(board[y][x] == 'o'){
                _length--;
            }// end if
            board[y][x] = 'x';
            count++;
        }// end if
    }// end while
    // checks if submarine has been hit, sunk or missed
    if(w.isHit(_length)){
        cout << "The submarine has been hit!" << endl;
        w.setHitStatus(true);
    }// end if
    if(w.isSunk(_length)){
        cout << "The submarine has been sunk!" << endl;
         w.setSunkStatus(true);
    }// end if
    if(w.isHit(_length) == false && w.isSunk(_length) == false){
        cout << "The submarine has not been hit or sunk! Congratulations!" << endl;
    }// end if
} // end randomShots
/*********************************************************************
 ** FUNCTION: playGame
 ** DESCRIPTION: calls functions to play game all in one function
 ** PARAMETERS: none
 ** PRE-CONDITIONS: none
 ** POST-CONDITIONS: none
 ** RETURNS: nothing
 *********************************************************************/
void Grid::playGame(){
    clearGrid(); // clear board
    printGrid(); // print board
    cout << endl;
    lengthInput(); // input for length
    orientationInput(); // input for orientation
    subInput(); // input for submarine variables
    addShip(); // add ship to board
    randomShots(); // randomize 15 shots
    printGrid(); // print board again
    cout << "X's represent randomized shots and O's represent the submarine." << endl;
    // second submarine
    Submarine s;
    s = w;
    s.printContents(); // print second submarine object
}




















