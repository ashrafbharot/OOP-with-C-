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
#ifndef SDDS_LABELMAKER_H
#define SDDS_LABELMAKER_H
#include <iostream>
#include "Label.h"

namespace sdds
{
	class LabelMaker
	{
		int noOfLabels;
		Label* labels;
	public:
		LabelMaker(int noOfLabels);
		void readLabels();
		void printLabels();
		~LabelMaker();
	};
}

#endif
