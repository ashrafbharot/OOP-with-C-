/***********************************************************************
// OOP244 Workshop #3 DIY (part 2): tester program
//
// File  main.cpp
// Version 1.0
// Author   Cornel Barna, Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
 Name: MOHAMED ASHRAF BHAROT    Date: 2023-10-01          Reason*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Train.h"

using namespace std;
using namespace sdds;

//it intialises the train object to invalid state
void Train::initialize()
{
	Name = nullptr;
	passengerNum = -1;
	DepartTime = -1;
}

//return true if the value is min and max acceptable values
bool Train::validTime(int value)const
{
	if (value >= MIN_TIME && value <= MAX_TIME)//  the value condition 
	{
		int minute = value % 100; // two right digits
		if (minute <= 59)
		{
			return true;
		}
	}
	return false;

}

bool Train::validNoOfPassengers(int value)const
{
	if (value > 0 && value < MAX_NO_OF_PASSENGERS)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Train::set(const char* name)
{
	finalize();
	if (name != nullptr && name[0] != '\0')
	{
		Name = new char[strlen(name) + 1];

		strcpy(Name, name);
	}
}

void Train::set(int noOfPassengers, int departure)
{
	if (validTime(departure) && validNoOfPassengers(noOfPassengers))
	{
		DepartTime = departure;
		passengerNum = noOfPassengers;
	}
	else
	{
		DepartTime = -1;
		passengerNum = -1;
	}
}

void Train::set(const char* name, int noOfPassengers, int departure)
{
	set(name);
	set(noOfPassengers, departure);

}

void Train::finalize()
{
	if (Name != nullptr)
	{
		delete[] Name;
		Name = nullptr;
	}
}

bool Train::isInvalid() const
{
	if (Name == nullptr || passengerNum == -1 || DepartTime == -1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int Train::noOfPassengers() const
{
	return passengerNum;
}

const char* Train::getName() const
{
	return Name;
}
int Train::getDepartureTime() const
{
	return DepartTime;
}
void Train::display() const
{
	if (!(isInvalid()))
	{
		cout << "NAME OF THE TRAIN:    " << Name << endl;
		cout << "NUMBER OF PASSENGERS: " << passengerNum << endl;
		cout << "DEPARTURE TIME:       " << DepartTime << endl;
	}
	else
	{
		cout << "Train in an invalid State!" << endl;
	}
}

//calculate the total number of passengers on the train
int Train::sumOfPassengers(int PassengerVal)
{
	int TotalPass;
	TotalPass = passengerNum + PassengerVal;
	return TotalPass;
}

//boards passengers onto the train
bool Train::load(int& remainPassengers)
{
	int TotalPass;
	int noOfPassengers;
	cout << "Enter number of passengers boarding:" << endl;
	cout << "> ";
	cin >> noOfPassengers;
	TotalPass = sumOfPassengers(noOfPassengers);
	if (TotalPass > MAX_NO_OF_PASSENGERS)
	{
		remainPassengers = (TotalPass - MAX_NO_OF_PASSENGERS);
		passengerNum = MAX_NO_OF_PASSENGERS;
	}
	else
	{
		remainPassengers = 0;
		passengerNum = TotalPass;
	}
	return remainPassengers == 0;
}

//returns boolean to indicate if the action was successful or not
bool Train::updateDepartureTime()
{
	int newDepartTime;
	cout << "Enter new departure time:" << endl;
	cout << "> ";
	cin >> newDepartTime;
	if (validTime(newDepartTime))
	{
		DepartTime = newDepartTime;
		return true;
	}
	else
	{
		DepartTime = -1;
		return false;
	}
}

//transfers the passengers of train to the current train
bool Train::transfer(const Train& secondTrain)
{
	if (!isInvalid() && !secondTrain.isInvalid())
	{
		int totalPassengers, passengersLeft;
		char* combinedName = new char[strlen(Name) + strlen(secondTrain.Name) + 3];  // alllocating the dynamic memory
		// creating the names for both the trains
		strcpy(combinedName, Name);
		strcat(combinedName, ", ");
		strcat(combinedName, secondTrain.Name);

		delete[] Name;
		Name = combinedName;
		totalPassengers = sumOfPassengers(secondTrain.passengerNum);
		if (totalPassengers > MAX_NO_OF_PASSENGERS)
		{
			passengersLeft = totalPassengers - MAX_NO_OF_PASSENGERS;
			cout << "Train is full; " << passengersLeft << " passengers of " << secondTrain.Name << " could not be boarded!" << endl;
			passengerNum = MAX_NO_OF_PASSENGERS;


		}
		else
		{
			passengerNum = totalPassengers;

		}

		return true;

	}
	return false;

}