/***********************************************************************
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
#include"Graduate.h"

using namespace std;

void Graduate::setThesisTitle(const char* thesisTitle)
{
    if (m_thesisTitle != nullptr)
    {
        delete[] m_thesisTitle;
        m_thesisTitle = nullptr;
    }

    if (thesisTitle != nullptr)
    {
        m_thesisTitle = new char[strlen(thesisTitle) + 1];
        strcpy(m_thesisTitle, thesisTitle);
    }
    else
    {
        clear();
    }
}

void Graduate::setSupervisor(const char* supervisor)
{
    if (m_supervisor != nullptr)
    {
        delete[] m_supervisor;
        m_supervisor = nullptr;
    }

    if (supervisor != nullptr)
    {
        m_supervisor = new char[strlen(supervisor) + 1];
        strcpy(m_supervisor, supervisor);
    }
    else
    {
        clear();
    }
}

void Graduate::clear()
{
    m_supervisor = nullptr;
    m_thesisTitle = nullptr;
}

Graduate::Graduate() : Student()
{
    clear();
}

Graduate::Graduate(const char* name, int age, const char* thesisTitle, const char* supervisor) : Student(name, age)
{
    clear();
    setSupervisor(supervisor);
    setThesisTitle(thesisTitle);
}

Graduate::Graduate(const Graduate& src) : Student(src)
{
    clear();
    *this = src;
}

Graduate& Graduate::operator=(const Graduate& src)
{
    if (this != &src)
    {
        (Student&)*this = src;

        setSupervisor(src.m_supervisor);
        setThesisTitle(src.m_thesisTitle);
    }
    else
    {
        clear();
    }
    return *this;
}

Graduate::~Graduate()
{
    delete[] m_supervisor;
    delete[] m_thesisTitle;

    clear();
}

void Graduate::display() const
{
    Student::display();

    if (m_thesisTitle != nullptr && m_supervisor != nullptr)
    {
        cout << "Thesis Title: " << m_thesisTitle << endl;
        cout << "Supervisor: " << m_supervisor << endl;
        cout << "---------------------------------------------" << endl;
    }
}