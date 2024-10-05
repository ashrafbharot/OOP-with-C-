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
#ifndef _SSDS_WORD_H_
#define _SDDS_WORD_H_

namespace sdds {
	const int MAX_WORD_LEN = 21;
	struct Word {
		char letters[MAX_WORD_LEN];
		int count;
	};


	

	int searchWords(const Word words[], int num, const char word[]);
	int readWord(char* word, FILE* fptr, int maxLen);
	void addWord(Word words[], int* index, const char newWord[]);
	void title(const char* value, int len);
	void endList();
	void totalWordsStat(int totNoWrds, int totalOverAll, int longestWord);
	void print(const Word* w, int gotoNextLine, int len);
	int findMaxLen(const Word words[], int noOfWords);
	void listWords(const Word words[], int noOfWords, const char* theTitle);
	void swap(Word* p1, Word* p2);
	void sort(Word words[], int cnt, int sortType);
	int totalCount(const Word* words, int num);
	void wordStats(const char* filename);
	void programTitle();


}
#endif // !_SDDS_WORD_H_
