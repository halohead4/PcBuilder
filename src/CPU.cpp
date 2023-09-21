#include "CPU.h"
#include <string>
#include <iostream>
#include <fstream>
#include "Part.h"

using namespace std;

// Default constructor that sets default values
CPU::CPU(){
    Setprice(0);
    Setpowerrating(0);
    Setname("n/a");
    nofcores = 0;
    clockspeed = 0;
    cout << "CPU Constructed" << endl;
}

// Overloaded constructor that takes parameters and sets member variables accordingly
CPU::CPU(string n, int a, int b, int c, int d){
    Setname(n);
    Setprice(a);
    Setpowerrating(b);
    Setnofcores(c);
    Setclockspeed(d);
    cout << "CPU Constructed" << endl;
}

// Saves the current state of the CPU object to an output stream
void CPU::save(std::ostream& os) const {
    os << "CPU" << '\n'; // save the class name
    os << Getname() << endl;
    os << Getprice() << endl;
    os << clockspeed << endl;
    os << nofcores << endl;
}

// Loads the state of the CPU object from an input stream
void CPU::load(ifstream& is) {
    string name;
    int price;
    getline(is, name);
    Setname(name);
    is >> price;
    Setprice(price);
    is >> clockspeed;
    is >> nofcores;
}

// Allocates dynamic memory for an array of integers of a specified size and fills it with some values
void CPU::allocate_memory(int size) {
    int* array = new int[size]; // Allocate an array of integers with the specified size
    for (int i = 0; i < size; i++) {
        array[i] = i * i; // Fill the array with some values
    }
    cout << "Allocated memory for " << size << " integers." << endl;
    delete[] array; // Deallocate the memory to avoid memory leaks
}

// Destructor that prints a message indicating that the CPU object is being destroyed
CPU::~CPU(){
    cout << "CPU Destroyed" << endl;
}

// Displays all stored info of the CPU object
void CPU::display(){
    cout<< endl;
    cout<<"------------Displaying info---------------"<< endl;
    cout<<" Price: " <<Getprice() << endl << " Power Rating: " <<Getpowerrating() << endl << " Name: " <<Getname() << endl;
    cout << " Number of Cores: " <<nofcores << endl << " Clockspeed: " <<clockspeed << endl;
    cout<<"------------------------------------------"<< endl;
    cout<<endl<<endl;
}
