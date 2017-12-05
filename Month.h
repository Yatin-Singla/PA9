#pragma once

#include <string>

using std::string;

class Month
{
public:


	Month(int passedMonth = 0, int passedNumberOfStrikes = 0, double passedAverageLongitude = 0.0, double passedAverageLatitude = 0.0);

	//Getters
	int GetMonthTitle();

	int GetNumberOfStrikes();

	double GetAvgLongitude();

	double GetAvgLatitude();

	//Setters
	void SetMonthTitle(int passedMonth);

	void SetNumberOfStrikes(int passedNumberOfStrikes);

	void SetAvgLongitude(double passedLongitude);

	void SetAvgLatitude(double passedLatitude);




private: 
	int monthTitle;

	int numberOfStrikes;

	double averageLongitude;

	double averageLatitude;
};

