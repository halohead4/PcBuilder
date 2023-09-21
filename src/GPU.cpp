#include "GPU.h"
#include <iostream>
#include <fstream>

using namespace std;

GPU::GPU(){
// Default constructor
}

GPU::GPU(string a, int b, int c, int d, int e, int f, int g, int h){
    // Overloaded constructor that sets the properties of the GPU object
    Setname(a);
    Setpowerrating(b);
    Setprice(c);
    Setmemorysize(d);
    Sethdmiports(e);
    Setdviports(f);
    Setdisplayports(g);
    Setclockspeed(h);
}

GPU::~GPU(){
// Destructor
}

void GPU::save(std::ostream& os) const {
    os << "GPU" << '\n'; // save the class name
    os << Getname() << endl; // save the GPU's name
    os << Getprice() << endl; // save the GPU's price
    os << memorysize << endl; // save the GPU's memory size
    os << hdmiports << endl; // save the number of HDMI ports the GPU has
    os << dviports << endl; // save the number of DVI ports the GPU has
    os << displayports << endl; // save the number of display ports the GPU has
    os << clockspeed << endl; // save the GPU's clock speed
}

void GPU::load(ifstream& is) {
    string name;
    int price;
    getline(is, name); // get the GPU's name from the input stream
    Setname(name);
    is >> price; // get the GPU's price from the input stream
    Setprice(price);
    is >> memorysize; // get the GPU's memory size from the input stream
    is >> hdmiports; // get the number of HDMI ports the GPU has from the input stream
    is >> dviports; // get the number of DVI ports the GPU has from the input stream
    is >> displayports; // get the number of display ports the GPU has from the input stream
    is >> clockspeed; // get the GPU's clock speed from the input stream
}
