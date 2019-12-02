//Tobby Lie
//CSCI 2312
//Homework 4
//October 1, 2017
//Animal class prototypes

#ifndef Animal_hpp
#define Animal_hpp

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class weightLessEqualToZero{};
class heightLessEqualToZero{};
class ageLessEqualToZero{}; // will signal if age is less than or equal to zero
class notYOrNPredator{}; // if is not Y or N for bool
class notYOrNFreshWater{};
class notYOrNWild{};
class notYOrNEndangered{};
class notYOrNProtected{};
class blankField{}; // used for when a field is blank

class Animal{
private:
    string name;
    string color;
public:
    Animal();
    void setName(string _name);
    string getName() const;
    void setColor(string _color);
    string getColor() const;
    virtual void readFromFile(string fileName); // virtual
    virtual void print(); // virtual
};
class Dog:public Animal{
private:
    string breed;
    int age;
    double weight;
public:
    Dog();
    void setBreed(string _breed);
    string getBreed() const;
    void setAge(int _age) throw(ageLessEqualToZero);
    int getAge() const;
    void setWeight(double _weight) throw(weightLessEqualToZero);
    double getWeight() const;
    void subtract10();
    void readFromFile(string fileName);
    void print();
};
class Fish:public Animal{
private:
    bool freshwater;
    string habitat;
    bool predator;
public:
    Fish();
    void setFreshWater(string status) throw(notYOrNFreshWater);
    bool isFreshWater() const;
    void setHabitat(string _habitat);
    string getHabitat() const;
    void setPredator(string status) throw(notYOrNPredator);
    bool isPredator() const;
    void readFromFile(string fileName);
    void print();
};
class Horse:public Animal{
private:
    string maneColor;
    int age;
    int height;
public:
    Horse();
    void setManeColor(string _maneColor);
    string getManeColor() const;
    void setAge(int _age) throw(ageLessEqualToZero);
    int getAge() const;
    void setHeight(int _height) throw(heightLessEqualToZero);
    int getHeight() const;
    void add1();
    void readFromFile(string fileName);
    void print();
};
class Monkey:public Animal{
private:
    int age;
    bool wild;
    string home;
    bool endangered;
public:
    Monkey();
    void setAge(int _age) throw(ageLessEqualToZero);
    int getAge() const;
    void setWild(string status) throw(notYOrNWild);
    bool isWild() const;
    void setHome(string _home);
    string getHome() const;
    void setEndangered(string status) throw(notYOrNEndangered);
    bool isEndangered() const;
    void changeEndangered();
    void readFromFile(string fileName);
    void print();
};
class Lizard:public Animal{
private:
    string habitat;
    bool _protected;
    double weight;
public:
    Lizard();
    void setHabitat(string _habitat);
    string getHabitat() const;
    void setProtected(string status) throw(notYOrNProtected);
    bool isProtected() const;
    void setWeight(double _weight) throw(weightLessEqualToZero);
    double getWeight() const;
    void readFromFile(string fileName);
    void print();
};

#endif /* Animal_hpp */























