//
//CSCI 2312
//Homework 2
//September 1, 2017
//Grid class prototypes

#include <vector>
#include <iostream>

using namespace std;

class Grid{
    
private:
    
    // used for size of vector
    int ROWS;
    int COLS;
    
    // multidimensional vector
    vector < vector<int> > gridVector;
    
public:
    
    // default constructor
    Grid():ROWS(0),COLS(0),gridVector(0,vector<int>(0)){}
    
    // overloaded constructor
    Grid(int _rows, int _cols);
    
    // accessor for ROWS
    int getRows() const;
    
    // accessor for COLS
    int getCols() const;
    
    // mutator for ROWS
    void setRows(int _rows);
    
    // mutator for COLS
    void setCols(int _cols);
    
    // returns multidimensional vector
    vector< vector<int> > getVector() const;
    
    // resizes multidimensional vector
    void resizeVector();
    
    // will fill 1/3 of grid with 1's
    void fillThirdOfGrid();
    
    // will compare 2 gridVectors and initialize
    // a vector with cells that both have 1's
    // from gridVectors compared
    void compareVectors(const Grid& g1,const Grid& g2);
    
    // prints grid
    void printGrid() const;
    
};











