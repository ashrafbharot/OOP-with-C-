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

#pragma once
#ifndef TRAIN_H
#define TRAIN_H

const int MIN_TIME = 700;
const int MAX_TIME = 2300;
const int MAX_NO_OF_PASSENGERS = 1000;

namespace sdds
{
	class Train
	{
		char* Name;
		int passengerNum;
		int DepartTime;
	public:
		void initialize();//it intialises the train object to invalid state

		bool validTime(int value)const;//return true if the value is min and max acceptable values

		bool validNoOfPassengers(int value)const;//return true if the number of passengers is positive

		void set(const char* name);//set the name of the train dynamically

		void set(int noOfPassengers, int departure);//set the two attributes for the number of passengers and departure time

		void set(const char* name, int noofpassengers, int departure);//set the name, number of passengers or departure to the incomming arguments

		void finalize();//finalize the use of train object

		bool isInvalid()const;// returns true if any attributes are set to their invalid state.

		int noOfPassengers() const;//returns the number of people on train

		const char* getName()const;//returns the number of passengers

		int getDepartureTime()const;//returns the departure time of the train

		void display() const;//display the information of train

		int sumOfPassengers(int);//calculate the total number of passengers on the train

		bool load(int& value);//boards passengers onto the train

		bool updateDepartureTime();//returns boolean to indicate if the action was successful or not

		bool transfer(const Train&);//transfers the passengers of train to the current train

	};
}
#endif // !TRAIN_H

