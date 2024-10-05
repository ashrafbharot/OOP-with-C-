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

#define _CRT_SECURE_NO_WARNINGS
#include "Phone.h"
#include <string.h>
#include <cstdio>
#include <iostream>
#include <iomanip>
#include "cStrTools.h"


using namespace std;

namespace sdds
{
	// runs the phone directory application

	void phoneDir(const char* programTitle, const char* fileName)
	{
		phoneDirectory data;
		char name[MAX_NAME + 1];
		int x = 1;
		const char* ptr = 0;
		char lowerCase[MAX_NAME + 1];

		displayTitle(programTitle);

		FILE* fptr = fopen(fileName, "r");

		if (fptr != NULL) {
		  do {
			  cout << "Enter a partial name to search (no spaces) or enter '!' to exit" << endl;
			  cout << "> ";
			  cin >> name;

				toLowerCaseAndCopy(name, name);

				if (strCmp(name, "!") == 0) {
					cout << "Thank you for using " << programTitle << " directory." << endl;
					x = 0;
				}
				else
				{
					while (fscanf(fptr, "%[^\t]\t%s\t%s\t%s\n", data.name, data.areaCode, data.prefix, data.number) != EOF)
					{
						toLowerCaseAndCopy(lowerCase, data.name);
						ptr = strStr(lowerCase, name);

						if (ptr != NULL)
						{
							cout << data.name << ": (" << data.areaCode << ") " << data.prefix << "-" << data.number << endl;

						}
					}
					fseek(fptr, 0, SEEK_SET);
				}
		  } while (x);

			fclose(fptr);
		}
		else
		{
			fileFail(programTitle, fileName);
		}
	}


	void displayTitle(const char* programTitle)
	{
		cout << programTitle << " phone direcotry search" << endl;
		cout << "-------------------------------------------------------" << endl;
	}


	void fileFail(const char* programTitle, const char* fileName)
	{
		cout << fileName << " file not found!" << endl;
		cout << "Thank you for using Broken Phone Book directory." << endl;
	}
}