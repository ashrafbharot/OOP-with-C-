/*/***********************************************************************
// OOP244 Workshop # 9: tester program
//
// File: main.cpp
// Version 1.1
// Date: 11/20/2022
// Author: Razi Iqbal
// Description: This program demonstrates the concept of Polymorphism
// using an example of Student and Graduate.
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
// Fardad          2023-11-02       review
// Fardad          2023-11-21       added namespace sdds
/////////////////////////////////////////////////////////////////
***********************************************************************/
/* Name: MOHAMED ASHRAF BHAROT DATE: 2023-11-22*/

#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstring>
#include"Student.h"

using namespace std;

    void Student::clear()
    {
        m_name = nullptr;
        m_age = 0;
    }

    void Student::setName(const char* name)
    {
        if (m_name != nullptr)
        {
            delete[] m_name;
            clear();
        }

        if (name != nullptr)
        {
            m_name = new char[strlen(name) + 1];
            strcpy(m_name, name);
        }
        else 
        {
            clear();
        }
    }

    Student::Student()
    {
        clear();
    }

    Student::Student(const char* name, int age)
    {
        clear();
        setName(name);
        m_age = age;
    }

    Student::Student(const Student& src) 
    {
        clear();
        *this = src;
    }

    Student& Student::operator=(const Student& src) 
    {
        if (this != &src)
        {
            setName(src.m_name);
            m_age = src.m_age;
        }
        else
        {
            clear();
        }

        return *this;
    }

    Student::~Student()
    {
        delete[] m_name;
        clear();
    }

    void Student::display() const 
    {
        if (m_name != nullptr && m_age > 0) 
        {
            cout << "Name: " << m_name << endl;
            cout << "Age: " << m_age << endl;
        }
    }