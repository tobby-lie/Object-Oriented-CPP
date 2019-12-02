//Tobby Lie
//CSCI 2312
//Homework 4
//October 1, 2017
//Animal class implementation

#include <fstream>
#include <string>
#include <cctype>
#include <cstring>
#include <iomanip>
#include "Animal.h"

using namespace std;

Animal::Animal():name(""),color(""){} // default constructor
/*********************************************************************
 ** FUNCTION: setName
 ** DESCRIPTION: setter for name variable
 ** PARAMETERS:  string _name
 ** PRE-CONDITIONS: none
 ** POST-CONDITIONS: name updated
 ** RETURNS: none
 *********************************************************************/
void Animal::setName(string _name) {name = _name;}; // end setName
/*********************************************************************
 ** FUNCTION: getName
 ** DESCRIPTION: getter for name variable
 ** PARAMETERS:  none
 ** PRE-CONDITIONS: name updated
 ** POST-CONDITIONS: none
 ** RETURNS: string
 *********************************************************************/
string Animal::getName() const {return name;} // end getName
/*********************************************************************
 ** FUNCTION: setColor
 ** DESCRIPTION: setter for color variable
 ** PARAMETERS:  string _color
 ** PRE-CONDITIONS: none
 ** POST-CONDITIONS: color updated
 ** RETURNS: none
 *********************************************************************/
void Animal::setColor(string _color) {color = _color;} // end setColor
/*********************************************************************
 ** FUNCTION: getColor
 ** DESCRIPTION: getter for color variable
 ** PARAMETERS:  none
 ** PRE-CONDITIONS: color updated
 ** POST-CONDITIONS: none
 ** RETURNS: string
 *********************************************************************/
string Animal::getColor() const {return color;} // end getColor
/*********************************************************************
 ** FUNCTION: readFromFile
 ** DESCRIPTION: reads file in and sets all variables
 ** PARAMETERS:  string fileName
 ** PRE-CONDITIONS: none
 ** POST-CONDITIONS: member variables updated
 ** RETURNS: none
 *********************************************************************/
void Animal::readFromFile(string fileName){
    ifstream inFile;
    inFile.open(fileName.c_str());
    if(inFile.fail()){
        cout << "Failed to open file!" << endl;
    } // end if
    string _name, _color;
    getline(inFile, _name, ',');
    getline(inFile, _color, ',');
    setName(_name);
    setColor(_color);
} // end readFromFile
/*********************************************************************
 ** FUNCTION: print
 ** DESCRIPTION: prints contents of all member variables
 ** PARAMETERS:  none
 ** PRE-CONDITIONS: variables updated
 ** POST-CONDITIONS: none
 ** RETURNS: none
 *********************************************************************/
void Animal::print(){
    cout << "Name: " << name << endl;
    cout << "Color: " << color << endl;
} // end print

Dog::Dog():Animal(),breed(""),age(1), weight(1){} // default constructor
/*********************************************************************
 ** FUNCTION: setBreed
 ** DESCRIPTION: setter for breed variable
 ** PARAMETERS:  string _breed
 ** PRE-CONDITIONS: none
 ** POST-CONDITIONS: breed updated
 ** RETURNS: none
 *********************************************************************/
void Dog::setBreed(string _breed){breed = _breed;} // end setBreed
/*********************************************************************
 ** FUNCTION: getBreed
 ** DESCRIPTION: getter for breed variable
 ** PARAMETERS:  none
 ** PRE-CONDITIONS: none
 ** POST-CONDITIONS: breed updated
 ** RETURNS: string
 *********************************************************************/
string Dog::getBreed() const {return breed;} // end getBreed
/*********************************************************************
 ** FUNCTION: setAge
 ** DESCRIPTION: setter for age variable
 ** PARAMETERS:  int _age
 ** PRE-CONDITIONS: none
 ** POST-CONDITIONS: age updated
 ** RETURNS: none
 *********************************************************************/
