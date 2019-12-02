//Tobby Lie 103385744
//CSCI 2312
//Homework Assignment 1
//August 22, 2017
//This program reads a user input
//and computes and displays
//the estimated number of plants
//which will be sold for all
//temperature ranges

#include <iostream>
#include "plantSales_functions.h" 

using namespace std;

int main(){
    
    // call askInput which will
    // store user input as double
    double numPlants = askInput();
    
    // calculate and print out results
    calculatePlantsSold(numPlants);
    
    
    return 0;
}
