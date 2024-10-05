/***********************************************************************
// OOP244 Workshop #8 lab (part 1): tester program
//
// File  main.cpp
// Version 1.0
// Author   Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name:MOHAMED ASHRAF BHAROT   Date:2023-11-19            Reason
***********************************************************************/

#include <iostream>

#include "Shape.h"

using namespace std;

namespace sdds
{
    ostream& operator<<(ostream& os, const Shape& src)
    {
        src.draw(os);
        return os;
    }


    istream& operator>>(istream& is, Shape& src)
    {
        src.getSpecs(is);
        return is;
    }
}