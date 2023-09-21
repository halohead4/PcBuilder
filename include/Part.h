///Purely virtual class With M:1 relationship towards PC class
#ifndef PART_H
#define PART_H
#include <string>
#include <iostream>
using namespace std;
class PC; // Forward declaration of the PC class for the correct functioning of the M:1 relationship
class Part {
public:
    Part(); //default constructor
    virtual ~Part();
    bool operator==(const Part& other) const; //overloaded operator for equality
    bool operator!=(const Part& other) const; //overloaded operator for inequality
    bool operator<(const Part& other) const; //overloaded operator for less than
    bool operator>(const Part& other) const; //overloaded operator for greater than
    bool operator<=(const Part& other) const; //overloaded operator for less than or equal to
    bool operator>=(const Part& other) const; //overloaded operator for greater than or equal to
    friend ostream& operator<<(ostream& os, const Part& obj); //overloaded operator for output stream
    friend istream& operator>>(istream& is, Part& obj); //overloaded operator for input stream
    int Getprice() const { return price; } //getter for price
    void Setprice(int val) { price = val; } //setter for price
    int Getpowerrating() const { return powerrating; } //getter for power rating
    void Setpowerrating(int val) { powerrating = val; } //setter for power rating
    string Getname() const { return name; } //getter for name
    void Setname(string val) { name = val; } //setter for name
    virtual void display() const; //virtual function for displaying information about the part
    void SetPC(PC* pc) { parent_pc = pc; } //setter for parent PC
    PC* GetPC() const { return parent_pc; } //getter for parent PC
     virtual void save(std::ostream& os) const {
        os << "Part" << '\n'; // save the class name
        os << name << '\n';
        os << price << '\n';
        os << powerrating << '\n';
    }
protected:
private:
    int price; //price of the part
    int powerrating; //power rating of the part
    string name; //name of the part
    PC* parent_pc; //pointer to the parent PC object
};
#endif // PART_H



/*///Purely virtual class With M:1 relationship towards PC class
#ifndef PART_H
#define PART_H
#include <string>
#include <iostream>
using namespace std;
class PC; // Forward declaration of the PC class for the correct functioning of the M:1 relationship
class Part {
public:
    Part(); //default constructor
    virtual ~Part();
    bool operator==(const Part& other) const; //overloaded operator for equality
    bool operator!=(const Part& other) const; //overloaded operator for inequality
    bool operator<(const Part& other) const; //overloaded operator for less than
    bool operator>(const Part& other) const; //overloaded operator for greater than
    bool operator<=(const Part& other) const; //overloaded operator for less than or equal to
    bool operator>=(const Part& other) const; //overloaded operator for greater than or equal to
    friend ostream& operator<<(ostream& os, const Part& obj); //overloaded operator for output stream
    friend istream& operator>>(istream& is, Part& obj); //overloaded operator for input stream
    int Getprice() const { return price; } //getter for price
    void Setprice(int val) { price = val; } //setter for price
    int Getpowerrating() const { return powerrating; } //getter for power rating
    void Setpowerrating(int val) { powerrating = val; } //setter for power rating
    string Getname() const { return name; } //getter for name
    void Setname(string val) { name = val; } //setter for name
    virtual void display() const; //virtual function for displaying information about the part
    void SetPC(PC* pc) { parent_pc = pc; } //setter for parent PC
    PC* GetPC() const { return parent_pc; } //getter for parent PC
protected:
private:
    int price; //price of the part
    int powerrating; //power rating of the part
    string name; //name of the part
    PC* parent_pc; //pointer to the parent PC object
};
#endif // PART_H
*/
