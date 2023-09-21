#ifndef PC_H
#define PC_H
#include "Part.h"
#include <vector>
#include "Part.h"
#include <algorithm>
class PC{
    public:
        PC();//Default constructor
        ~PC();
        void Addpart(Part* val);// Adding a new part to the PC.
        void Removepart(int index); // Removing a part from the PC.
        void Displayparts() const; // Displaying all the parts present in the PC.
        void Sortbypartprice();
        void Sortbyname();
        void Sortbypowerrating();
        Part* Findpart(const string& name) const;
        int Gettotalpower() const { return totalpower; } // Getting the total power of the PC.
        bool Getpsucompatible() const { return psucompatible; } // Getting the PSU compatibility status.
        void Setpsucompatible(bool val) { psucompatible = val; } // Setting the PSU compatibility status.
        int Getnofcomponants() const { return nofcomponants; } // Getting the number of components present in the PC.
        void SavePC(string filename);
        PC& operator=(const PC& other); // Overloading = operator for deep copy
        void LoadPC(string filename);

    private:
        int totalpower; // The total power of the PC.
        bool psucompatible; // The PSU compatibility status.
        int nofcomponants; // The number of components present in the PC.
        std::vector<Part*> parts; // A vector that will store all the parts present in the PC using pointers.
        int calculatepower; // A variable that will store the calculated power.
};
#endif // PC_H



/*#ifndef PC_H
#define PC_H
#include <vector>
#include "Part.h"
#include <algorithm>
class PC{
    public:
        PC(); // Default constructor
        ~PC();
        void Addpart(Part* val); // Adding a new part to the PC.
        void Removepart(int index); // Removing a part from the PC.
        void Displayparts() const; // Displaying all the parts present in the PC.
        void Sortbypartprice();
        void Sortbyname();
        void Sortbypowerrating();
        Part* Findpart(const string& name) const;
        int Gettotalpower() const { return totalpower; } // Getting the total power of the PC.
        bool Getpsucompatible() const { return psucompatible; } // Getting the PSU compatibility status.
        void Setpsucompatible(bool val) { psucompatible = val; } // Setting the PSU compatibility status.
        int Getnofcomponants() const { return nofcomponants; } // Getting the number of components present in the PC.
        PC& operator=(const PC& other); // Overloading = operator for deep copy
    private:
        int totalpower; // The total power of the PC.
        bool psucompatible; // The PSU compatibility status.
        int nofcomponants; // The number of components present in the PC.
        Part** parts; // A pointer to an array that will store all the parts present in the PC using pointers.
        int calculatepower; // A variable that will store the calculated power.
};
#endif

*/
