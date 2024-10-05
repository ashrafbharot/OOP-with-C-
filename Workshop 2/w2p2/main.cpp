/***********************************************************************
// OOP244 Workshop #2 DIY (part 2): tester program
//
// File  main.cpp
// Version 1.0
// Author   Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name:MOHAMED ASHRAF BHAROT      Date: 2023-09-23      Reason
***********************************************************************/
#include "Population.h"
using namespace sdds;
int main() {
    if (load("PCpopulations.csv")) {
        display();
    }
    deallocateMemory();
    return 0;
}