void Dog::setAge(int _age) throw(ageLessEqualToZero){
        if(_age <= 0) // if age is 0 or negative throw exception
            throw ageLessEqualToZero(); // end if
        age = _age;
} // end setAge
/*********************************************************************
 ** FUNCTION: getAge
 ** DESCRIPTION: getter for age variable
 ** PARAMETERS:  none
 ** PRE-CONDITIONS: age updated
 ** POST-CONDITIONS: none
 ** RETURNS: int
 *********************************************************************/
int Dog::getAge() const {return age;} // end getAge
/*********************************************************************
 ** FUNCTION: setWeight
 ** DESCRIPTION: setter for weight variable
 ** PARAMETERS:  double _weight
 ** PRE-CONDITIONS: none
 ** POST-CONDITIONS: weight updated
 ** RETURNS: none
 *********************************************************************/
void Dog::setWeight(double _weight) throw(weightLessEqualToZero){
        if(_weight <= 0) // if weight is 0 or negative throw exception
            throw weightLessEqualToZero(); // end if
        weight = _weight;
} // end setWeight
/*********************************************************************
 ** FUNCTION: subtract10
 ** DESCRIPTION: subtracts 10 from dog weight
 ** PARAMETERS:  none
 ** PRE-CONDITIONS: weight updated
 ** POST-CONDITIONS: weight updated
 ** RETURNS: none
 *********************************************************************/
void Dog::subtract10(){
    weight = weight - 10; // subtract weight
    try{
        if(weight <=0 ){ // if weight after subtraction is 0 or negative, throw exception
            throw weight;
        } // end if
    } // end throw
    catch(double w){ // catches exception
        cout << "Error: Dog weight cannot be 0 or negative!" << endl;
        cout << "Program aborting." << endl;
        exit(0);
    } // end catch
} // end subtract10
/*********************************************************************
 ** FUNCTION: getWeight
 ** DESCRIPTION: getter for weight variable
 ** PARAMETERS:  none
 ** PRE-CONDITIONS: weight updated
 ** POST-CONDITIONS: none
 ** RETURNS: double
 *********************************************************************/
double Dog::getWeight() const {return weight;} // end getWeight
/*********************************************************************
 ** FUNCTION: readFromFile
 ** DESCRIPTION: reads file in and sets all variables
 ** PARAMETERS:  string fileName
 ** PRE-CONDITIONS: none
 ** POST-CONDITIONS: member variables updated
 ** RETURNS: none
 *********************************************************************/
void Dog::readFromFile(string fileName){
    ifstream inFile;
    inFile.open(fileName.c_str());
    if(inFile.fail()){ // check if file open was successful
        cout << "Failed to open file!" << endl;
    } // end if
    string _name, _color, _breed;
    string agestr, weightstr;
    int _age = 0;
    double _weight = 0;
    
    getline(inFile, _name, ',');
    getline(inFile, _breed, ',');
    getline(inFile, agestr, ',');
    getline(inFile, _color, ',');
    getline(inFile, weightstr);
 
    if(agestr != ""){
    _age = stoi(agestr); // did this so that any even blank space could be accounted for
    } // end if
    if(weightstr != ""){
    _weight = stod(weightstr);
    } // end if
    
    
    try{
    setColor(_color);
        if(weightstr != ""){
            setWeight(_weight);
            subtract10();// subtract 10 from weight
        }
        if(agestr != ""){
            setAge(_age);
        }
    setBreed(_breed);
    setName(_name);
    } // end try
    catch(ageLessEqualToZero){
        cout << "Error: Dog age cannot be 0 or negative!" << endl;
        cout << "Program aborting." << endl;
        exit(0);
    } // end catch
    catch(weightLessEqualToZero){
        cout << "Error: Dog weight cannot be 0 or negative!" << endl;
        cout << "Program aborting." << endl;
        exit(0);
    } // end catch
    catch(blankField){
        cout << "Error: An input field is blank!" << endl;
        cout << "Program aborting." << endl;
        exit(0);
    }
} // end readFromFile
/*********************************************************************
 ** FUNCTION: print
 ** DESCRIPTION: prints contents of all member variables
 ** PARAMETERS:  none
 ** PRE-CONDITIONS: variables updated
 ** POST-CONDITIONS: none
 ** RETURNS: none
 *********************************************************************/
