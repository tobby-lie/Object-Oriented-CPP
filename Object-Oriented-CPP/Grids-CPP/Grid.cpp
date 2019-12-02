


#include "Grid.h"


/*********************************************************************
 ** FUNCTION: Grid
 ** DESCRIPTION: overloaded constructor
 ** PARAMETERS:  int _rows, _cols
 ** PRE-CONDITIONS: inputs must be ints
 ** POST-CONDITIONS: member variables updated
 ** RETURNS: nothing
 *********************************************************************/

Grid::Grid(int _rows, int _cols){
    
    ROWS = _rows;
    COLS = _cols;
    
    gridVector.resize(ROWS, vector<int>(COLS, 0));
    
}

/*********************************************************************
 ** FUNCTION: setRows
 ** DESCRIPTION: inizializes ROWS from input
 ** PARAMETERS:  int _rows
 ** PRE-CONDITIONS: input must be an int
 ** POST-CONDITIONS: ROWS updated
 ** RETURNS: nothing
 *********************************************************************/

void Grid::setRows(int _rows){
    
    ROWS = _rows;
    
}

/*********************************************************************
 ** FUNCTION: getRows
 ** DESCRIPTION: returns ROWS
 ** PARAMETERS:  none
 ** PRE-CONDITIONS: none
 ** POST-CONDITIONS: none
 ** RETURNS: int ROWS
 *********************************************************************/

int Grid::getRows() const{
    
    return ROWS;
    
}

/*********************************************************************
 ** FUNCTION: setCols
 ** DESCRIPTION: initializes COLS from input
 ** that input for usage in code
 ** PARAMETERS:  int _cols
 ** PRE-CONDITIONS: input must be an int
 ** POST-CONDITIONS: COLS updated
 ** RETURNS: nothing
 *********************************************************************/

void Grid::setCols(int _cols){
    
    COLS = _cols;
    
}

/*********************************************************************
 ** FUNCTION: getCols
 ** DESCRIPTION: returns COLS
 ** PARAMETERS:  none
 ** PRE-CONDITIONS: none
 ** POST-CONDITIONS: none
 ** RETURNS: int COLS
 *********************************************************************/


int Grid::getCols() const{
    
    return COLS;
    
}

/*********************************************************************
 ** FUNCTION: getVector
 ** DESCRIPTION: returns gridVector
 ** PARAMETERS:  none
 ** PRE-CONDITIONS: none
 ** POST-CONDITIONS: none
 ** RETURNS: vector<vector<int>> gridVector
 *********************************************************************/


vector<vector<int>> Grid::getVector() const{
    
    return gridVector;
    
}

/*********************************************************************
 ** FUNCTION: resizeVector
 ** DESCRIPTION: resizes the rows and columns of gridVector
 ** PARAMETERS:  none
 ** PRE-CONDITIONS: none
 ** POST-CONDITIONS: gridVector rows and columns updated
 ** RETURNS: nothing
 *********************************************************************/

void Grid::resizeVector(){
    
    gridVector.clear();
    gridVector.resize(ROWS, vector<int>(COLS, 0));
    
}

/*********************************************************************
 ** FUNCTION: fillThirdOfGrid
 ** DESCRIPTION: fills 1/3 of grid cells with 1's, if one third of
 ** the number of cells in the grid does not equate to a whole number
 ** the program will use the rounded down whole number for a third
 ** PARAMETERS:  none
 ** PRE-CONDITIONS: none
 ** POST-CONDITIONS: gridVector updated
 ** RETURNS: none
 *********************************************************************/

void Grid::fillThirdOfGrid(){
    
     int size = 0;
    
    for(int i = 0; i < gridVector.size(); i++){
        
        size += gridVector[i].size();
        
    }
    
    // will define the amount of iterations
    // needed for loop to fill
    // 1/3 of the grid
    int oneThirdSize = (size/3);
    
    int count = 1;
    
    // loop breaks when count
    // becomes greater than oneThirdSize
    while(count <= oneThirdSize){
        
        int randRows = (rand()%ROWS);
        int randCols = (rand()%COLS);
        
       if(gridVector[randRows][randCols] == 0){
            
            gridVector[randRows][randCols] = 1;
           
            //increments whenever a cell is filled with 1
            count++;
           
        }
        
    }
    
    
    
}

/*********************************************************************
 ** FUNCTION: compareVectors
 ** DESCRIPTION: compares two Grid objects and initializes cells 
 ** that both have a 1 in them to 1 for new Grid object
 ** PARAMETERS:  Grid g1, g2
 ** PRE-CONDITIONS: 3 Grid objects must exist
 ** POST-CONDITIONS: gridVector updated
 ** RETURNS: nothing
 *********************************************************************/

void Grid::compareVectors(const Grid& g1, const Grid& g2){
    
    // two temporary vectors created to hold
    // info from Grid objects
    vector<vector<int>> tempVect_1 = g1.getVector();
    vector<vector<int>> tempVect_2 = g2.getVector();
    
    for(int i = 0; i < ROWS; i++){
        
        for(int j = 0; j < COLS; j++){
            
            if((tempVect_1[i][j] == 1) && (tempVect_2[i][j] == 1)){
                
                gridVector[i][j] = 1;
                
            }
            else{
                
                gridVector[i][j] = 0;
                
            }
        }
        
    }
    
}

/*********************************************************************
 ** FUNCTION: printGrid
 ** DESCRIPTION: prints contents of gridVector
 ** PARAMETERS:  none
 ** PRE-CONDITIONS: none
 ** POST-CONDITIONS: none
 ** RETURNS: none
 *********************************************************************/

void Grid::printGrid() const{
    
    for(int i = 0; i < ROWS; i++){
        
        for(int j = 0; j < COLS; j++){
            
            cout << gridVector[i][j];
            
        }
        
        cout << endl;
        
    }
    
}
