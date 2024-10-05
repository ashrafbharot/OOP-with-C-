// Workshop #7:
// // Description:
// This file tests the lab section of your workshop
// Name: MOHAMED ASHRAF BHAROT  DATE:2023-11-12 
///////////////////////////////////////////////////

#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include<string>
#include "Container.h"

using namespace std;
namespace sdds {

    // Getter function for the volume of the container
    int Container::volume() {
        return Volume;
    }

    // To set the container as empty
    void Container::setEmpty() {
        Valid_Container = false;
    }

    // Getter function for the capacity of the container
    int Container::capacity() {
        return Capacity;
    }

    // Constructor for the Container class
    Container::Container(const char* Content, int Capacity, int Content_volume) {
        // Check if the content is valid and within capacity
        if (Content == NULL || Content_volume > Capacity) {
            Valid_Container = false;
        }
        else {
            // Set the container properties
            strcpy(this->Description, Content);
            this->Capacity = Capacity;
            this->Volume = Content_volume;
            Valid_Container = true;
        }
    }

    // Overloaded -= operator for subtracting volume from the container
    int Container::operator -= (int value) {
        // Update the volume, ensuring it doesn'tgo below zero
        if (Volume - value >= 0) {
            Volume -= value;
        }
        else {
            value = Volume;
            Volume = 0;
        }
        return value;
    }

    // Overloaded += operator for adding volume to the container
    int Container::operator += (int value) {
        // Update the volume, ensuring it doesn't exceed the capacity
        if (Volume + value <= Capacity) {
            Volume += value;
        }
        else {
            value = Capacity - Volume;
            Volume = Capacity;
        }
        return value;
    }

    // To check if the container is valid
    bool Container::valid() {
        return Valid_Container;
    }

    // To clear the container with a new capacity and description 
    void Container::clear(int Capacity, const char* m_description) {
        if (Capacity >= 1 && m_description != NULL && strlen(m_description) >= 1) {
            // Set the new container properties
            this->Capacity = Capacity;
            strcpy(this->Description, m_description);
            this->Volume = 0;
            Valid_Container = true;
        }
    }

    // To print the container details
    ostream& Container::print(ostream& ostr) {
        if (Valid_Container) {
            ostr << Description << ": (" << Volume << "cc/" << Capacity << ")";
        }
        else {
            ostr << "****: (**cc/***)";
        }
        return ostr;
    }

    // To read input for the container
    istream& Container::read(istream& istr) {
        int number;
        if (!Valid_Container) {
            cout << "Broken Container, adding aborted! Press <ENTER> to continue...." << endl;
            istr.ignore();
        }
        else {
            bool validValue = false;
            cout << "Add to ";
            // Call the print function to display container details
            print(cout);
            while (!validValue) {
                cout << endl << "> ";
                istr >> number;
                if (number > Capacity) {
                    cout << "Invalid Integer, retry:";
                }
                else if (number < 1 || number > 999) {
                    cout << "Value out of range [1<=val<=999]:";
                }
                else validValue = true;
            }
            // Add the specified volume to the container
            number = (*this += number);
            cout << "Added " << number << " CCs" << endl;
        }
        return istr;
    }
}