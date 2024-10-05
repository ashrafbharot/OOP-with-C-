/***********************************************************************
// OOP244 Workshop #2 lab (part 1)
//
// File  File.h
// Version 1.0
// Author   Fardad Soleimanloo
// Description
//    To be completed by students
// Revision History
// -----------------------------------------------------------
// Name: MOHAMED ASHRAF BHAROT       Date:2023-09-21    Reason
***********************************************************************/
#ifndef SDDS_FILE_H_
#define SDDS_FILE_H_
namespace sdds {
	bool openFile(const char filename[]);
	void closeFile();
	int noOfRecords();
	// TODO: Declare overloaded read function prototypes
	// reads the employess names 
	bool read(char*& name);
	// to read he employees number 
	bool read(int& employe_no);
	// to read the employees salary 
	bool read(double& employee_salary);

}

#endif // !SDDS_FILE_H_