void Dog::print(){
    cout << "Name: " << getName() << endl;
    cout << "Breed: " << breed << endl;
    if(age > 0){
    cout << "Age: " << age << " years old" << endl;
    }
    else{
        cout << "Age: " << endl;
    }
    cout << "Color: " << getColor() << endl;
    if(weight > 0){
    cout << "Weight: " << weight << " lb" << endl;
    }
    else{
        cout << "Weight: " << endl;
    }
} // end print

Fish::Fish():Animal(),freshwater(true),habitat(""), predator(true){} // default constructor
/*********************************************************************
 ** FUNCTION: setFreshWater
 ** DESCRIPTION: setter for freshWater variable
 ** PARAMETERS:  string status
 ** PRE-CONDITIONS: none
 ** POST-CONDITIONS: freshWater updated
 ** RETURNS: none
 *********************************************************************/
void Fish::setFreshWater(string status) throw(notYOrNFreshWater){
    string::iterator iter;
    for(iter = status.begin(); iter != status.end(); iter++){ // iterates through whole string and makes every char uppercase
    *iter = toupper(*iter);
    } // end for
        if(status != "TRUE" && status != "FALSE"){ // throw exception if string is neither of these
            throw notYOrNFreshWater();
        } // end if
        if(status == "TRUE")
            freshwater = true; // end if
        else
            freshwater = false; // end else
} // end setFreshWater
/*********************************************************************
 ** FUNCTION: isFreshWater
 ** DESCRIPTION: getter for freshWater variable
 ** PARAMETERS:  none
 ** PRE-CONDITIONS: freshwater is updated
 ** POST-CONDITIONS: none
 ** RETURNS: bool
 *********************************************************************/
bool Fish::isFreshWater() const{return freshwater;} // end isFreshWater
/*********************************************************************
 ** FUNCTION: setHabitat
 ** DESCRIPTION: setter for habitat variable
 ** PARAMETERS:  string _habitat
 ** PRE-CONDITIONS: none
 ** POST-CONDITIONS: habitat updated
 ** RETURNS: none
 *********************************************************************/
void Fish::setHabitat(string _habitat){habitat = _habitat;} // end setHabitat
/*********************************************************************
 ** FUNCTION: getHabitat
 ** DESCRIPTION: getter for habitat variable
 ** PARAMETERS:  none
 ** PRE-CONDITIONS: habitat updated
 ** POST-CONDITIONS:
 ** RETURNS: string
 *********************************************************************/
string Fish::getHabitat() const {return habitat;} // end getHabitat
/*********************************************************************
 ** FUNCTION: setPredator
 ** DESCRIPTION: setter for predator variable
 ** PARAMETERS:  none
 ** PRE-CONDITIONS: none
 ** POST-CONDITIONS: predator updated
 ** RETURNS: none
 *********************************************************************/
void Fish::setPredator(string status) throw(notYOrNPredator){
    string::iterator iter;
    for(iter = status.begin(); iter != status.end(); iter++){
        *iter = toupper(*iter); // converts to uppercase
    } // end for
    if(status != "TRUE" && status != "FALSE"){
        throw notYOrNPredator(); // throw if string does not match either of these
    } // end if
        if(status == "TRUE")
            predator = true; // end if
        else
            predator = false; // end else
} // end setPredator
/*********************************************************************
 ** FUNCTION: isPredator
 ** DESCRIPTION: getter for predator variable
 ** PARAMETERS:  none
 ** PRE-CONDITIONS: predator updated
 ** POST-CONDITIONS: none
 ** RETURNS: bool
 *********************************************************************/
