/***********************************************************************
// OOP244 Workshop #2 lab (part 1)
//
// File  Employee.cpp
// Version 1.0
// Author   Fardad Soleimanloo
// Description
//    To be completed by students
// Revision History
// -----------------------------------------------------------
// Name: MOHAMED ASHRAF BHAROT           Date: 2023-09-21          Reason
***********************************************************************/
#include <iostream>
#include "Employee.h"
#include "File.h"
#include <cstring>
using namespace std;
namespace sdds
{

    int noOfEmployees;
    Employee* employees;

    void sort()
    {
        int i, j;
        Employee temp;
        for (i = noOfEmployees - 1; i > 0; i--)
        {

            for (j = 0; j < i; j++)
            {
                if (employees[j].m_empNo > employees[j + 1].m_empNo)
                {
                    temp = employees[j];
                    employees[j] = employees[j + 1];
                    employees[j + 1] = temp;
                }
            }
        }
    }
    // TODO: Finish the implementation of the 1 arg load function which
    // reads one employee record from the file and loads it into the employee reference
    // argument
    bool load(Employee& employes)
    {
        // return the combined success result of the three read functions. These read
        // functions should set the properties of the reference argument of the load function
        bool ok = false;
        int check1 = read(employes.m_empNo);
        int check2 = read(employes.m_salary);
        int check3 = read(employes.m_name);

        if (check1 && check2 && check3)
        {
            ok = true;
        }

        return ok;
    }
    // TODO: Finish the implementation of the 0 arg load function
    bool load()
    {
        const char fileName[] = "employees.csv";
        if (!openFile(fileName))
        {
            cout << "Could not open data file: " << fileName << endl;
            return false;
        }

        noOfEmployees = noOfRecords();
        employees = new Employee[noOfEmployees];

        for (int i = 0; i < noOfEmployees; i++)
        {
            if (!load(employees[i]))
            {
                cout << "Error: incorrect number of records read; the data is possibly corrupted." << endl;
                closeFile();
                return false;
            }
        }

        closeFile();
        return true;
    }

    // TODO: Implementation for the display functions go here
    void display()
    {
        sort();
        Header();
        for (int i = 0; i < noOfEmployees; i++) {
            cout << i + 1 << "- ";
            Record(employees[i]);
        }
    };
    // TODO: Implementation for the deallocateMemory function goes here
    void Record(const Employee& employees) {
        cout << employees.m_empNo << ": " << employees.m_name << ", $" << (int)employees.m_salary << endl;
    }

    void deallocateMemory() {
        int i;
        if (employees != NULL) {
            for (i = 0; i < noOfEmployees; i++) {
                delete[] employees[i].m_name;
            }
            delete[] employees;
            employees = NULL;
        }
    };

    void Header() {
        cout << "Employee Salary report, sorted by employee number" << endl;
        cout << "no- Empno, Name, Salary" << endl;
        cout << "------------------------------------------------" << endl;
    };
}