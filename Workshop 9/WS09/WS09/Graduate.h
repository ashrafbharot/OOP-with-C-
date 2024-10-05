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

#ifndef SDDS_GRADUATE_H
#define SDDS_GRADUATE_H

#include"Student.h"

    class Graduate : public Student
    {
        char* m_supervisor;
        char* m_thesisTitle;

        //Private methods
        void setThesisTitle(const char* thesisTitle);
        void setSupervisor(const char* supervisor);

        void clear();
    public:
        Graduate();
        Graduate(const char* name, int age, const char* supervisor, const char* thesisTitle);

        // Rule of three
        Graduate(const Graduate& src);
        Graduate& operator=(const Graduate& src);
        ~Graduate();

        void display() const;
    };

#endif // !SDDS_GRADUATE_H