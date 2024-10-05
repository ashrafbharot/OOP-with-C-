/***********************************************************************
// OOP244 Workshop #3 
//
// File  main.cpp
// Version 1.0
// Author   Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name: MOHAMED ASHRAF BHAROT        Date 2023-09-28           Reason
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGSS
#include <iostream>
#include <cstring>
#include <iomanip>
#include "Train.h"

namespace sdds {

    Train::Train() : nameTrain(nullptr), NoOfpassengers(-1), TimeOfDepart(-1) {}

    Train::~Train() {
        finalize();
    }

    void Train::initialize() {
        finalize();
        nameTrain = nullptr;
        NoOfpassengers = -1;
        TimeOfDepart = -1;
    }

    bool Train::validTime(int value) const {
        int minutes = value % 100;
        return (value >= MIN_TIME && value <= MAX_TIME && minutes <= 59);
    }

    bool Train::validNoOfPassengers(int value) const {
        return (value > 0 && value <= MAX_NO_OF_PASSENGERS);
    }

    void Train::set(const char* name) {
        finalize();
        if (name && name[0] != '\0') {
            this->nameTrain = new char[strlen(name) + 1];
            strcpy(this->nameTrain, name);
        }
    }

    void Train::set(int noOfPassengers, int departure) {
        if (validNoOfPassengers(noOfPassengers) && validTime(departure)) {
            this->NoOfpassengers = noOfPassengers;
            this->TimeOfDepart = departure;
        }
        else {
            this->NoOfpassengers = -1;
            this->TimeOfDepart = -1;
        }
    }

    void Train::set(const char* name, int noOfPassengers, int departure) {
        set(name);
        set(noOfPassengers, departure);
    }

    void Train::finalize() {
        delete[] nameTrain;
        nameTrain = nullptr;
        NoOfpassengers = -1;
        TimeOfDepart = -1;
    }

    bool Train::isInvalid() const {
        return (nameTrain == nullptr || NoOfpassengers == -1 || TimeOfDepart == -1);
    }

    int Train::noOfPassengers() const {
        return NoOfpassengers;
    }

    const char* Train::getName() const {
        return (nameTrain != nullptr) ? nameTrain : "Train in an invalid state";
    }

    int Train::getDepartureTime() const {
        return TimeOfDepart;
    }

    void Train::display() const {
        if (!isInvalid()) {
            std::cout << "NAME OF THE TRAIN:    " << nameTrain << std::endl;
            std::cout << "NUMBER OF PASSENGERS: " << NoOfpassengers << std::endl;
            std::cout << "DEPARTURE TIME:       " << std::setw(4) << std::setfill('0') << TimeOfDepart << std::endl;
        }
        else {
            std::cout << "Train in an invalid State!" << std::endl;
        }
    }
}
