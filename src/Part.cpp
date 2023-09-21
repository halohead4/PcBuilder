#include "Part.h"
#include <iostream>
using namespace std;
Part::Part(){
    // Set default values
    Setprice(0);
    Setpowerrating(0);
    Setname("n/a");
    cout << "Part Constructed" << endl;
}

// Destructor
Part::~Part(){
    cout << "Part Destroyed" << endl;
}

// Function that displays all stored info
void Part::display() const {
    // Display all stored info
    cout << "------------Displaying info-------------" << endl;
    cout << " Name: " << Getname() << endl;
    cout << " Price: " << Getprice() << endl;
    cout << " Power rating: " << Getpowerrating() << endl;
    cout << "----------------------------------------" << endl;
}

// Implementation of comparison operators
bool Part::operator==(const Part& other) const {
    // Check if two parts are equal
    return (name == other.name && price == other.price && powerrating== other.powerrating);
}

bool Part::operator!=(const Part& other) const {
    // Check if two parts are not equal
    return !(*this == other);
}

bool Part::operator<(const Part& other) const {
    // Check if price of this part is less than price of other part
    return price < other.price;
}

bool Part::operator>(const Part& other) const {
    // Check if price of this part is greater than price of other part
    return price > other.price;
}

bool Part::operator<=(const Part& other) const {
    // Check if price of this part is less than or equal to price of other part
    return price <= other.price;
}

bool Part::operator>=(const Part& other) const {
    // Check if price of this part is greater than or equal to price of other part
    return price >= other.price;
}
