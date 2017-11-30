#include "Month.h"

Month::Month(int passedMonth, int passedNumberOfStrikes, double passedAverageLongitude, double passedAverageLatitude){

	//initialize the two private data members
	this->monthTitle = passedMonth;

	this->numberOfStrikes = passedNumberOfStrikes;

	this->averageLongitude = passedAverageLongitude;

	this->averageLatitude = passedAverageLatitude;

}

int Month::GetMonthTitle() {

	return this->monthTitle;
}

int Month::GetNumberOfStrikes() {

	return this->numberOfStrikes;

}

double Month::GetAvgLongitude() {

	return this->averageLongitude;

}

double Month::GetAvgLatitude() {

	return this->averageLatitude;

}

void Month::SetMonthTitle(int passedMonth) {

	this->monthTitle = passedMonth;

}

void Month::SetNumberOfStrikes(int passedNumberOfStrikes) {

	this->numberOfStrikes = passedNumberOfStrikes;

}

void Month::SetAvgLongitude(double passedLongitude) {

	this->averageLongitude = passedLongitude;

}

void Month::SetAvgLatitude(double passedLatitude) {

	this->averageLatitude = passedLatitude;

}

