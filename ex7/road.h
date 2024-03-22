// road.h

#ifndef _road_h
#define _road_h

#include <string>

class Vehicle; // declare the class so Road can use it

/**
 * Road class
 */
class Road {
public:
    Road(std::string description);
    void advance_one_step();
    bool is_clear() const;
    int steps_to_clear() const;
    // return true if the spot exists and is nullptr or it doesn't exist
    bool spot_is_clear(int index) const;
    void display();
private:
    int length;
    int cur_step;
    Vehicle* *spots;            // array of spaces, allocate din constructor
};

/**
 * Vehicle class
 * Parent class for car, taxi, and truck
 * defines the interface for the derived classes
 */
class Vehicle {
public:
    Vehicle(Road *road_on) : _can_move{false}, road{road_on} { }
    bool can_move() const { return _can_move; }
    void reset_move_state() { _can_move = false; }
    virtual void check_can_move_from(int index) = 0; // pure virtual function
    virtual void celebrate() = 0; // pure virtual function
    virtual void display() = 0; // pure virtual function

protected:
    bool _can_move;        // is vehicle in a place where it can move?
    Road *road;            // current road vehicle is on
};

/**
 * Car class
 * Moves one space to the right when it has two spaces in front of it
 * Celebrates by printing "Beep beep"
 */
class Car : public Vehicle {
public:
    Car(Road *road_on) : Vehicle(road_on) { }
    void check_can_move_from(int index);
    void celebrate();
    void display();
};

/**
 * Taxi class
 * Moves one space to the right when it has one space in front of it
 * Celebrates by printing "Zoomm"
 */
class Taxi : public Vehicle {
public:
    Taxi(Road *road_on) : Vehicle(road_on) { }
    void check_can_move_from(int index);
    void celebrate();
    void display();
};

/*
 * Truck class
 * Moves one space to the right when it has three spaces in front of it
 * celebrates by printing "Blaaaaat"
 */
class Truck : public Vehicle {
    public:
    Truck(Road *road_on) : Vehicle(road_on) { }
    void check_can_move_from(int index);
    void celebrate();
    void display();
};

#endif