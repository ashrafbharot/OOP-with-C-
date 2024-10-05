/***********************************************************************
// OOP244 Workshop #2 DIY (part 2):
//
// File  Population.h
// Version 1.0
// Author   Fardad Soleimanloo
// Description
//   To completed by students
// Revision History
// -----------------------------------------------------------
// Name: MOHAMED ASHRAF BHAROT        Date 2023-09-23            Reason
***********************************************************************/
#ifndef SDDS_POPULATION_H_
#define SDDS_POPULATION_H_

namespace sdds {
    struct Population {
        char* postalCode;
        int population;
    };

    void sort();

    int totalPopulation();

    bool getPostalCode(char* postal_code_prefix);

    bool load(Population& record);
    bool load(const char* filename);
    bool load(const char* filename, const char* partial_postal_code_prefix);

    // returns true of the cstring starts with subString
    bool startsWith(const char* cString, const char* subString);

    void display(const int count, const Population& record);
    void display();
    void deallocateMemory();


}
#endif // SDDS_POPULATION_H_