#include "Month.h"

Month::Month(int passedMonth, int passedNumberOfStrikes){

	//initialize the two private data members
	this->monthTitle = passedMonth;

	this->numberOfStrikes = passedNumberOfStrikes;

}

int Month::GetMonthTitle() {

	return this->monthTitle;
}

int Month::GetNumberOfStrikes() {

	return this->numberOfStrikes;

}

void Month::SetMonthTitle(int passedMonth) {

	this->monthTitle = passedMonth;

}

void Month::SetNumberOfStrikes(int passedNumberOfStrikes) {

	this->numberOfStrikes = passedNumberOfStrikes;

}

