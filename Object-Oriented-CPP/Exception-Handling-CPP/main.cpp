//Tobby Lie 103385744
//CSCI 2312
//Homework 4
//October 1, 2017
//This program uses
//exception handling
//and polymorphism to
//implement derived classes
//that take in different data

#include <iostream>
#include <fstream>
#include "Animal.h"
#include <string>

int main(){
    Dog d;
    Fish f;
    Horse h;
    Monkey m;
    Lizard l;
    
    d.readFromFile("Dog.csv"); // Dog
    cout << "Dog" << endl;
    cout << "---" << endl;
    d.print();
    cout << endl << endl;;
    
    f.readFromFile("Fish.csv"); // Fish
    cout << "Fish" << endl;
    cout << "----" << endl;
    f.print();
    cout << endl << endl;
    
    h.readFromFile("Horse.csv"); // Horse
    h.add1(); // add 1 to height
    cout << "Horse" << endl;
    cout << "-----" << endl;
    h.print();
    cout << endl << endl;
    
    m.readFromFile("Monkey.csv"); // Monkey
    m.changeEndangered(); // change endangered flag
    cout << "Monkey" << endl;
    cout << "------" << endl;
    m.print();
    cout << endl << endl;
    
    l.readFromFile("Lizard.csv"); // Lizard
    cout << "Lizard" << endl;
    cout << "------" << endl;
    l.print();
    cout << endl << endl;

    return 0;
}
