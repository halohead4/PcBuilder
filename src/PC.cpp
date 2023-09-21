#include <string>
#include <iostream>
#include "PC.h"
#include "CPU.h"
#include "GPU.h"
#include "Motherboard.h"
#include "Speakers.h"
#include <algorithm>
#include <fstream>

using namespace std;
PC::PC(){
    //setting default values
    totalpower = 0;
    nofcomponants = 0;
    psucompatible = true;
    calculatepower = 0;
    cout << "Default PC constructed"<< endl;
}
PC::~PC(){
    for (Part* part : parts) {
        delete part; // free memory for all Part objects
    }
    parts.clear(); // remove all elements from the vector
    cout << "PC Destroyed" << endl;
}
void PC::Addpart(Part* val){
    //increase no of componants, add the part to the vector and increase total power by the power rating of the part
    nofcomponants++;
    parts.push_back(val);
    totalpower += val->Getpowerrating();
}
void PC::Removepart(int index){
    //decrease no of componants, remove part from the vector and decrease total power by the power rating of the part
    nofcomponants--;
    totalpower -= parts.at(index)->Getpowerrating();
    delete parts.at(index); // free memory for the removed Part object
    parts.erase(parts.begin() + index);
}
void PC::Displayparts() const {
    cout << "------------------PC Information---------------" << endl;
    cout << "Total Power: " << totalpower << endl;
    cout << "PSU Compatibility: " << psucompatible << endl;
    cout << "Number of Components: " << nofcomponants << endl;
    cout << "Number of Parts: " << parts.size() << endl;
    cout << "-----------------Displaying Parts--------------" << endl;
    for (int i = 0; i < nofcomponants; i++) {
        cout << i + 1 << ". ";

        // dynamically cast each Part object to its appropriate child class
        CPU* cpu = dynamic_cast<CPU*>(parts.at(i));
        GPU* gpu = dynamic_cast<GPU*>(parts.at(i));
        Speaker* speak = dynamic_cast<Speaker*>(parts.at(i));
        Motherboard* motherboard = dynamic_cast<Motherboard*>(parts.at(i));

        // check if the dynamic cast was successful and call the appropriate getter functions
        if (cpu) {
            cout << "----" << cpu->Getname() << " (CPU)" << "----" << endl;
            cout << "Price: $" << cpu->Getprice() << endl;
            cout << "Power Rating: " << cpu->Getpowerrating() << "W" << endl;
            cout << "Clock Speed: " << cpu->Getclockspeed() << "GHz" << endl;
            cout << "Core Count: " << cpu->Getnofcores() << endl;
        }
        else if (gpu) {
            cout << "----" << gpu->Getname() << " (GPU)" << "----" << endl;
            cout << "Price: $" << gpu->Getprice() << endl;
            cout << "Power Rating: " << gpu->Getpowerrating() << "W" << endl;
            cout << "Graphics Memory: " << gpu->Getmemorysize() << "GB" << endl;
            cout << "Clock Speed: " << gpu->Getclockspeed() << "MHz" << endl;
            cout << "No. of HDMI ports: " << gpu->Gethdmiports() << endl;
            cout << "No. of DVI ports: " << gpu->Getdviports() << endl;
            cout << "No. of DispayPort ports: " << gpu->Getdisplayports() << endl;
        }
        else if (speak) {
            cout << "----" << speak->Getname() << " (Speakers)" << "----" << endl;
            cout << "Price: $" << speak->Getprice() << endl;
            cout << "Power Rating: " << speak->Getpowerrating() << "W" << endl;
            cout << "Driver size: " << speak->GetdriverSize() << "Inches" << endl;
            cout << "Subwoofer: " << speak->Getsubwoofer() << endl;
        }
        else if (motherboard) {
            cout << "----" << motherboard->Getname() << " (Motherboard)" << "----" << endl;
            cout << "Price: $" << motherboard->Getprice() << endl;
            cout << "Power Rating: " << motherboard->Getpowerrating() << "W" << endl;
            cout << "Number of USB Ports: " << motherboard->Getnofusbports() << endl;
            cout << "Socket Type: " << motherboard->Getsockettype() << endl;
            cout << "Number of RAM Slots: " << motherboard->Getramslots() << endl;
            cout << "RAM Generation: " << motherboard->Getramgen() << endl;
        }
    }
    cout << "-----------------------------------------------" << endl;
}

// This function sorts the parts vector in descending order of their price
void PC::Sortbypartprice() {
    sort(parts.begin(), parts.end(), [](Part* a, Part* b) {
        return a->Getprice() > b->Getprice(); // Compare the prices of two parts and return true if the price of the first part is greater than that of the second
    });
}

