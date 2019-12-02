//Tobby Lie
//CSCI 2312
//Homework 3
//September 18, 2017
//WaterVehicle class prototypes

class WaterVehicle{
private:
    int length;
    int startLocation_x;
    int startLocation_y;// head of ship starts here
    bool sunk;
    bool hit;
    bool isHorizontal; // if horizontal ship will extend out from head to the right by however
                       // much length is, if vertical, ship will extend from head down
public:
    WaterVehicle(); // default constructor
    WaterVehicle(int _length, int _x, int _y, bool _sunk, bool _hit, bool _isHorizontal); // overloaded constructor
    int getLength() const;
    void setLength(int _length);
    int getLocation_x() const;
    void setLocation_x(int _x);
    int getLocation_y() const;
    void setLocation_y(int _y);
    bool isSunk(int _length) const; // returns true if ship is sunk
    void setSunkStatus(bool sunkStatus); // can set bool for sunk
    bool getSunkStatus() const; // returns true or false for sunk
    bool isHit(int _length) const; // returns true if ship is hit
    void setHitStatus(bool hitStatus); // can set bool for hit
    bool getHitStatus() const; // returns true or false for hit
    void setOrientation(int _orientation); // 0 for horizontal, 1 for vertical
    bool checkHorizontal() const; // returns true if ship is horizontal, otherwise vertical
}; // end WaterVehicle
class Submarine: public WaterVehicle{
private:
    int diveDepth;
    bool surfaced;
public:
    Submarine(); // default constructor
    // overloaded constructor
    Submarine(int _length,  int _x, int _y, bool _sunk, bool _hit, bool _isHorizontal, int _depth, bool _surfaced);
    int getDepth() const;
    void setDepth(int _depth);
    void setSurfaced(bool _surfaced); // set surfaced to true or false
    bool isSurfaced() const; // returns true if sub has surfaced
    void operator=(Submarine s); // overloeaded =
    void printContents(); // print contents of object
}; // end Submarine


