bool Fish::isPredator() const {return predator;} // end isPredator
/*********************************************************************
 ** FUNCTION: readFromFile
 ** DESCRIPTION: reads file in and sets all variables
 ** PARAMETERS:  string fileName
 ** PRE-CONDITIONS: none
 ** POST-CONDITIONS: member variables updated
 ** RETURNS: none
 *********************************************************************/
void Fish::readFromFile(string fileName){
    ifstream inFile;
    inFile.open(fileName.c_str());
    if(inFile.fail()){ // validate file open
        cout << "Failed to open file!" << endl;
    } // end if
    string _name, _color, _habitat;
    string _freshwater, _predator;
    
    getline(inFile, _name, ',');
    getline(inFile, _color, ',');
    getline(inFile, _freshwater, ',');
    getline(inFile, _habitat, ',');
    getline(inFile, _predator);
    
    try{ // if a field is blank, it will print out a default value or a blank space and continue with program
    setColor(_color);
    setName(_name);
    setHabitat(_habitat);
        if(_predator != ""){
            setPredator(_predator);
        }
    if(_freshwater != ""){
        setFreshWater(_freshwater);
    }
    } // end try
    catch(notYOrNFreshWater){
        cout << "Error: Fish fresh water status can only be either TRUE or FALSE!" << endl;
        cout << "Program aborting." << endl;
        exit(0);
    } // end catch
    catch(notYOrNPredator){
        cout << "Error: Fish predator status can only be either TRUE or FALSE!" << endl;
        cout << "Program aborting." << endl;
        exit(0);
    } // end catch
} // end readFromFile
/*********************************************************************
 ** FUNCTION: print
 ** DESCRIPTION: prints contents of all member variables
 ** PARAMETERS:  none
 ** PRE-CONDITIONS: variables updated
 ** POST-CONDITIONS: none
 ** RETURNS: none
 *********************************************************************/
void Fish::print(){
    cout << "Name: " << getName() << endl;
    cout << "Color: " << getColor() << endl;
    if(isFreshWater()){
        cout << "Fresh water: Yes" << endl;
    } // end if
    else{
        cout << "Fresh water: No" << endl;
    } // end else
    cout << "Habitat: " << habitat << endl;
    if(isPredator()){
        cout << "Predator: Yes" << endl;
    } // end if
    else{
        cout << "Predator: No" << endl;
    } // end else
} // end print

Horse::Horse():Animal(),maneColor(""), age(1), height(1){}
/*********************************************************************
 ** FUNCTION: setManeColor
 ** DESCRIPTION: setter for manecolor variable
 ** PARAMETERS:  string _maneColor
 ** PRE-CONDITIONS: none
 ** POST-CONDITIONS: manecolor updated
 ** RETURNS: none
 *********************************************************************/
void Horse::setManeColor(string _maneColor){
    maneColor = _maneColor;
} // end setManeColor
/*********************************************************************
 ** FUNCTION: getManeColor
 ** DESCRIPTION: getter for maneColor variable
 ** PARAMETERS:  none
 ** PRE-CONDITIONS: manecolor updated
 ** POST-CONDITIONS: none
 ** RETURNS: string
 *********************************************************************/
string Horse::getManeColor() const{
    return maneColor;
} // end getManecolor
/*********************************************************************
 ** FUNCTION: setAge
 ** DESCRIPTION: setter for age variable
 ** PARAMETERS:  none
 ** PRE-CONDITIONS: none
 ** POST-CONDITIONS: age updated
 ** RETURNS: none
 *********************************************************************/
void Horse::setAge(int _age) throw(ageLessEqualToZero){
        if(_age <= 0){ // throw excepton if age is 0 or negative
            throw ageLessEqualToZero();
        } // end if
        age = _age;
} // end setAge
/*********************************************************************
 ** FUNCTION: getAge
 ** DESCRIPTION: getter for age variable
 ** PARAMETERS:  none
 ** PRE-CONDITIONS: age updated
 ** POST-CONDITIONS: none
 ** RETURNS: int
 *********************************************************************/
