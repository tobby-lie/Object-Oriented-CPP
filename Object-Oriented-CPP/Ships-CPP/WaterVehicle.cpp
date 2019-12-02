//Tobby Lie
//CSCI 2312
//Homework 3
//September 18, 2017
//WaterVehicle class implementation

#include <iostream>
#include "WaterVehicle.h"

using namespace std;

/*********************************************************************
 ** FUNCTION: WaterVehicle
 ** DESCRIPTION: default constructor
 ** PARAMETERS:  none
 ** PRE-CONDITIONS: none
 ** POST-CONDITIONS: none
 ** RETURNS: nothing
 *********************************************************************/
WaterVehicle::WaterVehicle():length(0),startLocation_x(0), startLocation_y(0),sunk(false), hit(false), isHorizontal(false){} // end WaterVehicle
/*********************************************************************
 ** FUNCTION: WaterVehicle
 ** DESCRIPTION: overloaded constructor
 ** PARAMETERS:  _length, _x, _y, _sunk, _hit, _isHorizontal
 ** PRE-CONDITIONS: none
 ** POST-CONDITIONS: object updated
 ** RETURNS: nothing
 *********************************************************************/
WaterVehicle::WaterVehicle(int _length, int _x, int _y, bool _sunk, bool _hit, bool _isHorizontal):length(_length),startLocation_x(_x), startLocation_y(_y), sunk(_sunk), hit(_hit), isHorizontal(_isHorizontal){} // end WaterVehicle
/*********************************************************************
 ** FUNCTION: getLength
 ** DESCRIPTION: accessor for length
 ** PARAMETERS:  none
 ** PRE-CONDITIONS: length should be assigned a value
 ** POST-CONDITIONS: none
 ** RETURNS: length
 *********************************************************************/
int WaterVehicle::getLength() const{
    return length;
} // end getLength
/*********************************************************************
 ** FUNCTION: setLength
 ** DESCRIPTION: mutator for length
 ** PARAMETERS:  _length
 ** PRE-CONDITIONS: none
 ** POST-CONDITIONS: length updated
 ** RETURNS: nothing
 *********************************************************************/
void WaterVehicle::setLength(int _length){
    length = _length;
} // end setLength
/*********************************************************************
 ** FUNCTION: getLocation_x
 ** DESCRIPTION: accessor for x coordinate
 ** PARAMETERS:  none
 ** PRE-CONDITIONS: x coordinate should be assigned a value
 ** POST-CONDITIONS: none
 ** RETURNS: startLocation_x
 *********************************************************************/
int WaterVehicle::getLocation_x() const{
    return startLocation_x;
} // end getLocation_x
/*********************************************************************
 ** FUNCTION: setLocation_x
 ** DESCRIPTION: mutator for x coordinate
 ** PARAMETERS:  _x
 ** PRE-CONDITIONS: none
 ** POST-CONDITIONS: x coordinate updated
 ** RETURNS: nothing
 *********************************************************************/
void WaterVehicle::setLocation_x(int _x){
    startLocation_x = _x;
} // end setLocation_x
/*********************************************************************
 ** FUNCTION: getLocation_y
 ** DESCRIPTION: accessor for y coordinate
 ** PARAMETERS:  none
 ** PRE-CONDITIONS: y coordinate should be assigned a value
 ** POST-CONDITIONS: none
 ** RETURNS: startLocation_y
 *********************************************************************/
int WaterVehicle::getLocation_y() const{
    return startLocation_y;
} // end getLocation_y
/*********************************************************************
 ** FUNCTION: setLocation_y
 ** DESCRIPTION: mutator for y coordinate
 ** PARAMETERS:  _y
 ** PRE-CONDITIONS: none
 ** POST-CONDITIONS: y coordinate updated
 ** RETURNS: nothing
 *********************************************************************/
void WaterVehicle::setLocation_y(int _y){
    startLocation_y = _y;
} // end setLocation_y
/*********************************************************************
 ** FUNCTION: isSunk
 ** DESCRIPTION: returns true if ship is sunk
 ** PARAMETERS:  _length
 ** PRE-CONDITIONS: should have ship length
 ** POST-CONDITIONS: none
 ** RETURNS: bool
 *********************************************************************/
