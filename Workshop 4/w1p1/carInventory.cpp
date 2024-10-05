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
// Name: MOHAMED ASHRAF BHAROT    Date:2023-10-05      Reason
***********************************************************************/


#define _CRT_SECURE_NO_WARNINGS
#include "CarInventory.h"
#include<iostream>
#include<cstring>
#include<iomanip>
using namespace std;
namespace sdds {
	// resets the values here for all member variables by setting type, brand, and model to nullptr
	// setting the year, code, and price to 0
	void CarInventory::resetInfo()
	{
		m_type = nullptr;
		m_brand = nullptr;
		m_model = nullptr;
		m_year = 0;
		m_code = 0;
		m_price = 0;
	}
	//This default constructor will initialize the member variables by calling the resetInfo()
	CarInventory::CarInventory()
	{
		resetInfo();
	}
	//
	CarInventory::~CarInventory()
	{
		delete[] m_type;
		delete[] m_brand;
		delete[] m_model;
		m_model = nullptr;
		m_brand = nullptr;
		m_type = nullptr;
		resetInfo();
	}
	//constructor will dynamically keep the values of the C-string argument
	CarInventory::CarInventory(const char* type, const char* brand, const char* model, int year, int code, double price)

	{
		if (type != nullptr || brand != nullptr || model != nullptr || year >= 1990 || code >= 100 || code < 1000 || price > 0)

		{

			m_type = nullptr;
			m_brand = nullptr;
			m_model = nullptr;
			m_type = new char[strlen(type) + 1];
			strcpy(m_type, type);
			m_brand = new char[strlen(brand) + 1];
			strcpy(m_brand, brand);
			m_model = new char[strlen(model) + 1];
			strcpy(m_model, model);
			m_year = year;
			m_code = code;
			m_price = price;
		}
		else
		{
			resetInfo();
		}

	}
	//This method will first deallocate all the allocated memory and then sets the attributes to the corresponding arguments
	CarInventory& CarInventory::setInfo(const char* type, const char* brand, const char* model, int year, int code, double price)
	{
		//deallocate all the allocated memory
		delete[] m_type;
		delete[] m_brand;
		delete[] m_model;

		if (type == nullptr || brand == nullptr || model == nullptr || year < 1990 || code < 100 || price < 0)
		{
			resetInfo();
		}
		else
		{
			m_type = nullptr;
			m_brand = nullptr;
			m_model = nullptr;
			m_type = new char[strlen(type) + 1];
			strcpy(m_type, type);
			m_brand = new char[strlen(brand) + 1];
			strcpy(m_brand, brand);
			m_model = new char[strlen(model) + 1];
			strcpy(m_model, model);

			m_year = year;

			m_code = code;

			m_price = price;

		}

		//return the reference of the current object.
		return *this;

	}
	//This method prints the values of all the member variables on the screen
	void CarInventory::printInfo() const
	{
		std::cout << "|" << " " << left << std::setw(11) << m_type << "|" << " " << left << std::setw(17) << m_brand << "|" << " " << left << std::setw(17) << m_model << "|" << " " << left << std::setw(5) << m_year << "|" << "  " << left << std::setw(4) << m_code << "|" << "  " << left << right << std::setw(8) << fixed << setprecision(2) << m_price << " " << "|" << std::endl;
	}
	//This method returns whether all member variables have valid values or not based on the criteria stated at the Private Member Variables.
	bool CarInventory::isValid() const

	{
		return m_type != nullptr && m_brand != nullptr && m_model != nullptr && m_year >= 1990 && m_code >= 100 && m_price >= 0;
	}

	//This function is to check whether the type, model, brand and year of an object of CarInventory are equal to another object of this class. 
	bool CarInventory::isSimilarTo(const CarInventory& car) const

	{
		if (m_type == nullptr || m_brand == nullptr || m_model == nullptr ||
			car.m_type == nullptr || car.m_brand == nullptr || car.m_model == nullptr) {
			return false; // If any of the values are nullptr, return false
		}

		return (strcmp(m_type, car.m_type) == 0) &&
			(strcmp(m_brand, car.m_brand) == 0) &&
			(strcmp(m_model, car.m_model) == 0) &&
			(m_year == car.m_year);

	};


	int find_similar(CarInventory car[], const int num_cars)
		//It returns i if it finds two CarInventory objects that have similar information in the car array
	{
		for (int i = 0; i < num_cars; i++) {
			for (int j = i + 1; j < num_cars; j++) {
				if (car[i].isSimilarTo(car[j])) {
					return i; // Return the index of the first match
				}
			}
		}
		return -1; // Return -1 if no match is found
	}
}
