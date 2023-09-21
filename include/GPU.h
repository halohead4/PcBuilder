#ifndef GPU_H
#define GPU_H
#include <iostream>
#include "Part.h"
#include <string>
using namespace std;
class GPU : public Part{
    public:
        GPU(); // Default constructor of the GPU class.
        GPU(string a, int b, int c, int d, int e, int f, int g, int h); // Overloaded constructor of the GPU class.
        virtual ~GPU(); // Virtual destructor of the GPU class.
        int Getmemorysize() { return memorysize; } // Getting the memory size of the GPU.
        void Setmemorysize(int val) { memorysize = val; } // Setting the memory size of the GPU.
        int Gethdmiports() { return hdmiports; } // Getting the number of HDMI ports in the GPU.
        void Sethdmiports(int val) { hdmiports = val; } // Setting the number of HDMI ports in the GPU.
        int Getdviports() { return dviports; } // Getting the number of DVI ports in the GPU.
        void Setdviports(int val) { dviports = val; } // Setting the number of DVI ports in the GPU.
        int Getdisplayports() { return displayports; } // Getting the number of display ports in the GPU.
        void Setdisplayports(int val) { displayports = val; } // Setting the number of display ports in the GPU.
        int Getclockspeed() { return clockspeed; } // Getting the clock speed of the GPU.
        void Setclockspeed(int val) { clockspeed = val; } // Setting the clock speed of the GPU.
        void save(std::ostream& os) const;
        void load(std::ifstream& is);
    protected:
    private:
        int memorysize; // The memory size of the GPU.
        int hdmiports; // The number of HDMI ports in the GPU.
        int dviports; // The number of DVI ports in the GPU.
        int displayports; // The number of display ports in the GPU.
        int clockspeed; // The clock speed of the GPU.
};
#endif // GPU_H
