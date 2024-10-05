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

#ifndef SDDS_STUDENT_H
#define SDDS_STUDENT_H


    class Student
    {
        char* m_name;
        int m_age;

        // Private methods
        void clear();
        void setName(const char* name);
    public:
        Student();
        Student(const char* name, int age);

        // Rule of three
        Student(const Student& src);
        Student& operator=(const Student& src);
        virtual ~Student();

        void display() const;
    };

#endif // !SDDS_STUDENT_H
