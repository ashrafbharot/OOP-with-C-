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

#ifndef SDDS_LINE_H_
#define SDDS_LINE_H_

#include "LblShape.h"

namespace sdds
{
    class Line : public LblShape
    {
        unsigned int m_length{ 0 };
    public:
        Line() {}
        Line(const char* label, int length);
        virtual ~Line() {}

        void getSpecs(std::istream& is);
        void draw(std::ostream& os) const;
    };
}
#endif