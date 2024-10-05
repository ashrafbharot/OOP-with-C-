/***********************************************************************
// OOP244 Workshop #5 DIY (part 2): tester program
//
// File  Portfolio.h
// Version 1.0
// Author   Asam Gulaid, revised by Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name: MOHAMED ASHRAF BHAROT      Date: 2023-10-15           Reason
// -----------------------------------------------------------*/
#ifndef SDDS_Portfolio_H_
#define SDDS_Portfolio_H_
#include <iostream>

using namespace std;

namespace sdds {

    class Portfolio {
        double m_value = 0;
        char m_stock[16];
        char m_type;

    public:
        Portfolio();
        Portfolio(double value, const char* stock, char type);
        void dispPortfolio() const;
        void emptyPortfolio();
        std::ostream& display() const;
        //Casting Portfolio to double type
        operator double() const;
        //Casting Portfolio to C-String type
        operator const char* () const;
        //Casting Portfolio to char type
        operator char() const;
        //Casting Portfolio to boolean type
        operator bool() const;
        //Overloaded operator to add the received value to the class
        Portfolio& operator +=(double value);
        //Overloaded operator to subtract the received value from the Portfolio class
        Portfolio& operator -= (double value);
        //Returns true if m_value is negative
        bool operator ~ () const;
        //Overloaded operator to move m_value from Portfolio on right to left
        Portfolio& operator <<(Portfolio& source);
        //Overloaded operator to move m_value from Portfolio on left to right
        Portfolio& operator >>(Portfolio& source);
        //checking the validity of the Portfolio object
        bool validPortfolio() const;
        //Customised function to get m_value
        double getM_value() const;
    };
    //Binary helper operator to return the sum of m_values received
    double operator +(const Portfolio& obj1, const Portfolio& obj2);
    //Helper function that returns a double value added with the m_value of the reference object
    double operator +=(double& value, const Portfolio& source);

}
#endif // SDDS_Portfolio_H_