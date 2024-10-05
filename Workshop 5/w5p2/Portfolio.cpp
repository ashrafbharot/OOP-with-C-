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
#define _CRT_SECURE_NO_WARNINGS

#include "Portfolio.h"
#include <iostream>
#include <cstring>
using namespace std;
namespace sdds {

    //Already implemented functions
    Portfolio::Portfolio() {
        emptyPortfolio();
    }

    void Portfolio::emptyPortfolio()
    {
        m_value = 0;
        m_stock[0] = 0;
        m_type = 'E';
    }
    Portfolio::Portfolio(double value, const char* stock, char type) {
        emptyPortfolio();
        if (value >= 0 && (type == 'V' || type == 'G' || type == 'I')) {
            m_value = value;
            m_type = type;
            strcpy(m_stock, stock);
        }
    }

    void Portfolio::dispPortfolio() const {
        cout << " ";
        cout.width(10);
        cout << (const char*)(*this);
        cout << " | ";
        cout << "Value: ";
        cout.width(10);
        cout << double(*this);
        cout << " | ";
        cout << " Type: ";
        cout << char(*this);
    }
    std::ostream& Portfolio::display() const {

        if (~*this) {
            cout << " Portfolio  |  Bad-NG |";
            dispPortfolio();
        }
        else if (*this) {
            cout << " Portfolio  |  Active |";
            dispPortfolio();

        }
        else {
            cout << " Portfolio  |  EMPTY  |";
            dispPortfolio();
        }
        return cout;
    }
    //Casting Portfolio to double type
    Portfolio::operator double() const
    {
        return m_value;
    }
    //Casting Portfolio to C-String type
    Portfolio::operator const char* () const
    {
        return m_stock;
    }
    //Casting Portfolio to char type
    Portfolio::operator char() const
    {
        return m_type;
    }
    //Casting Portfolio to boolean type
    Portfolio::operator bool() const
    {
        return (m_type == 'G' || m_type == 'V' || m_type == 'I');
    }
    //Overloaded operator to add the received value to the class
    Portfolio& Portfolio::operator+=(double floatValue)
    {
        if ((floatValue > 0) && (m_type == 'G' || m_type == 'V' || m_type == 'I'))
        {
            m_value += floatValue;
        }

        return *this;
    }
    //Overloaded operator to subtract the received value from the Portfolio class
    Portfolio& Portfolio::operator-=(double floatValue)
    {

        if ((floatValue > 0) && (m_type == 'G' || m_type == 'V' || m_type == 'I'))
        {
            m_value -= floatValue;
        }

        return *this;
    }
    //Returns true if m_value is negative
    bool Portfolio::operator~() const
    {
        return (m_value < 0);

    }
    //Overloaded operator to move m_value from Portfolio on right to left
    Portfolio& Portfolio::operator <<(Portfolio& source)
    {
        if (this != &source && this->validPortfolio() && source.validPortfolio())//checking if both objects are valid and are not same
        {
            m_value += source.m_value;
            source.m_value = 0;
            source.m_stock[0] = 0;
            source.m_type = 'E';
        }


        return *this;
    }
    //Overloaded operator to move m_value from Portfolio on left to right
    Portfolio& Portfolio::operator >>(Portfolio& source)
    {
        if (this != &source && this && source)
        {
            source.m_value += m_value;
            m_value = 0;
            m_stock[0] = 0;
            m_type = 'E';
        }
        return *this;
    }
    //Customised function to get m_value
    double Portfolio::getM_value() const
    {
        return m_value;

    }
    //Binary helper operator to return the sum of m_values received
    double operator+(const Portfolio& obj1, const Portfolio& obj2)
    {
        double sumValue = obj1.getM_value() + obj2.getM_value();
        return sumValue;
    }
    //Helper function that returns a double value added with the m_value of the reference object
    double operator +=(double& value, const Portfolio& source)
    {
        value += source.getM_value();
        return value;
    }
    //checking the validity of the Portfolio object
    bool Portfolio::validPortfolio() const
    {
        bool validity = false;
        if ((m_value >= 0) && (m_type == 'G' || m_type == 'V' || m_type == 'I'))
        {
            validity = true;
        }
        return validity;
    }
}