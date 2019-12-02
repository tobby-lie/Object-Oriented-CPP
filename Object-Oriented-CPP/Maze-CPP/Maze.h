//Tobby Lie 103385744
//CSCI 2312
//Homework 5
//October 24, 2017
//Maze program function implementation

#ifndef Maze_h
#define Maze_h

#include <iostream>

using namespace std;

struct Node{
    char name;
    Node* south;
    Node* north;
    Node* east;
    Node* west;
};

typedef Node* nodePtr; // Node pointer

/*********************************************************************
 ** FUNCTION: improvedMaze
 ** DESCRIPTION: runs the maze game, takes care of memory allocation
 ** and uses a series of switch statements to traverse graph
 ** USE THIS FOR PROGRAM AS IT IS MORE EFFICIENT THAN ORIGINAL MAZE FUCNT
 ** PARAMETERS: none
 ** PRE-CONDITIONS: currPtr should be blank and not pointing to
 ** anything when game begins
 ** POST-CONDITIONS: none
 ** RETURNS: nothing
 *********************************************************************/
void improvedMaze(){
    // currPtr is blank when created
    nodePtr currPtr = new Node;
    currPtr->name = ' ';
    currPtr->north = nullptr;
    currPtr->west = nullptr;
    currPtr->east = nullptr;
    currPtr->south = nullptr;
    
    // new Nodes
    nodePtr A = new Node,B = new Node,C = new Node,D = new Node,E = new Node,F = new Node,G = new Node,H = new Node, I = new Node, J = new Node, K = new Node, L = new Node;
    
    // graph initialization of all graph nodes
    A->name = 'A';A->south = E;A->north = nullptr;A->east = B;A->west = nullptr; // node A
    B->name = 'B'; B->south = F;B->north = nullptr;B->east = nullptr;B->west = A; // node B
    C->name = 'C';C->south = G;C->north = nullptr;C->east = nullptr;C->west = nullptr; // node C
    D->name = 'D';D->south = H;D->north = nullptr;D->east = nullptr;D->west = nullptr; // node D
    E->name = 'E';E->south = I;E->north = A;E->east = nullptr;E->west = nullptr; // node E
    F->name = 'F';F->south = nullptr;F->north = B;F->east = G;F->west = nullptr; // node F
    G->name = 'G';G->south = nullptr;G->north = C;G->east = H;G->west = F; // node G
    H->name = 'H';H->south = L;H->north = D;H->east = nullptr;H->west = G; // node H
    I->name = 'I';I->south = nullptr;I->north = E;I->east = J;I->west = nullptr; // node I
    J->name = 'J';J->south = nullptr;J->north = nullptr;J->east = K;J->west = I; // node J
    K->name = 'K';K->south = nullptr;K->north = nullptr;K->east = nullptr;K->west = J; // node K
    L->name = 'L';L->south = nullptr;L->north = H;L->east = nullptr;L->west = nullptr; // node L
    // end graph initialization
    // nullptr in any direction means that there is no node to go to in that direction
    
    cout << "***********************************************" << endl;
    cout << "* You wake up disoriented. You are in a maze. *" << endl;
    cout << "* Find your way out.                          *" << endl;
    cout << "***********************************************" << endl;
    cout << endl;
    
    // loop will terminate once currPtr name is L which is the finishing node
    char choice = ' ';
    while(currPtr->name != 'L'){
        
        if(currPtr->name == ' '){ // for when game first starts, set to starting point at A
            currPtr = A;
        }// end if
        
        bool north = false, south = false, east = false, west = false; // will allow program to decide which directions are available
        int directionCounter = 0; // just for fun, to display unique message for dead ends
        cout << "You are in room " << currPtr->name << "." << endl; // states which room user is in
        if(currPtr->north != nullptr){
            cout << "You can go north (N)" << endl;
            north = true;
            directionCounter++;
        } // end if
        if(currPtr->south != nullptr){
            cout << "You can go south (S)" << endl;
            south = true;
            directionCounter++;
        } // end if
        if(currPtr->west != nullptr){
            cout << "You can go west (W)" << endl;
            west = true;
            directionCounter++;
        } // end if
        if(currPtr->east != nullptr){
            cout << "You can go east (E)" << endl;
            east = true;
            directionCounter++;
        } // end if
        if(directionCounter == 1){
            cout << "You are at a dead end..." << endl;
        } // end if
        cout << "Which direction would you like to go?" << endl;
        cin >> choice;
        choice = toupper(choice);
        while((choice != 'W' && choice != 'E' && choice != 'S' && choice != 'N') || cin.fail()){
            cout << "Invalid input! Try again." << endl;
            cout << "Which direction would you like to go?" << endl;
            cin.clear();
            cin.ignore();
            cin >> choice;
            choice = toupper(choice);
        } // end while
        if(choice == 'W' && west == true){
            currPtr = currPtr->west;
        } // end if
        else if(choice == 'E' && east == true){
            currPtr = currPtr->east;
        } // end else if
        else if(choice == 'N' && north == true){
            currPtr = currPtr->north;
        } // end else if
        else if(choice == 'S' && south == true){
            currPtr = currPtr->south;
        } // end else if
        else{
            cout << "Invalid input! Try again." << endl;
        } // end else
        
    } // end while
    // victory message
    cout << "***************************************************" << endl;
    cout << "*You see a light at the end of a corridor...      *" << endl;
    cout << "*You made it to room L and escaped the maze alive.*" << endl;
    cout << "***************************************************" << endl;
    
    // return memory to freestore or heap
    delete A;delete B;delete C;delete D;delete E;delete F;delete G;delete H;delete I;delete J;delete K;delete L;
} // end improvedMaze

