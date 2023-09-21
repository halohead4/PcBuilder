#ifndef SPEAKERS_H
#define SPEAKERS_H
#include <Part.h>
#include <string>
using namespace std;
class Speaker : public Part{
    public:
        Speaker(); // Default constructor
        Speaker(string n, int m, int a); // Overloaded constructor 1
        Speaker(string n, int a, int b, int c, bool d);// Overloaded constructor 2
        virtual ~Speaker(); // Destructor
        int GetdriverSize() { return driverSize; } // Getter function for driver size
        void SetdriverSize(int val) { driverSize = val; } // Setter function for driver size
        bool Getsubwoofer() { return subwoofer; } // Getter function for subwoofer
        void Setsubwoofer(bool val) { subwoofer = val; } // Setter function for subwoofer
        void display();// function that displays all stored information
        void save(std::ostream& os) const;
        void load(std::ifstream& is);
    protected:
    private:
        int driverSize; // A private variable for storing driver size
        bool subwoofer; // A private variable for storing subwoofer information
};
#endif // SPEAKER_H
