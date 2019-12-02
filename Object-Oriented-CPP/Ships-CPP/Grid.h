//Tobby Lie
//CSCI 2312
//Homework 3
//September 18, 2017
//Grid class prototypes

#include <vector>
#include "WaterVehicle.h"

using namespace std;

class Grid{
private:
    static const int ROWS = 10; // rows
    static const int COLS = 10; // cols
    char board[ROWS][COLS]; // board game is played on
    Submarine w; // will call a WaterVehicle type to utilize in this class
    // Grid "has a" WaterVehicle
public:
    void clearGrid(); // clears grid
    void printGrid(); // prints contents of grid
    void orientationInput(); // 0 for horizontal, 1 for vertical
    void lengthInput(); // gets input for length of ship, uses error checking
    void locationInput(); // x, y coordinates
    void addShip(); // add ship to board
    bool inBoundaries(); // checks if ship position and size are within board boundaries of 10 x 10
    void randomShots(); // random 15 shots
    void subInput(); // for submarine variables
    void playGame(); // call to play entire game
}; // end Grid
