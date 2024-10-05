#pragma once
/***********************************************************************
// OOP244 Workshop #2 DIY (part 2):
//
// File  File.h
// Version 1.0
// Author   Fardad Soleimanloo
// Description
//   To completed by students
// Revision History
// -----------------------------------------------------------
// Name:MOHAMED ASHRAF BHAROT         Date 2023-09-24         Reason
***********************************************************************/
#ifndef SDDS_FILE_H_
#define SDDS_FILE_H_
#define MAX_POSTAL_CODE_LEN 3
namespace sdds {
	bool openFile(const char filename[]);
	void closeFile();
	int numRecords();
	int numRecords(const char* postalCodePrefix);
	bool read(char*& postalCode);
	bool read(int& population);
	bool read(char*& postalCode, const char* partial_postal_code_prefix);

}
#endif // !SDDS_FILE_H_
