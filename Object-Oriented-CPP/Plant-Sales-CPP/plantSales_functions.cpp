//
//CSCI 2312
//Homework Assignment 1
//August 22, 2017
//support functions for plant sales program

#include <iostream>
#include "plantSales_functions.h"

using namespace std;

/*********************************************************************
 ** FUNCTION: askInput
 ** DESCRIPTION: prompts user for input and then returns
 ** that input for usage in code
 ** PARAMETERS:  none
 ** PRE-CONDITIONS: input must be a number
 ** POST-CONDITIONS: none
 ** RETURNS: plants
 *********************************************************************/

double askInput(){
    
    cout << "How many plants are available to sell in store?" << endl;
    cout << "Please input the quantity: " << endl;
    
    double plants;
    cin >> plants;
    
    return plants;
    
}

/*********************************************************************
 ** FUNCTION: calculatePlantsSold
 ** DESCRIPTION: calculates plants sold at certain temperature ranges
 ** and then prints out results to screen
 ** PARAMETERS:  numPlants
 ** PRE-CONDITIONS: input must be number of plants available
 ** POST-CONDITIONS: numPlants printed out after calculations
 ** RETURNS: none
 *********************************************************************/

void calculatePlantsSold(double numPlants){
    
    cout << "#############################" << endl;
    cout << "# Outdoor Temp: Plants sold #" << endl;
    cout << "#############################" << endl;
    cout << endl;
    cout << "Colder than 40 degrees: " << numPlants*.10 << " plants sold" << endl;
    cout << endl;
    cout << "Between 40 degrees and 60 degrees: " << numPlants*.30 << " plants sold" << endl;
    cout << endl;
    cout << "Between 61 degrees and 70 degrees: " << numPlants*.50 << " plants sold" << endl;
    cout << endl;
    cout << "Between 71 degrees and 80 degrees: " << numPlants*.60 << " plants sold" << endl;
    cout << endl;
    cout << "Hotter than 80 degrees: " << numPlants*.40 << " plants sold" << endl;
    cout << endl;
    
    return;
}