bool WaterVehicle::isSunk(int _length) const{
    // we know that all components
    // of the ship are gone
    if(_length == 0){
        return true; // signals that it is sunk
    }// end if
    return false;
} // end isSunk
/*********************************************************************
 ** FUNCTION: isHit
 ** DESCRIPTION: returns true if ship has been hit
 ** PARAMETERS:  _length
 ** PRE-CONDITIONS: should have ship length
 ** POST-CONDITIONS: none
 ** RETURNS: bool
 *********************************************************************/
bool WaterVehicle::isHit(int _length) const{
    if(_length < length){
        return true;
    }// end if
    return false;
} // end isHit
/*********************************************************************
 ** FUNCTION: setHitStatus
 ** DESCRIPTION: can set if a ship has been hit or not
 ** PARAMETERS:  hitStatus
 ** PRE-CONDITIONS: none
 ** POST-CONDITIONS: hit updated
 ** RETURNS: nothing
 *********************************************************************/
void WaterVehicle::setHitStatus(bool hitStatus){
    hit = hitStatus;
} // end setHitStatus
/*********************************************************************
 ** FUNCTION: setSunkStatus
 ** DESCRIPTION: can set if ship has sunk or not
 ** PARAMETERS:  sunkStatus
 ** PRE-CONDITIONS: none
 ** POST-CONDITIONS: sunk updated
 ** RETURNS: nothing
 *********************************************************************/
void WaterVehicle::setSunkStatus(bool sunkStatus){
    sunk = sunkStatus;
} // end setSunkStatus
/*********************************************************************
 ** FUNCTION: getHitStatus
 ** DESCRIPTION: accessor for hit
 ** PARAMETERS:  none
 ** PRE-CONDITIONS: none
 ** POST-CONDITIONS: none
 ** RETURNS: hit
 *********************************************************************/
bool WaterVehicle::getHitStatus() const{
    return hit;
} // end getHitStatus
/*********************************************************************
 ** FUNCTION: getSunkStatus
 ** DESCRIPTION: accessor for sunk
 ** PARAMETERS:  none
 ** PRE-CONDITIONS: none
 ** POST-CONDITIONS: none
 ** RETURNS: sunk
 *********************************************************************/
bool WaterVehicle::getSunkStatus() const{
    return sunk;
} // end getSunkStatus
/*********************************************************************
 ** FUNCTION: setOrientation
 ** DESCRIPTION: mutator for orientation
 ** PARAMETERS:  _orientation
 ** PRE-CONDITIONS: none
 ** POST-CONDITIONS: isHorizontal updated
 ** RETURNS: nothing
 *********************************************************************/
void WaterVehicle::setOrientation(int _orientation){
    if(_orientation == 0){
        isHorizontal = true; // if user inputs 0 this signals that ship is horizontal
    }// end if
    else if(_orientation == 1){
        isHorizontal = false; // else if user inputs 1 then ship is vertical
    }// end else if
} // end setOrientation
/*********************************************************************
 ** FUNCTION: checkHorizontal
 ** DESCRIPTION: accessor for isHorizontal
 ** PARAMETERS:  none
 ** PRE-CONDITIONS: none
 ** POST-CONDITIONS: none
 ** RETURNS: bool
 *********************************************************************/
bool WaterVehicle::checkHorizontal() const{
    if(isHorizontal == true){
        return true;
    }// end if
    else{
        return false;
    }// end else
} // end checkHorizontal
/*********************************************************************
 ** FUNCTION: Submarine
 ** DESCRIPTION: default constructor, also initializes waterVehicle variables
 ** PARAMETERS:  none
 ** PRE-CONDITIONS: none
 ** POST-CONDITIONS: none
 ** RETURNS: nothing
 *********************************************************************/
Submarine::Submarine():WaterVehicle(),diveDepth(0),surfaced(false){} // end WaterVehicle
/*********************************************************************
 ** FUNCTION: Submarine
 ** DESCRIPTION: overloaded constructor, also initializes waterVehicle variables
 ** PARAMETERS:  _length, _x, _y, _sunk, _hit, _isHorizontal, _depth, _surfaced
 ** PRE-CONDITIONS: none
 ** POST-CONDITIONS: WaterVehicle and Submarine updated
 ** RETURNS: nothing
 *********************************************************************/