// anything below this comment will not be used, decided to save the code just in case, but just ignore it for the program. The code above is much more efficient and focuses more on pointers.

/*********************************************************************
 ** FUNCTION: positionA
 ** DESCRIPTION: takes various inputs that represent various directions
 ** a user can go depending on the current room they are in
 ** PARAMETERS: nodePtr south east west or north in any combination
 ** PRE-CONDITIONS: nodePtrs must already be initialized, meaning
 ** must have a name and pointers must either be pointed to another
 ** node or nullptr
 ** POST-CONDITIONS: currPtr updated
 ** RETURNS: nodePtr
 *********************************************************************/

// will only document one of these since they all pretty much function the same, just with
// various numbers of inputs
/*nodePtr positionA(nodePtr south, nodePtr east){
    char choice = ' ';
    cout << "You are in room A. You can go east or south." << endl;
    cout << "Which direction would you like to go? (E/S)" << endl;
    cin >> choice;
    choice = toupper(choice);
    while((choice != 'E' && choice != 'S') || cin.fail()){
        cout << "Invalid input! Must input E for east or S for south." << endl;
        cin.clear();
        cin.ignore();
        cin >> choice;
        choice = toupper(choice);
    } // end while
    if(choice == 'E'){
        return east;
    } // end if
    else{
        return south;
    } // end else
} // end positionA

nodePtr positionB(nodePtr south, nodePtr west){
    char choice = ' ';
    cout << "You are in room B. You can go west or south." << endl;
    cout << "Which direction would you like to go? (W/S)" << endl;
    cin >> choice;
    choice = toupper(choice);
    while((choice != 'W' && choice != 'S') || cin.fail()){
        cout << "Invalid input! Must input W for west or S for south." << endl;
        cin.clear();
        cin.ignore();
        cin >> choice;
        choice = toupper(choice);
    }
    if(choice == 'W'){
        return west;
    }
    else{
        return south;
    }
}

nodePtr positionC(nodePtr south){
    char choice = ' ';
    cout << "You are in room C. This is a dead end... You can only go south." << endl;
    cout << "You can input S to move south." << endl;
    cin >> choice;
    choice = toupper(choice);
    while((choice != 'S') || cin.fail()){
        cout << "Invalid input! Must input S for south." << endl;
        cin.clear();
        cin.ignore();
        cin >> choice;
        choice = toupper(choice);
    }
        return south;
}

nodePtr positionD(nodePtr south){
    char choice = ' ';
    cout << "You are in room D. This is a dead end... You can only go south." << endl;
    cout << "You can input S to move south." << endl;
    cin >> choice;
    choice = toupper(choice);
    while((choice != 'S') || cin.fail()){
        cout << "Invalid input! Must input S for south." << endl;
        cin.clear();
        cin.ignore();
        cin >> choice;
        choice = toupper(choice);
    }
    return south;
}

nodePtr positionE(nodePtr south, nodePtr north){
    char choice = ' ';
    cout << "You are in room E. You can go north or south." << endl;
    cout << "Which direction would you like to go? (N/S)" << endl;
    cin >> choice;
    choice = toupper(choice);
    while((choice != 'N' && choice != 'S') || cin.fail()){
        cout << "Invalid input! Must input N for north or S for south." << endl;
        cin.clear();
        cin.ignore();
        cin >> choice;
        choice = toupper(choice);
    }
    if(choice == 'N'){
        return north;
    }
    else{
        return south;
    }
}

nodePtr positionF(nodePtr east, nodePtr north){
    char choice = ' ';
    cout << "You are in room F. You can go north or east." << endl;
    cout << "Which direction would you like to go? (N/E)" << endl;
    cin >> choice;
    choice = toupper(choice);
    while((choice != 'N' && choice != 'E') || cin.fail()){
        cout << "Invalid input! Must input N for north or E for east." << endl;
        cin.clear();
        cin.ignore();
        cin >> choice;
        choice = toupper(choice);
    }
    if(choice == 'N'){
        return north;
    }
    else{
        return east;
    }
}

nodePtr positionG(nodePtr west, nodePtr north, nodePtr east){
    char choice = ' ';
    cout << "You are in room G. You can go west, north or east." << endl;
    cout << "Which direction would you like to go? (W/N/E)" << endl;
    cin >> choice;
    choice = toupper(choice);
    while((choice != 'N' && choice != 'E' && choice != 'W') || cin.fail()){
        cout << "Invalid input! Must input W for west, N for north or E for east." << endl;
        cin.clear();
        cin.ignore();
        cin >> choice;
        choice = toupper(choice);
    }
    if(choice == 'W'){
        return west;
    }
    else if(choice == 'E'){
        return east;
    }
    else{
        return north;
    }
}

nodePtr positionH(nodePtr west, nodePtr north, nodePtr south){
    char choice = ' ';
    cout << "You are in room H. You can go west, north or south." << endl;
    cout << "Which direction would you like to go? (W/N/S)" << endl;
    cin >> choice;
    choice = toupper(choice);
    while((choice != 'N' && choice != 'W' && choice != 'S') || cin.fail()){
        cout << "Invalid input! Must input W for west, N for north or S for south." << endl;
        cin.clear();
        cin.ignore();
        cin >> choice;
        choice = toupper(choice);
    }
    if(choice == 'W'){
        return west;
    }
    else if(choice == 'S'){
        return south;
    }
    else{
        return north;
    }
}

nodePtr positionI(nodePtr north, nodePtr east){
    char choice = ' ';
    cout << "You are in room I. You can go north or east." << endl;
    cout << "Which direction would you like to go? (N/E)" << endl;
    cin >> choice;
    choice = toupper(choice);
    while((choice != 'N' && choice != 'E') || cin.fail()){
        cout << "Invalid input! Must input N for north or E for east." << endl;
        cin.clear();
        cin.ignore();
        cin >> choice;
        choice = toupper(choice);
    }
    if(choice == 'N'){
        return north;
    }
    else{
        return east;
    }
}

nodePtr positionJ(nodePtr west, nodePtr east){
    char choice = ' ';
    cout << "You are in room J. You can go west or east." << endl;
    cout << "Which direction would you like to go? (W/E)" << endl;
    cin >> choice;
    choice = toupper(choice);
    while((choice != 'W' && choice != 'E') || cin.fail()){
        cout << "Invalid input! Must input W for west or E for east." << endl;
        cin.clear();
        cin.ignore();
        cin >> choice;
        choice = toupper(choice);
    }
    if(choice == 'W'){
        return west;
    }
    else{
        return east;
    }
}

nodePtr positionK(nodePtr west){
    char choice = ' ';
    cout << "You are in room K. This is a dead end... You can only go west." << endl;
    cout << "You can input W to move west." << endl;
    cin >> choice;
    choice = toupper(choice);
    while((choice != 'W') || cin.fail()){
        cout << "Invalid input! Must input W for west." << endl;
        cin.clear();
        cin.ignore();
        cin >> choice;
        choice = toupper(choice);
    }
    return west;
}*/

