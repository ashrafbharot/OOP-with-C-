/***********************************************************************
// OOP244 Workshop #2 DIY (part 2):
//
// File  Population.cpp
// Version 1.0
// Author   Fardad Soleimanloo
// Description
//   To completed by students
// Revision History
// -----------------------------------------------------------
// Name:MOHAMED ASHRAF BHAROT       Date  2023-09-23           Reason
***********************************************************************/
#include "Population.h"
#include "File.h"
#include <cstring>
#include <iostream>
using namespace std;
namespace sdds
{

    int noOfRec;
    Population* records;

    void sort()
    {
        int i, j;
        Population temp;
        for (i = noOfRec - 1; i > 0; i--)
        {
            for (j = 0; j < i; j++)
            {
                if (records[j].population > records[j + 1].population)
                {
                    temp = records[j];
                    records[j] = records[j + 1];
                    records[j + 1] = temp;
                }
            }
        }
    }

    int totalPopulation()
    {
        int i;
        int total = 0;
        for (i = 0; i < noOfRec; i++)
        {
            total += records[i].population;
        }
        return total;
    }

    bool getPostalCode(char* postal_code_prefix)
    {
        cout << "Population Report" << endl;
        cout << "-----------------" << endl;
        cout << "Enter postal code:" << endl << "> ";
        cin >> postal_code_prefix;

        return (strcmp(postal_code_prefix, "!") != 0);
    }

    // load reads one record from the file and loads it into the record argument
    bool load(Population& record)
    {
        bool readPostalOk = read(record.postalCode);
        bool readPopulationOk = read(record.population);
        return readPostalOk && readPopulationOk;
    }

    bool load(Population& record, const char* partial_postal_code_prefix)
    {
        bool readPostalOk = read(record.postalCode, partial_postal_code_prefix);
        bool readPopulationOk = read(record.population);
        return readPostalOk && readPopulationOk;
    }

    // load reads all the records from the file and loads them into the dynamically allocated array of postal codes.
    bool load(const char* filename)
    {
        bool ok = false;
        int i;
        if (!openFile(filename))
        {
            cout << "Could not open data file: " << filename << endl;
        }
        else
        {
            noOfRec = numRecords();
            records = new Population[noOfRec];
            for (i = 0; i < noOfRec; i++)
            {
                if (!load(records[i]))
                {
                    cout << "Error: incorrect number of records read; the data is possibly corrupted." << endl;
                    deallocateMemory();
                    return false;
                }
            }
            ok = true;
        }
        closeFile();
        return ok;
    }

    // load reads all the records from the file that start with prefix and loads them into the dynamically allocated array of postal codes.
    bool load(const char* filename, const char* partial_postal_code_prefix)
    {
        int noOfAllRec = 0;
        bool ok = false;
        int prefixedRecordsIndex = 0;
        int allRecordsIndex = 0;
        if (strcmp(partial_postal_code_prefix, "all") == 0)
        {
            return load(filename);
        }
        if (!openFile(filename))
        {
            cout << "Could not open data file: " << filename << endl;
        }
        else
        {
            noOfRec = numRecords(partial_postal_code_prefix);
            noOfAllRec = numRecords();
            records = new Population[noOfRec];

            while (allRecordsIndex < noOfAllRec && prefixedRecordsIndex < noOfRec)
            {
                if (load(records[prefixedRecordsIndex], partial_postal_code_prefix))
                {
                    prefixedRecordsIndex++;
                }
                allRecordsIndex++;
            }
            ok = true;

        }
        closeFile();
        return ok;
    }

    bool startsWith(const char* cstring, const char* subString)
    {
        return strstr(cstring, subString) == cstring;
    }

    void display(int count, Population& record)
    {
        cout << count + 1 << "- " << record.postalCode << ":  " << record.population << endl;
    }

    void display()
    {
        int i;
        int totalPop;
        sort();
        totalPop = totalPopulation();
        cout << "Postal Code: population" << endl;
        cout << "-------------------------" << endl;

        for (i = 0; i < noOfRec; i++)
        {
            display(i, records[i]);
        }
        cout << "-------------------------" << endl;
        cout << "Population of the listed areas: " << totalPop << endl << endl;
    }

    void deallocateMemory()
    {
        int i;
        for (i = 0; i < noOfRec; i++)
        {
            delete[] records[i].postalCode;
        }
        delete[] records;
    }

}