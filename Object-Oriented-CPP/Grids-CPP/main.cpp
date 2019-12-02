//
//  main.cpp
//  Grids
//
//  Created by Tobby Lie on 8/30/17.
//  Copyright © 2017 Tobby Lie. All rights reserved.
//

#include <iostream>
//Tobby Lie 103385744
//CSCI 2312
//Homework Assignment 2
//Septemer 1, 2017

//This program reads user input
//for the width and length of
//a grid, two grids will then
//be displayed which contain
//1's in 1/3 of their cells
//a third grid will then be
//created that contains 1's
//in the cells that grid one
//and two both had 1's in

#include <ctime>
#include <cstdlib>
#include "Grid.h"
#include "functions.h"

using namespace std;

int main() {

    srand((int)time(0));
    
    // ask user for input of dimensions of grid
    cout << "What is the width of the grid?" << endl;
    int ROWS = checkInput();
    
    cout << "What is the length of the grid?" << endl;
    int COLS = checkInput();
    
    // create objects
    Grid g1(ROWS, COLS), g2(ROWS, COLS), resultGrid(ROWS, COLS);
    
    // fill 1/3 of objects with 1's
    g1.fillThirdOfGrid();
    g2.fillThirdOfGrid();
    
    // print first 2 grids
    cout << "Grid 1" << endl;
    cout << "------" << endl;
    g1.printGrid();
    cout << endl;
    
    cout << "Grid 2" << endl;
    cout << "------" << endl;
    g2.printGrid();
    cout << endl;
    
    // resultGrid will have 1 in the cells
    // that g1 and g2 had 1's in
    resultGrid.compareVectors(g1, g2);
    cout << endl;
    
    cout << "Result Grid" << endl;
    cout << "-----------" << endl;
    resultGrid.printGrid();
    
    return 0;
}
