int Horse::getAge() const{
    return age;
} // end getAge
/*********************************************************************
 ** FUNCTION: setHeight
 ** DESCRIPTION: setter for height variable
 ** PARAMETERS:  int _height
 ** PRE-CONDITIONS: none
 ** POST-CONDITIONS: height updated
 ** RETURNS: none
 *********************************************************************/
void Horse::setHeight(int _height) throw(heightLessEqualToZero){
        if(_height <= 0){ // throw if height 0 or negative
            throw heightLessEqualToZero();
        } // end if
        height = _height;
} // setHeight
/*********************************************************************
 ** FUNCTION: getHeight
 ** DESCRIPTION: getter for height variable
 ** PARAMETERS:  none
 ** PRE-CONDITIONS: height updated
 ** POST-CONDITIONS: none
 ** RETURNS: int
 *********************************************************************/
int Horse::getHeight() const{
    return height;
} // end getHeight
/*********************************************************************
 ** FUNCTION: add1
 ** DESCRIPTION: add 1 to height
 ** PARAMETERS:  none
 ** PRE-CONDITIONS: none
 ** POST-CONDITIONS: height updated
 ** RETURNS: none
 *********************************************************************/
void Horse::add1(){
    height = height + 1; // add 1 to height
} // end add1
/*********************************************************************
 ** FUNCTION: readFromFile
 ** DESCRIPTION: reads file in and sets all variables
 ** PARAMETERS:  string fileName
 ** PRE-CONDITIONS: none
 ** POST-CONDITIONS: member variables updated
 ** RETURNS: none
 *********************************************************************/
void Horse::readFromFile(string fileName){
    ifstream inFile;
    inFile.open(fileName.c_str());
    if(inFile.fail()){
        cout << "Failed to open file!" << endl;
    } // end if
    string _name, _color, _maneColor;
    string agestr, heightstr;
    int _age = 0, _height = 0;
    
    getline(inFile, _name, ',');
    getline(inFile, _color, ',');
    getline(inFile, _maneColor, ',');
    getline(inFile, agestr, ',');
    getline(inFile, heightstr);

    if(agestr != ""){
        _age = stoi(agestr); // did this so that even blank spaces in field could be accounted for
    } // end if
    if(heightstr != ""){
        _height = stoi(heightstr);
    } // end if
    
    try{ // will print out either blank space or default value for blank fields
    setColor(_color);
    setName(_name);
    if(heightstr != ""){
        setHeight(_height);
    }
    if(agestr != ""){
        setAge(_age);
    }
    setManeColor(_maneColor);
    } // end try
    catch(ageLessEqualToZero){
        cout << "Error: Horse age cannot be 0 or negative!" << endl;
        cout << "Program aborting." << endl;
        exit(0);
    } // end catch
    catch(heightLessEqualToZero){
        cout << "Error: Horse height cannot be 0 or negative!" << endl;
        cout << "Program aborting." << endl;
        exit(0);
    } // end catch
} // end readFromFile
/*********************************************************************
 ** FUNCTION: print
 ** DESCRIPTION: prints contents of all member variables
 ** PARAMETERS:  none
 ** PRE-CONDITIONS: variables updated
 ** POST-CONDITIONS: none
 ** RETURNS: none
 *********************************************************************/
void Horse::print(){
    cout << "Name: " << getName() << endl;
    cout << "Color: " << getColor() << endl;
    cout << "Mane Color: " << maneColor << endl;
    cout << "Age: " << age << " years old" << endl;
    cout << "Height: " << height << " hands tall" << endl;
} // end print
Monkey::Monkey():Animal(), age(1), wild(true), home(""), endangered(true){}
/*********************************************************************
 ** FUNCTION: setAge
 ** DESCRIPTION: setter for age variable
 ** PARAMETERS:  int _age
 ** PRE-CONDITIONS: none
 ** POST-CONDITIONS: age updated
 ** RETURNS: none
 *********************************************************************/