// This function sorts the parts vector in ascending order of their name
void PC::Sortbyname() {
    sort(parts.begin(), parts.end(), [](Part* part1, Part* part2) {
        return part1->Getname() < part2->Getname(); // Compare the names of two parts and return true if the name of the first part comes before that of the second in alphabetical order
    });
}

// This function sorts the parts vector in ascending order of their power rating
void PC::Sortbypowerrating() {
    sort(parts.begin(), parts.end(), [](Part* a, Part* b) {
        return a->Getpowerrating() < b->Getpowerrating(); // Compare the power ratings of two parts and return true if the power rating of the first part is less than that of the second
    });
}

// This function finds a part by name and displays its details
Part* PC::Findpart(const string& name) const {
    auto it = find_if(parts.begin(), parts.end(), [&name](Part* p) { return p->Getname() == name; }); // Use the find_if algorithm to search for a part by name
    if (it != parts.end()) {
        cout << "Found part: ";
        (*it)->display(); // If the part is found, display its details using the display method of the base class
        return *it; // Return the pointer to the found part
    } else {
        cout << "Part not found" << endl;
        return nullptr; // Return a null pointer if the part is not found
    }
}

void PC::SavePC(string filename) {
    ofstream os(filename);
    if (os.is_open()) {
            cout << "file opened" << endl;
        os << totalpower << '\n';
        os << nofcomponants << '\n';
        os << psucompatible << '\n';
        os << calculatepower << '\n';
        os << parts.size() << '\n'; // save the number of parts
        cout << "PC info saved" << endl;

        for (auto p : parts) { // loop through the parts and save them
        p->save(os);
        }
        cout << "Part info saved" << endl;
        os.close();
        cout << "PC saved to " << filename << '\n';
    } else {
        cerr << "Error: Unable to open file " << filename << '\n';
    }
}

void PC::LoadPC(string filename) {
    ifstream is(filename);
    if (is.is_open()) {
        // variables to hold PC data
        int num_parts = 0;
        int part_index = 0;

        // read in PC data
        is >> totalpower;
        is >> nofcomponants;
        is >> psucompatible;
        is >> calculatepower;
        is >> num_parts;

        cout << "num_parts = " << num_parts << '\n'; // print the value of num_parts


        // read in part data
        while (part_index < num_parts && is.good()) {
            string part_type;
            getline(is, part_type);

            if (part_type == "CPU") {
                CPU* cpu = new CPU;
                cpu->load(is);
                parts.push_back(cpu);
                part_index++;

            } else if (part_type == "GPU") {
                GPU* gpu = new GPU;
                gpu->load(is);
                parts.push_back(gpu);
                part_index++;

            } else if (part_type == "Motherboard") {
                Motherboard* mobo = new Motherboard;
                mobo->load(is);
                parts.push_back(mobo);
                part_index++;

            } else if (part_type == "Speakers") {
                Speaker* speak = new Speaker;
                speak->load(is);
                parts.push_back(speak);
                part_index++;

            } else {
                cerr << "Unknown part type: " << part_type << '\n';

            }
        }
        is.close();
        cout << "PC loaded from " << filename << '\n';
    } else {
        cerr << "Error: Unable to open file " << filename << '\n';
    }
}

PC& PC::operator=(const PC& other) {
    if (this != &other) {
        // Perform deep copy of parts vector
        for (auto part : parts) {
            delete part;
        }
        parts.clear();
        for (auto part : other.parts) {
            parts.push_back(new Part(*part));
        }

        // Copy other member variables
        totalpower = other.totalpower;
        psucompatible = other.psucompatible;
        nofcomponants = other.nofcomponants;
    }
    return*this;
}


