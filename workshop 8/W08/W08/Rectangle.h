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


#ifndef SDDS_RECTANGLE_H_
#define SDDS_RECTANGLE_H_

#include "LblShape.h"

namespace sdds
{
    class Rectangle : public LblShape
    {
        unsigned int m_width{ 0 };
        unsigned int m_height{ 0 };
    public:
        Rectangle() {}
        Rectangle(const char* label, int width, int height);
        virtual ~Rectangle() {}

        void getSpecs(std::istream& is);
        void draw(std::ostream& os) const;
    };
}
#endif