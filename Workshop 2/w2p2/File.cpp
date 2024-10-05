/***********************************************************************
// OOP244 Workshop #2 DIY (part 2):
//
// File  File.cpp
// Version 1.0
// Author   Fardad Soleimanloo
// Description
//   To completed by students
// Revision History
// -----------------------------------------------------------
// Name:MOHAMED ASHRAF BHAROT  Date: 2023-09-24      Reason
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include <iostream>
#include "File.h"
#include "Population.h"

using namespace std;
namespace sdds {
    FILE* fptr;
    bool openFile(const char filename[]) {
        fptr = fopen(filename, "r");
        return fptr != NULL;
    }
    void closeFile() {
        if (fptr) fclose(fptr);
    }

    int numRecords() {
        int recs = 0;
        char ch;
        while (fscanf(fptr, "%c", &ch) == 1) {
            recs += (ch == '\n');
        }
        rewind(fptr);
        return recs;
    }

    int numRecords(const char* postalCodePrefix) {
        int recs = 0;
        char postalCode[MAX_POSTAL_CODE_LEN + 1];
        int population;
        while (fscanf(fptr, "%3s,%d\n", postalCode, &population) == 2) {
            if (startsWith(postalCode, postalCodePrefix)) {
                recs++;
            }
        }
        rewind(fptr);
        return recs;
    }

    bool read(char*& postalCode)
    {
        char temp[MAX_POSTAL_CODE_LEN + 1];
        bool success = fscanf(fptr, "%3s,", temp) == 1;
        if (success)
        {
            postalCode = new char[strlen(temp) + 1];
            strcpy(postalCode, temp);
        }
        return success;
    }

    bool read(int& population)
    {
        return fscanf(fptr, "%d\n", &population) == 1;
    }

    bool read(char*& postalCode, const char* partial_postal_code_prefix)
    {
        char temp[MAX_POSTAL_CODE_LEN + 1];
        bool success = fscanf(fptr, "%3s,", temp) == 1;
        if (success)
        {
            if (startsWith(temp, partial_postal_code_prefix))
            {
                postalCode = new char[strlen(temp) + 1];
                strcpy(postalCode, temp);
            }
            else
            {
                success = false;
            }
        }
        return success;
    }

}