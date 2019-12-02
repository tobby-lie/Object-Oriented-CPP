//
//CSCI 2312
//Homework Assignment 2
//Septemember 1, 2017
//Support function for Grid program
//Validates input

/*********************************************************************
 ** FUNCTION: checkInput
 ** DESCRIPTION: validates input to int
** PARAMETERS:  none
 ** PRE-CONDITIONS: none
 ** POST-CONDITIONS: input is an int
 ** RETURNS: none
 *********************************************************************/

int checkInput(){
    
    int input = 0;
    // bool will become true when
    // input is validated to break
    // out of the loop
    bool isDone = false;
    
    // loop will break if
    // input if of valid data type
    do{
        
        cin >> input;
        
        // check if cin valid data type
        if(!cin.fail()){
            isDone = true;
        }
        else{
            // reset buffer state
            cin.clear();
            // empty buffer
            cin.ignore();
            // ask for input again
            cout << "Please input an integer." << endl;
        }
        
    }while(!isDone);

    return input;
}














