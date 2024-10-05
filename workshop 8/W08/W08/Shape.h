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



#ifndef SDDS_SHAPE_H_
#define SDDS_SHAPE_H_

#include <iostream>

namespace sdds
{
    class Shape
    {
    public:
        virtual ~Shape() {}
        virtual void draw(std::ostream& os) const = 0;
        virtual void getSpecs(std::istream& is) = 0;
    };

    std::ostream& operator<<(std::ostream& os, const Shape& src);
    std::istream& operator>>(std::istream& is, Shape& src);
}

#endif