void Monkey::setAge(int _age) throw(ageLessEqualToZero){
        if(_age <= 0){
            throw ageLessEqualToZero();
        } // end if
        age = _age;
} // end setAge
int Monkey::getAge() const{
    return age;
}
/*********************************************************************
 ** FUNCTION: setWild
 ** DESCRIPTION: setter for wild variable
 ** PARAMETERS:  string status
 ** PRE-CONDITIONS: none
 ** POST-CONDITIONS: wild updated
 ** RETURNS: none
 *********************************************************************/
void Monkey::setWild(string status) throw(notYOrNWild){
    string::iterator iter;
    for(iter = status.begin(); iter != status.end(); iter++){
        *iter = toupper(*iter);
    } // end for
        if(status != "TRUE" && status != "FALSE"){
            throw notYOrNWild();
        } // end if
        if(status == "TRUE"){
            wild = true;
        } // end if
        else{
            wild = false;
        } // end else
} // end setWild
/*********************************************************************
 ** FUNCTION: isWild
 ** DESCRIPTION: getter for wild variable
 ** PARAMETERS:  none
 ** PRE-CONDITIONS: wild updated
 ** POST-CONDITIONS: none
 ** RETURNS: bool
 *********************************************************************/
bool Monkey::isWild() const {return wild;} // end isWild
/*********************************************************************
 ** FUNCTION: setHome
 ** DESCRIPTION: setter for home variable
 ** PARAMETERS:  stirng _home
 ** PRE-CONDITIONS: home updated
 ** POST-CONDITIONS: none
 ** RETURNS: none
 *********************************************************************/
void Monkey::setHome(string _home){
    home = _home;
} // end setHome
/*********************************************************************
 ** FUNCTION: getHome
 ** DESCRIPTION: getter for home variable
 ** PARAMETERS:  none
 ** PRE-CONDITIONS: home updated
 ** POST-CONDITIONS: none
 ** RETURNS: string
 *********************************************************************/
string Monkey::getHome() const{return home;} // end getHome
/*********************************************************************
 ** FUNCTION: setEndangered
 ** DESCRIPTION: setter for endangered variable
 ** PARAMETERS:  string status
 ** PRE-CONDITIONS: none
 ** POST-CONDITIONS: endangered updated
 ** RETURNS: none
 *********************************************************************/
void Monkey::setEndangered(string status) throw(notYOrNEndangered){
    string::iterator iter;
    for(iter = status.begin(); iter != status.end(); iter++){
        *iter = toupper(*iter);
    } // end for
    if(status != "TRUE" && status != "FALSE"){
            throw notYOrNEndangered();
    } // end if
        if(status == "TRUE"){
            endangered = true;
        } // end if
        else{
            endangered = false;
        } // end else
        
} // end setEndangered
/*********************************************************************
 ** FUNCTION: isEndangered
 ** DESCRIPTION: getter for endangered variable
 ** PARAMETERS:  none
 ** PRE-CONDITIONS: endangered updated
 ** POST-CONDITIONS: none
 ** RETURNS: bool
 *********************************************************************/
bool Monkey::isEndangered() const{
    return endangered;
} // end isEndangered
/*********************************************************************
 ** FUNCTION: changeEndangered
 ** DESCRIPTION: changes status of endangered
 ** PARAMETERS:  none
 ** PRE-CONDITIONS: endangered updated
 ** POST-CONDITIONS: endangered updated
 ** RETURNS: none
 *********************************************************************/
