#ifndef MOTHERBOARD_H
#define MOTHERBOARD_H
#include <string>
#include "Part.h"
using namespace std;
class Motherboard : public Part{
    public:
        Motherboard(); // Default constructor of the Motherboard class.
        Motherboard(string a, int b, int c, int d, string e, int f, int g); // Overloaded constructor of the Motherboard class.
        virtual ~Motherboard(); // Virtual destructor of the Motherboard class.
        int Getnofusbports() { return nofusbports; } // Getting the number of USB ports in the Motherboard.
        void Setnofusbports(int val) { nofusbports = val; } // Setting the number of USB ports in the Motherboard.
        string Getsockettype() { return sockettype; } // Getting the socket type of the Motherboard.
        void Setsockettype(string val) { sockettype = val; } // Setting the socket type of the Motherboard.
        int Getramslots() { return ramslots; } // Getting the number of RAM slots in the Motherboard.
        void Setramslots(int val) { ramslots = val; } // Setting the number of RAM slots in the Motherboard.
        int Getramgen() { return ramgen; } // Getting the RAM generation of the Motherboard.
        void Setramgen(int val) { ramgen = val; } // Setting the RAM generation of the Motherboard.
        void save(std::ostream& os) const;
        void load(std::ifstream& is);

    protected:
    private:
        int nofusbports; // The number of USB ports in the Motherboard.
        string sockettype; // The socket type of the Motherboard.
        int ramslots; // The number of RAM slots in the Motherboard.
        int ramgen; // The RAM generation of the Motherboard.
};
#endif // MOTHERBOARD_H

/*#ifndef MOTHERBOARD_H
#define MOTHERBOARD_H
#include <string>
#include "Part.h"
using namespace std;
class Motherboard : public Part{
    public:
        Motherboard(); // Default constructor of the Motherboard class.
        Motherboard(string a, int b, int c, int d, string e, int f, int g); // Overloaded constructor of the Motherboard class.
        virtual ~Motherboard(); // Virtual destructor of the Motherboard class.
        int Getnofusbports() { return nofusbports; } // Getting the number of USB ports in the Motherboard.
        void Setnofusbports(int val) { nofusbports = val; } // Setting the number of USB ports in the Motherboard.
        string Getsockettype() { return sockettype; } // Getting the socket type of the Motherboard.
        void Setsockettype(string val) { sockettype = val; } // Setting the socket type of the Motherboard.
        int Getramslots() { return ramslots; } // Getting the number of RAM slots in the Motherboard.
        void Setramslots(int val) { ramslots = val; } // Setting the number of RAM slots in the Motherboard.
        int Getramgen() { return ramgen; } // Getting the RAM generation of the Motherboard.
        void Setramgen(int val) { ramgen = val; } // Setting the RAM generation of the Motherboard.
    protected:
    private:
        int nofusbports; // The number of USB ports in the Motherboard.
        string sockettype; // The socket type of the Motherboard.
        int ramslots; // The number of RAM slots in the Motherboard.
        int ramgen; // The RAM generation of the Motherboard.
};
#endif // MOTHERBOARD_H
*/
