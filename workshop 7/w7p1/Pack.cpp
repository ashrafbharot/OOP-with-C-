// Workshop #7:
// // Description:
// This file tests the lab section of your workshop
// Name: MOHAMED ASHRAF BHAROT  DATE:2023-11-12 
///////////////////////////////////////////////////

#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <string>
#include "Pack.h"

using namespace std;
namespace sdds {

    // Constructor for Pack class
    Pack::Pack(const char* Content, int Size, int unitSize, int NumberOfUnits)
        :Container(Content, Size* unitSize, unitSize* NumberOfUnits) {
        this->Size = Size;
        this->Unit_Size = unitSize;
        this->Number_Of_Units = NumberOfUnits;
    }

    // Overloaded -= operator for subtracting units from pack
    int Pack::operator -= (int units) {
        // Call the Container class's operator and adjust number of units
        int result = Container::operator-=(units * Unit_Size) / Unit_Size;
        this->Number_Of_Units -= result;
        return result;
    }

    // Overloaded += operator for adding units to the pack
    int Pack::operator += (int units) {
        // Call the Container class's operator and adjust the number of units
        int result = Container::operator+=(units * Unit_Size) / Unit_Size;
        this->Number_Of_Units += result;
        return result;
    }

    // Getter function for the size of the pack
    int Pack::size() {
        return Size;
    }

    // Getter function for the unit size of the pack
    int Pack::unit() {
        return Unit_Size;
    }

    // Getter function for the number of units in the pack
    int Pack::noOfUnits() {
        return Number_Of_Units;
    }

    // To clear the pack with a new size, unit size, and content
    void Pack::clear(int packSize, int unitSize, const char* content) {
        if (unitSize > 0) {
            // Calculate the total size of the pack
            int packunit = packSize * unitSize;
            Size = packSize;
            // Call the Container class's clear function with the new parameters
            Container::clear(packunit, content);
            this->Unit_Size = unitSize;
            this->Number_Of_Units = 0;
        }
    }

    // To print the pack details
    ostream& Pack::print(ostream& out) {
        // Call the Container class's print function
        Container::print(out);
        if (valid()) {
            out << ", " << Number_Of_Units << " in a pack of " << Size;
        }
        return out;
    }

    // To read input for the pack
    istream& Pack::read(istream& in) {
        int units;
        if (!valid()) {
            cout << "Broken Container, adding aborted! Press <ENTER> to continue....";
            in.ignore();
        }
        else if (Number_Of_Units == Size) {
            in.ignore();
            cout << "Pack is full!, press <ENTER> to continue..." << endl;
        }
        else {
            bool validValue = false;
            cout << "Add to ";
            // Call the print function to display pack details
            print(cout);

            int maxVal = Size - Number_Of_Units;
            int flag = 0;
            while (!validValue && flag == 0) {
                cout << endl << "> ";
                in >> units;
                if (units > Size) {
                    cout << "Invalid Integer, retry: ";
                }
                else if (units < 1 || units > maxVal) {
                    cout << "Value out of range [1<=val<=" << maxVal << "]: ";
                    in >> units;
                    flag = 1;
                }
                else validValue = true;
            }
            // Add the specified number of units to the pack
            units = (*this += units);
            cout << "Added " << units << endl;
        }
        return in;
    }
}