void Monkey::changeEndangered(){
    if(endangered == true){
        endangered = false;
    } // end if
    else{
        endangered = true;
    } // end else
} // end changeEndangered
/*********************************************************************
 ** FUNCTION: readFromFile
 ** DESCRIPTION: reads file in and sets all variables
 ** PARAMETERS:  string fileName
 ** PRE-CONDITIONS: none
 ** POST-CONDITIONS: member variables updated
 ** RETURNS: none
 *********************************************************************/
void Monkey::readFromFile(string fileName){
    ifstream inFile;
    inFile.open(fileName.c_str());
    if(inFile.fail()){
        cout << "Failed to open file!" << endl;
    } // end if
    string _name, _color, _home;
    string agestr;
    int _age = 0;
    string _wild, _endangered;
    
    getline(inFile, _name, ',');
    getline(inFile, _color, ',');
    getline(inFile, agestr, ',');
    getline(inFile, _wild, ',');
    getline(inFile, _home, ',');
    getline(inFile, _endangered);
    
    if(agestr != ""){
        _age = stoi(agestr); // did this to make sure blank spaces could be accounted for
    } // end if
    
    try{ // will print out blank or default value for any blank field input
    if(agestr != ""){
        setAge(_age);
    }
    setColor(_color);
    setName(_name);
    setHome(_home);
    if(_wild != ""){
        setWild(_wild);
    }
    if(_endangered != ""){
        setEndangered(_endangered);
    }
    } // end try
    catch(ageLessEqualToZero){
        cout << "Error: Monkey age cannot be 0 or negative!" << endl;
        cout << "Program aborting." << endl;
        exit(0);
    } // end catch
    catch(notYOrNWild){
        cout << "Error: Monkey Wild status can only either be TRUE or FALSE!" << endl;
        cout << "Program aborting." << endl;
        exit(0);
    } // end catch
    catch(notYOrNEndangered){
        cout << "Error: Monkey Endangerment status can only either be TRUE or FALSE!" << endl;
        cout << "Program aborting." << endl;
        exit(0);
    } // end catch
} // end readFromFile
/*********************************************************************
 ** FUNCTION: print
 ** DESCRIPTION: prints contents of all member variables
 ** PARAMETERS:  none
 ** PRE-CONDITIONS: variables updated
 ** POST-CONDITIONS: none
 ** RETURNS: none
 *********************************************************************/
void Monkey::print(){
    cout << "Name: " << getName() << endl;
    cout << "Color: " << getColor() << endl;
    cout << "Age: " << age << " years old" << endl;
    if(isWild()){
        cout << "Wild: Yes" << endl;
    } // end if
    else{
        cout << "Wild: No" << endl;
    } // end else
    cout << "Home: " << home << endl;
    if(isEndangered()){
        cout << "Endangered: Yes" << endl;
    } // end if
    else{
        cout << "Endangered: No" << endl;
    } // end else
} // end print

Lizard::Lizard():Animal(), habitat(""), _protected(true), weight(1){}
/*********************************************************************
 ** FUNCTION: setHabitat
 ** DESCRIPTION: setter for habitat variable
 ** PARAMETERS:  string _habitat
 ** PRE-CONDITIONS: none
 ** POST-CONDITIONS: habitat updated
 ** RETURNS: none
 *********************************************************************/
void Lizard::setHabitat(string _habitat){
    habitat = _habitat;
} // end setHabitat
/*********************************************************************
 ** FUNCTION: getHabitat
 ** DESCRIPTION: getter for habitat variable
 ** PARAMETERS:   none
 ** PRE-CONDITIONS: habitat updated
 ** POST-CONDITIONS: none
 ** RETURNS: string
 *********************************************************************/
string Lizard::getHabitat() const{
    return habitat;
} // end getHabitat
/*********************************************************************
 ** FUNCTION: setProtected
 ** DESCRIPTION: setter for protected variable
 ** PARAMETERS:  string status
 ** PRE-CONDITIONS: none
 ** POST-CONDITIONS: protected updated
 ** RETURNS: none
 *********************************************************************/
