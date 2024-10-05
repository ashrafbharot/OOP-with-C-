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


#ifndef SDDS_Lblshape_H_
#define SDDS_Lblshape_H_

#include "Shape.h"

namespace sdds
{
    class LblShape : public Shape
    {
        char* m_label = nullptr;
    protected:
        const char* label() const;
    public:
        LblShape() {}
        LblShape(const char* label);
        virtual ~LblShape();
        void getSpecs(std::istream& is);

        LblShape(const LblShape& src) = delete;
        LblShape& operator=(const LblShape& src) = delete;

    };
}
#endif