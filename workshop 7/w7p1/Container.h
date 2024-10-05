#pragma once
// Workshop #7:
// // Description:
// This file tests the lab section of your workshop
// Name: MOHAMED ASHRAF BHAROT  DATE:2023-11-12 
///////////////////////////////////////////////////

#ifndef CONTAINER_H
#define CONTAINER_H
#include <iostream>
#include <cstring>

using namespace std;
namespace sdds {
    // Declaration of the Container class
    class Container {
    private:
        char Description[50];
        int Capacity;
        int Volume;
        bool Valid_Container;

    protected:
        // Protected member functions for internals use
        int volume();
        void setEmpty();
        int capacity();

    public:
        // Public member functions and contructors for the Container class
        Container(const char* Content, int Capacity, int Content_volume = 0);
        int operator -= (int value);
        int operator += (int value);
        bool valid();
        void clear(int Capacity, const char* Content);
        ostream& print(ostream& out);
        istream& read(istream& in);

        // Friend functions for stream operators
        friend ostream& operator << (ostream& out, Container& C) {
            return C.print(out);
        }
        friend istream& operator >> (istream& in, Container& C) {
            return C.read(in);
        }
    };
}

#endif // CONTAINER_H