#pragma once
/***********************************************************************
// OOP244 Workshop #4 lab (part 1): tester program
//
// File  main.cpp
// Version 1.0
// Author   Asad Norouzi, revised by Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name:MOHAMED ASHRAF BHAROT   Date:2023-10-05      Reason
***********************************************************************/


#define _CRT_SECURE_NO_WARNNIGS
#ifndef SDDS_CARINVENTORY_H // replace with relevant names
#define SDDS_CARINVENTORY_H


namespace sdds {

	class CarInventory
	{
		//Private member variables

		char* m_type; //Dynamic 

		char* m_brand; //Dynamic

		char* m_model; //Dynamic 

		int m_year; //>= 1900

		int m_code; //three digit integer

		double m_price; //> 0

		void resetInfo();




	public:

		CarInventory();//constructor

		~CarInventory();//destructor

		CarInventory(const char* type, const char* brand, const char* model, int year = 2022, int code = 100, double price = 1);

		CarInventory& setInfo(const char* type, const char* brand, const char* model, int year, int code, double price);

		void printInfo() const;

		bool isValid() const;

		bool isSimilarTo(const CarInventory& car) const;

	};
	//global function
	int find_similar(CarInventory car[], const int num_cars);
}
#endif
