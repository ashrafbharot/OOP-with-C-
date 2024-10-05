#pragma once
/***********************************************************************
// OOP244 Workshop #4 DIY (part 2): tester program
//
// File  main.cpp
// Version 1.0
// Author  Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name: MOHAMED ASHRAF BHAROT         Date:2023-10-08        Reason
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#ifndef SDDS_LABEL_H
#define SDDS_LABEL_H
#include <iostream>
#include <cstring>
using namespace std;
namespace sdds
{
	class Label {
		char frameString[9];
		char* m_content;
	public:
		Label();
		Label(const char* frameArg);
		Label(const char* frameArg, const char* content);
		~Label();
		std::istream& readLabel();
		std::ostream& printLabel()const;
		void clear();
		Label& text(const char* content);
	};
}
#endif