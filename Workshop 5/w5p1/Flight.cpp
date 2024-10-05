/***********************************************************************
// OOP244 Workshop #5 lab (part 1): tester program
//
// File  main.cpp
// Version 1.0
// Author   Asam Gulaid, revised by Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name: MOHAMED ASHRAF BHAROT     Date:2023-10-12      Reason
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "Flight.h"

using namespace std;

namespace sdds {

    void Flight::emptyPlane() {
        m_passengers = 0;
        m_fuel = 0;
        strcpy(m_title, "EmptyPlane");
    }



    Flight::Flight() {
        emptyPlane();
    }

    Flight::Flight(int passengers, double fuel, const char* title) {
        emptyPlane();
        if (passengers > 0 && passengers <= Boen747Capacity && fuel >= 0 &&
            fuel <= FuelTankCapacity) {
            m_passengers = passengers;
            m_fuel = fuel;
            strcpy(m_title, title);
        }
    }

    std::ostream& Flight::display() const {

        if (*this) {
            cout << " Flight  |  Ready to Depart";
            cout << " ";
            cout.width(10);
            cout << std::string(*this);
            cout << " | ";
            cout << "Pass: ";
            cout.width(10);
            cout << int(*this);
            cout << " | ";
            cout.width(12);
            cout.precision(2);
            cout.setf(ios::right);
            cout.setf(ios::fixed);
            cout << double(*this);
            cout.unsetf(ios::right);
            cout << " Liters";
        }
        else if (~*this) {
            cout << " Flight  |  Empty Plane    ";
        }
        else {
            cout << " Flight  |  Low Fuel       ";
            cout << " ";
            cout.width(10);
            cout << (const char*)(*this);
            cout << " | ";
            cout << "Pass: ";
            cout.width(10);
            cout << int(*this);
            cout << " | ";
            cout.width(12);
            cout.precision(2);
            cout.setf(ios::right);
            cout.setf(ios::fixed);
            cout << double(*this);
            cout.unsetf(ios::right);
            cout << " Liters";
        }
        return cout;
    }
    Flight::operator bool() const
    {
        bool isready = false;
        double temp = m_passengers * 600;
        if (m_passengers > 0 && m_fuel >= temp)
        {
            isready = true;
        }
        return isready;
    }
    Flight::operator int() const
    {
        return m_passengers;
    }
    Flight::operator double() const
    {
        return m_fuel;
    }
    Flight::operator const char* () const
    {
        return m_title;
    }
    int Flight::getpassengers() const
    {
        return m_passengers;
    }

    bool operator ~(const Flight& f1)
    {
        bool paszero = false;
        if (f1.getpassengers() == 0)
        {
            paszero = true;
        }
        return paszero;
    }
    Flight& Flight::operator =(Flight& f2)
    {
        m_fuel += f2.m_fuel;
        m_passengers += f2.m_passengers;
        strcpy(m_title, f2.m_title);
        f2.m_passengers = 0;
        f2.m_fuel = 0;
        strcpy(f2.m_title, "EmptyPlane");
        return *this;
    }
    Flight& Flight::operator =(int pass)
    {
        if (pass > 0 && pass <= 388)
        {
            m_passengers = pass;
        }
        return *this;
    }

    Flight& Flight::operator =(double gas)
    {
        if (gas > 0 && gas <= 238840)
        {
            m_fuel = gas;
        }
        return *this;

    }
    Flight& Flight::operator +=(double gas)
    {
        if (gas < 0 || m_fuel == 238840)
        {

        }
        else
        {
            if (m_fuel + gas > 238840)
            {
                m_fuel = 238840;
            }
            else
            {
                m_fuel += gas;
            }

        }
        return *this;
    }
    Flight& Flight::operator +=(int pas)
    {
        if (pas < 0 || m_passengers == 388)
        {

        }
        else
        {
            if (m_passengers + pas > 388)
            {
                m_passengers = 388;
            }
            else
            {
                m_passengers += pas;
            }

        }
        return *this;
    }
    Flight& Flight::operator -=(double ful)
    {
        if (ful < 0)
        {

        }
        else
        {
            if (m_fuel - ful < 0)
            {
                m_fuel = 0;
            }
            else
            {
                m_fuel -= ful;
            }
        }
        return *this;
    }
    Flight& Flight::operator -=(int people)
    {
        if (people < 0)
        {

        }
        else
        {
            if (m_passengers - people < 0)
            {
                m_passengers = 0;
            }
            else
            {
                m_passengers -= people;
            }
        }
        return *this;
    }
    Flight& Flight::operator <<(Flight& right)
    {
        if (right.getpassengers() > 0) {
            m_passengers += right.m_passengers;
            if (m_passengers > 388) {
                right.m_passengers = m_passengers % 388;
                m_passengers -= right.m_passengers;
            }
        }
        return *this;
    }
    Flight& Flight::operator >>(Flight& right)
    {
        if (m_passengers > 0) {
            right.m_passengers += m_passengers;
            if (right.m_passengers > 388) {
                m_passengers = right.m_passengers % 388;
                right.m_passengers -= m_passengers;
            }
        }
        return *this;
    }
    bool Flight::isTrueFlight() const
    {
        bool istrue = false;
        if (m_passengers >= 0 && m_passengers <= 388)
        {
            istrue = true;
        }
        return istrue;
    }

    int operator +(const Flight& f1, const Flight& f2)

    {
        int passe = 0;
        if (f1.isTrueFlight() && f2.isTrueFlight())
        {
            passe = f1.getpassengers() + f2.getpassengers();
        }


        return passe;
    }
    int operator +=(int& plus, const Flight& f1)
    {

        plus = plus + f1.getpassengers();
        return plus;
    }




}