/*#include <string>
#include <iostream>
#include "PC.h"
#include "CPU.h"
#include "GPU.h"
#include "Motherboard.h"
#include "Speakers.h"
#include <algorithm>
using namespace std;
///CONSTRUCTOR
PC::PC() {
    // Set default values
    totalpower = 0;
    nofcomponants = 0;
    psucompatible = true;
    calculatepower = 0;
    // Dynamically allocate the parts array
    parts = new Part*[nofcomponants];
    cout << "Default PC constructed" << endl;
}

void PC::Addpart(Part* val) {
    // Increase the size of the dynamically allocated array by 1
    Part** newParts = new Part*[nofcomponants + 1];
    // Copy over the old array elements into the new array
    for (int i = 0; i < nofcomponants; i++) {
        newParts[i] = parts[i];
    }
    // Add the new part to the end of the new array
    newParts[nofcomponants] = val;
    // Deallocate the old array
    delete[] parts;
    // Point the parts pointer to the new array
    parts = newParts;
    // Increment the number of components and calculate the new power
    nofcomponants++;
    totalpower = calculatepower;
    cout << "Part added" << endl;
}
void PC::Removepart(int index) {
    // Check if the index is valid
    if (index < 0 || index >= nofcomponants) {
        cout << "Invalid index" << endl;
        return;
    }
    // Create a new array with one less element
    Part** newParts = new Part*[nofcomponants - 1];
    // Copy over the old array elements into the new array up to the index
    for (int i = 0; i < index; i++) {
        newParts[i] = parts[i];
    }
    // Copy over the old array elements into the new array after the index
    for (int i = index + 1; i < nofcomponants; i++) {
        newParts[i - 1] = parts[i];
    }
    // Delete the old array element at the given index
    delete parts[index];
    // Deallocate the old array
    delete[] parts;
    // Point the parts pointer to the new array
    parts = newParts;
    // Decrement the number of components and calculate the new power
    nofcomponants--;
    totalpower = calculatepower;
    cout << "Part removed" << endl;
}
void PC::Displayparts() const {
    cout << "-----------------Displaying Parts--------------" << endl;
    for (int i = 0; i < nofcomponants; i++) {
        cout << i + 1 << ". ";

        // dynamically cast each Part object to its appropriate child class
        CPU* cpu = dynamic_cast<CPU*>(*(parts + i));
        GPU* gpu = dynamic_cast<GPU*>(*(parts + i));
        Speaker* speak = dynamic_cast<Speaker*>(*(parts + i));
        Motherboard* motherboard = dynamic_cast<Motherboard*>(*(parts + i));


        // check if the dynamic cast was successful and call the appropriate getter functions
        if (cpu) {
            cout << "----" << cpu->Getname() << " (CPU)" << "----" << endl;
            cout << "Price: $" << cpu->Getprice() << endl;
            cout << "Power Rating: " << cpu->Getpowerrating() << "W" << endl;
            cout << "Clock Speed: " << cpu->Getclockspeed() << "GHz" << endl;
            cout << "Core Count: " << cpu->Getnofcores() << endl;
        }
        else if (gpu) {
            cout << "----" << gpu->Getname() << " (GPU)" << "----" << endl;
            cout << "Price: $" << gpu->Getprice() << endl;
            cout << "Power Rating: " << gpu->Getpowerrating() << "W" << endl;
            cout << "Graphics Memory: " << gpu->Getmemorysize() << "GB" << endl;
            cout << "Clock Speed: " << gpu->Getclockspeed() << "MHz" << endl;
            cout << "No. of HDMI ports: " << gpu->Gethdmiports() << endl;
            cout << "No. of DVI ports: " << gpu->Getdviports() << endl;
            cout << "No. of DispayPort ports: " << gpu->Getdisplayports() << endl;
        }
        else if (speak) {
            cout << "----" << speak->Getname() << " (Speakers)" << "----" << endl;
            cout << "Price: $" << speak->Getprice() << endl;
            cout << "Power Rating: " << speak->Getpowerrating() << "W" << endl;
            cout << "Driver size: " << speak->GetdriverSize() << "Inches" << endl;
            cout << "Subwoofer: " << speak->Getsubwoofer() << endl;
        }
        else if (motherboard) {
            cout << "----" << motherboard->Getname() << " (Motherboard)" << "----" << endl;
            cout << "Price: $" << motherboard->Getprice() << endl;
            cout << "Power Rating: " << motherboard->Getpowerrating() << "W" << endl;
            cout << "Number of USB Ports: " << motherboard->Getnofusbports() << endl;
            cout << "Socket Type: " << motherboard->Getsockettype() << endl;
            cout << "Number of RAM Slots: " << motherboard->Getramslots() << endl;
            cout << "RAM Generation: " << motherboard->Getramgen() << endl;
        }
    }
    cout << "-----------------------------------------------" << endl;
}

// Sort the parts array in descending order of their price
void PC::Sortbypartprice() {
    sort(parts, parts + nofcomponants, [](Part* a, Part* b) {
        return a->Getprice() > b->Getprice();
    });
}

// Sort the parts array in ascending order of their name
void PC::Sortbyname() {
    sort(parts, parts + nofcomponants, [](Part* part1, Part* part2) {
        return part1->Getname() < part2->Getname();
    });
}

// Sort the parts array in ascending order of their power rating
void PC::Sortbypowerrating() {
    sort(parts, parts + nofcomponants, [](Part* a, Part* b) {
        return a->Getpowerrating() < b->Getpowerrating();
    });
}

// This function finds a part by name and returns a pointer to the found part. If the part is not found, it returns nullptr.
Part* PC::Findpart(const string& name) const {
    for (int i = 0; i < nofcomponants; i++) {
        if (parts[i]->Getname() == name) {
            return parts[i]; // If the part is found, return a pointer to the found part
        }
    }
    return nullptr; // If the part is not found, return nullptr
}
void PC::SavePC(string filename) {
    ofstream os(filename);
    if (os.is_open()) {
            cout << "file opened" << endl;
        os << totalpower << '\n';
        os << nofcomponants << '\n';
        os << psucompatible << '\n';
        os << calculatepower << '\n';
        os << parts.size() << '\n'; // save the number of parts
        cout << "PC info saved" << endl;

        for (auto p : parts) { // loop through the parts and save them
        p->save(os);
        }
        cout << "Part info saved" << endl;

        os.close();
        cout << "PC saved to " << filename << '\n';
    } else {
        cerr << "Error: Unable to open file " << filename << '\n';
    }
}

void PC::LoadPC(string filename) {
    ifstream is(filename);
    if (is.is_open()) {
        // variables to hold PC data
        int num_parts = 0;
        int part_index = 0;
        // read in PC data
        is >> totalpower;
        is >> nofcomponants;
        is >> psucompatible;
        is >> calculatepower;
        is >> num_parts;
        cout << "num_parts = " << num_parts << '\n'; // print the value of num_parts
        // read in part data
        while (part_index < num_parts && is.good()) {
            string part_type;
            getline(is, part_type);

            if (part_type == "CPU") {
                CPU* cpu = new CPU;
                cpu->load(is);
                parts.push_back(cpu);
                part_index++;

            } else if (part_type == "GPU") {
                GPU* gpu = new GPU;
                gpu->load(is);
                parts.push_back(gpu);
                part_index++;

            } else if (part_type == "Motherboard") {
                Motherboard* mobo = new Motherboard;
                mobo->load(is);
                parts.push_back(mobo);
                part_index++;

            } else if (part_type == "Speakers") {
                Speaker* speak = new Speaker;
                speak->load(is);
                parts.push_back(speak);
                part_index++;

            } else {
                cerr << "Unknown part type: " << part_type << '\n';
            }
        }
        is.close();
        cout << "PC loaded from " << filename << '\n';

    } else {
        cerr << "Error: Unable to open file " << filename << '\n';
    }
}

PC& PC::operator=(const PC& other) {
    if (this != &other) { // check for self-assignment
        // Copy other member variables
        totalpower = other.totalpower;
        psucompatible = other.psucompatible;
        nofcomponants = other.nofcomponants;
        // perform deep copy of parts vector
        if (parts != nullptr) {
            // free existing memory
            for (int i = 0; i < nofcomponants; i++) {
                delete parts[i];
            }
            delete [] parts;
        }
        nofcomponants = other.nofcomponants;
        if (nofcomponants > 0) {
            parts = new Part*[nofcomponants];
            for (int i = 0; i < nofcomponants; i++) {
                parts[i] = new Part(*other.parts[i]);
            }
        } else {
            parts = nullptr;
        }
    }
    return *this;
}

///DESTRUCTOR
PC::~PC(){
    for (int i = 0; i < nofcomponants; i++) {
        delete parts[i]; // free memory for all Part objects
    }
    delete[] parts; // delete the array
    cout << "PC Destroyed" << endl;
}
*/
/*#include <string>
#include <iostream>
#include "PC.h"
#include "CPU.h"
#include "GPU.h"
#include "Motherboard.h"
#include "Speakers.h"
#include <algorithm>
using namespace std;
///CONSTRUCTOR
PC::PC(){
    //setting default values
    totalpower = 0;
    nofcomponants = 0;
    psucompatible = true;
    calculatepower = 0;
    cout << "Default PC constructed"<< endl;
}
///DESTRUCTOR
PC::~PC(){
    for (Part* part : parts) {
        delete part; // free memory for all Part objects
    }
    parts.clear(); // remove all elements from the vector
    cout << "PC Destroyed" << endl;
}
void PC::Addpart(Part* val){
    //increase no of componants, add the part to the vector and increase total power by the power rating of the part
    nofcomponants++;
    parts.push_back(val);
    totalpower += val->Getpowerrating();
}
void PC::Removepart(int index){
    //decrease no of componants, remove part from the vector and decrease total power by the power rating of the part
    nofcomponants--;
    totalpower -= parts.at(index)->Getpowerrating();
    delete parts.at(index); // free memory for the removed Part object
    parts.erase(parts.begin() + index);
}
void PC::Displayparts() const {
    cout << "-----------------Displaying Parts--------------" << endl;
    for (int i = 0; i < nofcomponants; i++) {
        cout << i + 1 << ". ";

        // dynamically cast each Part object to its appropriate child class
        CPU* cpu = dynamic_cast<CPU*>(parts.at(i));
        GPU* gpu = dynamic_cast<GPU*>(parts.at(i));
        Speaker* speak = dynamic_cast<Speaker*>(parts.at(i));
        Motherboard* motherboard = dynamic_cast<Motherboard*>(parts.at(i));

        // check if the dynamic cast was successful and call the appropriate getter functions
        if (cpu) {
            cout << "----" << cpu->Getname() << " (CPU)" << "----" << endl;
            cout << "Price: $" << cpu->Getprice() << endl;
            cout << "Power Rating: " << cpu->Getpowerrating() << "W" << endl;
            cout << "Clock Speed: " << cpu->Getclockspeed() << "GHz" << endl;
            cout << "Core Count: " << cpu->Getnofcores() << endl;
        }
        else if (gpu) {
            cout << "----" << gpu->Getname() << " (GPU)" << "----" << endl;
            cout << "Price: $" << gpu->Getprice() << endl;
            cout << "Power Rating: " << gpu->Getpowerrating() << "W" << endl;
            cout << "Graphics Memory: " << gpu->Getmemorysize() << "GB" << endl;
            cout << "Clock Speed: " << gpu->Getclockspeed() << "MHz" << endl;
            cout << "No. of HDMI ports: " << gpu->Gethdmiports() << endl;
            cout << "No. of DVI ports: " << gpu->Getdviports() << endl;
            cout << "No. of DispayPort ports: " << gpu->Getdisplayports() << endl;
        }
        else if (speak) {
            cout << "----" << speak->Getname() << " (Speakers)" << "----" << endl;
            cout << "Price: $" << speak->Getprice() << endl;
            cout << "Power Rating: " << speak->Getpowerrating() << "W" << endl;
            cout << "Driver size: " << speak->GetdriverSize() << "Inches" << endl;
            cout << "Subwoofer: " << speak->Getsubwoofer() << endl;
        }
        else if (motherboard) {
            cout << "----" << motherboard->Getname() << " (Motherboard)" << "----" << endl;
            cout << "Price: $" << motherboard->Getprice() << endl;
            cout << "Power Rating: " << motherboard->Getpowerrating() << "W" << endl;
            cout << "Number of USB Ports: " << motherboard->Getnofusbports() << endl;
            cout << "Socket Type: " << motherboard->Getsockettype() << endl;
            cout << "Number of RAM Slots: " << motherboard->Getramslots() << endl;
            cout << "RAM Generation: " << motherboard->Getramgen() << endl;
        }
    }
    cout << "-----------------------------------------------" << endl;
}

// This function sorts the parts vector in descending order of their price
void PC::Sortbypartprice() {
    sort(parts.begin(), parts.end(), [](Part* a, Part* b) {
        return a->Getprice() > b->Getprice(); // Compare the prices of two parts and return true if the price of the first part is greater than that of the second
    });
}

// This function sorts the parts vector in ascending order of their name
void PC::Sortbyname() {
    sort(parts.begin(), parts.end(), [](Part* part1, Part* part2) {
        return part1->Getname() < part2->Getname(); // Compare the names of two parts and return true if the name of the first part comes before that of the second in alphabetical order
    });
}

// This function sorts the parts vector in ascending order of their power rating
void PC::Sortbypowerrating() {
    sort(parts.begin(), parts.end(), [](Part* a, Part* b) {
        return a->Getpowerrating() < b->Getpowerrating(); // Compare the power ratings of two parts and return true if the power rating of the first part is less than that of the second
    });
}

// This function finds a part by name and displays its details
Part* PC::Findpart(const string& name) const {
    auto it = find_if(parts.begin(), parts.end(), [&name](Part* p) { return p->Getname() == name; }); // Use the find_if algorithm to search for a part by name
    if (it != parts.end()) {
        cout << "Found part: ";
        (*it)->display(); // If the part is found, display its details using the display method of the base class
    } else {
        cout << "Part not found" << endl;
    }
}
//Overloaded equality operator
PC& PC::operator=(const PC& other) {
    if (this != &other) {
        // Perform deep copy of parts vector
        for (auto part : parts) {
            delete part;
        }
        parts.clear();
        for (auto part : other.parts) {
            parts.push_back(new Part(*part));
        }

        // Copy other member variables
        totalpower = other.totalpower;
        psucompatible = other.psucompatible;
        nofcomponants = other.nofcomponants;
    }
    return *this;
}*/

