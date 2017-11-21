#pragma once

#include <string>

using std::string;

class Month
{
public:


	Month(int passedMonth = 0, int passedNumberOfStrikes = 0);

	//Getters
	int GetMonthTitle();

	int GetNumberOfStrikes();

	//Setters
	void SetMonthTitle(int passedMonth);

	void SetNumberOfStrikes(int passedNumberOfStrikes);



private: 
	int monthTitle;

	int numberOfStrikes;
};

