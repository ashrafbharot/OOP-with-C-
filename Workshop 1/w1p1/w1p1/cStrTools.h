#pragma once
/***********************************************************************
// OOP244 Workshop #1 lab
//
// File  w1p1.cpp
// Version 1.0
// Author   Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name: MOHAMED ASHRAF BHAROT          Date: 2023-09-13   Reason
***********************************************************************/
#ifndef _SDDS_CSTRTOOLS_H_
#define _SDDS_CSTRTOOLS_H_
namespace sdds {


	char toLower(char ch);
	int strCmp(const char* s1, const char* s2);
	int strnCmp(const char* s1, const char* s2, int len);
	void strCpy(char* des, const char* src);
	int strLen(const char* str);
	const char* strStr(const char* str, const char* find);
	int isAlpha(char ch);
	int isSpace(char ch);
	void trim(char word[]);
	void toLowerCaseAndCopy(char des[], const char source[]);
}
#endif // !_SDDS_CSTRTOOLS_H_
