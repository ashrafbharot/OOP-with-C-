#pragma once
// Workshop #7:
// // Description:
// This file tests the lab section of your workshop
// Name: MOHAMED ASHRAF BHAROT  DATE:2023-11-12 
///////////////////////////////////////////////////


#ifndef PACK_H
#define PACK_H
#include "Container.h"

using namespace sdds;
namespace sdds {
    // Declaration of the Pack class, a derived class from Container
    class Pack : public Container {
    private:
        int Unit_Size;
        int Size;
        int Number_Of_Units;

    public:
        // Constructor and member functions for Pack class
        Pack(const char* Content, int Size, int unitSize = 330, int NumberOfUnits = 0);
        int operator -= (int units);
        int operator += (int units);
        int size();
        int unit();
        int noOfUnits();
        void clear(int packSize, int unitSize, const char* content);
        ostream& print(ostream& out);
        istream& read(istream& in);

        // Friend functions for stream operators
        friend ostream& operator << (ostream& out, Pack& P) {
            return P.print(out);
        }
        friend istream& operator >> (istream& in, Pack& P) {
            return P.read(in);
        }
    };
}

#endif // PACK_H