void Lizard::setProtected(string status) throw(notYOrNProtected){
    string::iterator iter;
    for(iter = status.begin(); iter != status.end(); iter++){
        *iter = toupper(*iter);
    } // end for
        if(status != "TRUE" && status != "FALSE"){
            throw notYOrNProtected();
        } // end if
        if(status == "TRUE"){
            _protected = true;
        } // end if
        else{
            _protected = false;
        } // end else
} // end setProtrected
/*********************************************************************
 ** FUNCTION: isProtected
 ** DESCRIPTION: getter for protected variable
 ** PARAMETERS:  none
 ** PRE-CONDITIONS: protected updated
 ** POST-CONDITIONS: none
 ** RETURNS: bool
 *********************************************************************/
bool Lizard::isProtected() const {return _protected;} // end isProtected
/*********************************************************************
 ** FUNCTION: setWeight
 ** DESCRIPTION: setter for weight variable
 ** PARAMETERS:  double weight
 ** PRE-CONDITIONS: none
 ** POST-CONDITIONS: weight updated
 ** RETURNS: none
 *********************************************************************/
void Lizard::setWeight(double _weight) throw(weightLessEqualToZero){
        if(_weight <= 0)
            throw weightLessEqualToZero(); // end if
        weight = _weight;
} // end setWeight
/*********************************************************************
 ** FUNCTION: getWeight
 ** DESCRIPTION: getter for weight variable
 ** PARAMETERS:  none
 ** PRE-CONDITIONS: weight updated
 ** POST-CONDITIONS:
 ** RETURNS: double
 *********************************************************************/
double Lizard::getWeight() const{
    return weight;
} // end getWeight
/*********************************************************************
 ** FUNCTION: readFromFile
 ** DESCRIPTION: reads file in and sets all variables
 ** PARAMETERS:  string fileName
 ** PRE-CONDITIONS: none
 ** POST-CONDITIONS: member variables updated
 ** RETURNS: none
 *********************************************************************/
void Lizard::readFromFile(string fileName){
    ifstream inFile;
    inFile.open(fileName.c_str());
    if(inFile.fail()){
        cout << "Failed to open file!" << endl;
    } // end if
    string _name, _color, _habitat;
    string weightstr;
    double _weight = 0;
    string _protected;
    
    getline(inFile, _name, ',');
    getline(inFile, _color, ',');
    getline(inFile, _habitat, ',');
    getline(inFile, _protected, ',');
    getline(inFile, weightstr);
    
    if(weightstr != ""){
        _weight = stod(weightstr); // did this to account for blank space fields
    }
    
    try{ // if input field blank, will print out either default value or blank field
    setColor(_color);
    setName(_name);
    setHabitat(_habitat);
    if(weightstr != ""){
        setWeight(_weight);
    }
    if(_protected != ""){
        setProtected(_protected);
    }
    } // end try
    catch(notYOrNProtected){
        cout << "Error: Lizard protected status can only either be TRUE or FALSE!" << endl;
        cout << "Program aborting." << endl;
        exit(0);
    } // end catch
    catch(weightLessEqualToZero){
        cout << "Error: Lizard weight cannot be 0 or negative!" << endl;
        cout << "Program aborting." << endl;
        exit(0);
    } // end catch
} // end readFromFile
/*********************************************************************
 ** FUNCTION: print
 ** DESCRIPTION: prints contents of all member variables
 ** PARAMETERS:  none
 ** PRE-CONDITIONS: variables updated
 ** POST-CONDITIONS: none
 ** RETURNS: none
 *********************************************************************/
void Lizard::print(){
    cout << "Name: " << getName() << endl;
    cout << "Color: " << getColor() << endl;
    cout << "Habitat: " << habitat << endl;
    if(isProtected()){
        cout << "Protected: Yes" << endl;
    } // end if
    else{
        cout <<"Protected: No" << endl;
    } // end if
    cout << "Weight: " << weight << " lb" << endl;
} // end print















