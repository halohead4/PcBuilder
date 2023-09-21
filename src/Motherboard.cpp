#include "Motherboard.h"
#include <iostream>
#include <fstream>
using namespace std;

// Default constructor
Motherboard::Motherboard()
{
//ctor
}

// Overloaded constructor
Motherboard::Motherboard(string a, int b, int c, int d, string e, int f, int g){
    // Set name, power rating, price, number of USB ports, socket type, RAM slots, and RAM generation
    Setname(a);
    Setpowerrating(b);
    Setprice(c);
    Setnofusbports(d);
    Setsockettype(e);
    Setramslots(f);
    Setramgen(g);
    }

// Destructor
Motherboard::~Motherboard()
{
//dtor
}

// Function that saves the object's properties to an output stream
void Motherboard::save(std::ostream& os) const {
    os << "Motherboard" << '\n'; // save the class name
    os << Getname() << endl; // save the motherboard's name
    os << Getprice() << endl; // save the motherboard's price
    os << nofusbports << endl; // save the number of USB ports on the motherboard
    os << sockettype << endl; // save the socket type of the motherboard
    os << ramslots << endl; // save the number of RAM slots on the motherboard
    os << ramgen << endl; // save the generation of RAM supported by the motherboard
}

// Function that loads the object's properties from an input stream
void Motherboard::load(ifstream& is) {
    string name;
    int price;
    getline(is, name); // get the motherboard's name from the input stream
    Setname(name);
    is >> price; // get the motherboard's price from the input stream
    Setprice(price);
    is >> nofusbports; // get the number of USB ports on the motherboard from the input stream
    is >> sockettype; // get the socket type of the motherboard from the input stream
    is >> ramslots; // get the number of RAM slots on the motherboard from the input stream
    is >> ramgen; // get the generation of RAM supported by the motherboard from the input stream
}