/*********************************************************************
 ** FUNCTION: originalMaze
 ** DESCRIPTION: runs the maze game, takes care of memory allocation
 ** and uses a series of switch statements to traverse graph
 ** will not use this as it is inefficient
 ** PARAMETERS: none
 ** PRE-CONDITIONS: currPtr should be blank and not pointing to 
 ** anything when game begins
 ** POST-CONDITIONS: none
 ** RETURNS: nothing
 *********************************************************************/
// will continue to loop until currPtr->name is L to represent landing on L which is finish
// currPtr being passed in will be initialized to blank
/*void originalMaze(){
    nodePtr currPtr = new Node;
    currPtr->name = ' ';
    currPtr->north = nullptr;
    currPtr->west = nullptr;
    currPtr->east = nullptr;
    currPtr->south = nullptr;
    
    // new Nodes
    nodePtr A = new Node,B = new Node,C = new Node,D = new Node,E = new Node,F = new Node,G = new Node,H = new Node, I = new Node, J = new Node, K = new Node, L = new Node;
    
    // graph initialization of all graph nodes
    A->name = 'A';A->south = E;A->north = nullptr;A->east = B;A->west = nullptr; // node A
    B->name = 'B'; B->south = F;B->north = nullptr;B->east = nullptr;B->west = A; // node B
    C->name = 'C';C->south = G;C->north = nullptr;C->east = nullptr;C->west = nullptr; // node C
    D->name = 'D';D->south = H;D->north = nullptr;D->east = nullptr;D->west = nullptr; // node D
    E->name = 'E';E->south = I;E->north = A;E->east = nullptr;E->west = nullptr; // node E
    F->name = 'F';F->south = nullptr;F->north = B;F->east = G;F->west = nullptr; // node F
    G->name = 'G';G->south = nullptr;G->north = C;G->east = H;G->west = F; // node G
    H->name = 'H';H->south = L;H->north = D;H->east = nullptr;H->west = G; // node H
    I->name = 'I';I->south = nullptr;I->north = E;I->east = J;I->west = nullptr; // node I
    J->name = 'J';J->south = nullptr;J->north = nullptr;J->east = K;J->west = I; // node J
    K->name = 'K';K->south = nullptr;K->north = nullptr;K->east = nullptr;K->west = J; // node K
    L->name = 'L';L->south = nullptr;L->north = H;L->east = nullptr;L->west = nullptr; // node L
    // end graph initialization
    // nullptr in any direction means that there is no node to go to in that direction
    
    cout << "***********************************************" << endl;
    cout << "* You wake up disoriented. You are in a maze. *" << endl;
    cout << "* Find your way out.                          *" << endl;
    cout << "***********************************************" << endl;
    cout << endl;
    
    // loop will terminate once currPtr name is L which is the finishing node
    while(currPtr->name != 'L'){
        
        if(currPtr->name == ' '){ // for when game first starts, set to starting point at A
            currPtr = A;
        }
        
        // switch statements will call functions that can allow user to move along the graph
        char nodeName = currPtr->name;
        switch(nodeName){
            case 'A':{
                currPtr = positionA(E, B);
                break;
            }
            case 'B':{
                currPtr = positionB(F, A);
                break;
            }
            case 'C':{
                currPtr = positionC(G);
                break;
            }
            case 'D':{
                currPtr = positionD(H);
                break;
            }
            case 'E':{
                currPtr = positionE(I, A);
                break;
            }
            case 'F':{
                currPtr = positionF(G, B);
                break;
            }
            case 'G':{
                currPtr = positionG(F, C, H);
                break;
            }
            case 'H':{
                currPtr = positionH(G, D, L);
                break;
            }
            case 'I':{
                currPtr = positionI(E, J);
                break;
            }
            case 'J':{
                currPtr = positionJ(I, K);
                break;
            }
            case 'K':{
                currPtr = positionK(J);
                break;
            }
            // don't need case L. Will never need to make a move from node L since it is the finish spot
        }
    }
    // victory message
    cout << "***************************************************" << endl;
    cout << "*You see a light at the end of a corridor...      *" << endl;
    cout << "*You made it to room L and escaped the maze alive.*" << endl;
    cout << "***************************************************" << endl;
    
    // return memory to freestore or heap
    delete A;delete B;delete C;delete D;delete E;delete F;delete G;delete H;delete I;delete J;delete K;delete L;
}*/

#endif /* Maze_h */




























