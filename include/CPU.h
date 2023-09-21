#ifndef CPU_H
#define CPU_H
#include "Part.h"
#include <string>
class CPU : public Part {
    public:
        CPU(); // Default constructor
        CPU(string n, int a, int b, int c, int d); // Overloaded constructor
        ~CPU(); // Destructor
        int Getnofcores() { return nofcores; } // Getter function for nofcores
        void Setnofcores(int val) { nofcores = val; } // Setter function for nofcores
        float Getclockspeed() { return clockspeed; } // Getter function for clockspeed
        void Setclockspeed(float val) { clockspeed = val; } // Setter function for clockspeed
        void display(); // Function that displays all stored info
        void save(std::ostream& os) const; // Function to save CPU info to a file
        void load(std::ifstream& is); // Function to load CPU info from a file
        void allocate_memory(int size); // Function that demonstrates dynamic memory allocation
    private:
        int nofcores; // Private variable that stores the number of cores
        float clockspeed; // Private variable that stores the clock speed
};

#endif // CPU_H
