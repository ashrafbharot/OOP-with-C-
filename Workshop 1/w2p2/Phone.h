#pragma once
/******************************************************************************
					Workshop - #1 (Part-2)>
Full Name	:MOHAMED ASHRAF BHAROT
Student ID# : 139539225
Email		: mamabharot@myseneca.ca
Section	    : ZCC
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
******************************************************************************/
// -----------------------------------------------------------
// Name: Mohamed Ashraf Bharot          Date: 2023-09-06         Reason
/***********************************************************************/

#ifndef _SDDS_PHONE_H 
#define _SDDS_PHONE_H
#define MAX_LENGTH 20
#define MAX_NAME 50

struct phoneDirectory {
	char name[MAX_NAME + 1];
	char areaCode[MAX_LENGTH + 1];
	char prefix[MAX_LENGTH + 1];
	char number[MAX_LENGTH + 1];
};

namespace sdds {

	// runs the phone directory application
	void phoneDir(const char* programTitle, const char* fileName);
	
	void displayTitle(const char* programTitle);
	
	void fileFail(const char* programTitle, const char* fileName);
	//char getInput(int fptr, const char* programTitle);
}
#endif // !_SDDS_PHONE_H_