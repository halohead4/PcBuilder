#include "Speakers.h"
#include <string>
#include <iostream>
#include "Part.h"
#include <fstream>
using namespace std;
// Default constructor
Speaker::Speaker(){
    // Set default values
    Setprice(0);
    Setpowerrating(0);
    Setname("n/a");
    driverSize = 0;
    subwoofer = 0;
    cout << "Default Speaker created" << endl;
}

// Overloaded constructor 1
Speaker::Speaker(string n, int m, int a){
    // Set name, price, power rating
    Setname(n);
    Setprice(m);
    Setpowerrating(a);
    // Set default values for other properties
    driverSize = 0;
    subwoofer = 0;
    cout << "Default Speaker 2 created" << endl;
}

// Overloaded constructor 2
Speaker::Speaker(string n, int a, int b, int c, bool d){
    // Set name, price, power rating, driver size, and subwoofer properties
    Setname(n);
    Setprice(a);
    Setpowerrating(b);
    SetdriverSize(c);
    Setsubwoofer(d);
    cout << "CPU Constructed" << endl;
    }

// Destructor
Speaker::~Speaker(){
    cout << "Speaker destroyed" << endl;
}

// Function that displays all stored info
void Speaker::display(){
    cout << "Displaying info" << endl;
    cout << Getprice() << endl << Getpowerrating() << endl << Getname() << endl;
    cout << driverSize << endl << subwoofer << endl << endl;
}

// Function that saves the object's properties to an output stream
void Speaker::save(std::ostream& os) const {
    os << "Speakers" << '\n'; // save the class name
    os << Getname() << endl;
    os << Getprice() << endl;
    os << driverSize << endl;
    os << subwoofer << endl;
}

// Function that loads the object's properties from an input stream
void Speaker::load(ifstream& is) {
    string name;
    int price;
    getline(is, name);
    Setname(name);
    is >> price;
    Setprice(price);
    is >> driverSize;
    is >> subwoofer;
    }