Submarine::Submarine(int _length,  int _x, int _y, bool _sunk, bool _hit, bool _isHorizontal, int _depth, bool _surfaced):WaterVehicle(_length, _x, _y, _sunk, _hit, _isHorizontal), diveDepth(_depth), surfaced(_surfaced){} // end Submarine
/*********************************************************************
 ** FUNCTION: getDepth
 ** DESCRIPTION: accessor for diveDepth
 ** PARAMETERS:  none
 ** PRE-CONDITIONS: diveDepth should be initialized
 ** POST-CONDITIONS: none
 ** RETURNS: diveDepth
 *********************************************************************/
int Submarine::getDepth() const{
    return diveDepth;
} // end getDepth
/*********************************************************************
 ** FUNCTION: setDepth
 ** DESCRIPTION: mutator for diveDepth
 ** PARAMETERS:  _depth
 ** PRE-CONDITIONS: none
 ** POST-CONDITIONS: diveDepth updated
 ** RETURNS: nothing
 *********************************************************************/
void Submarine::setDepth(int _depth){
    diveDepth = _depth;
} // end setDepth
/*********************************************************************
 ** FUNCTION: setSurfaced
 ** DESCRIPTION: mutator for surfaced
 ** PARAMETERS:  _surfaced
 ** PRE-CONDITIONS: none
 ** POST-CONDITIONS: surfaced updated
 ** RETURNS: nothing
 *********************************************************************/
void Submarine::setSurfaced(bool _surfaced){
    surfaced = _surfaced;
} // end surfaced
/*********************************************************************
 ** FUNCTION: isSurfaced
 ** DESCRIPTION: accessor for surfaced
 ** PARAMETERS:  none
 ** PRE-CONDITIONS: surfaced should be initialized
 ** POST-CONDITIONS: none
 ** RETURNS: surfaced
 *********************************************************************/
bool Submarine::isSurfaced() const{
    return surfaced;
} // end isSurfaced
/*********************************************************************
 ** FUNCTION: operator=
 ** DESCRIPTION: overloaded = operator
 ** PARAMETERS:  s of type Submarine
 ** PRE-CONDITIONS: should have a Submarine object to pass in
 ** POST-CONDITIONS: none
 ** RETURNS: nothing
 *********************************************************************/
void Submarine::operator=(Submarine s){
    setLength(s.getLength()); // length
    setLocation_x(s.getLocation_x()); // x coordinate
    setLocation_y(s.getLocation_y()); // y coordinate
    setSunkStatus(s.getSunkStatus()); // sunk
    setHitStatus(s.getHitStatus()); // hit
    setOrientation(s.checkHorizontal()); // orientation
    setDepth(s.getDepth()); // diveDepth
    setSurfaced(s.isSurfaced()); // surfaced
} // end operator=
/*********************************************************************
 ** FUNCTION: printContents
 ** DESCRIPTION: prints info about current object
 ** PARAMETERS:  none
 ** PRE-CONDITIONS: object should have variables initialized
 ** POST-CONDITIONS: none
 ** RETURNS: nothing
 *********************************************************************/
void Submarine::printContents(){
    cout << "Information about this submarine: " << endl;
    cout << "Length: " << getLength() << endl; // length
    // starting position (x,y)
    cout << "Start location (x,y): " << "(" << getLocation_x() << "," << getLocation_y() << ")" << endl;
    if(getSunkStatus() == true){
        cout << "Ship has sunk." << endl; // if ship has sunk
    }// end if
    else{
        cout << "Ship has not been sunk." << endl; // if ship has not sunk
    }// end else
    if(getHitStatus() == true){
        cout << "Ship has been hit." << endl; // if ship has been hit
    }// end if
    else{
        cout << "Ship has not been hit." << endl; // if ship has not been hit
    }// end else
    if(checkHorizontal() == true){
        cout << "Orientation: Vertical" << endl; // if vertical
    }// end if
    else{
        cout << "Orientation: Horizontal" << endl; // if horizontal
    }// end else
    cout << "Dive Depth: " << diveDepth << endl; // diveDepth
    if(surfaced == true){
        cout << "Has surfaced" << endl; // if surfaced
    }// end if
    else{
        cout << "Has not surfaced" << endl; // if not surfaced
    }// end else
} // end printContents









    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    





