#include "MonthCircle.h"


//invoke the CircleShape constructor by default
MonthCircle::MonthCircle(float dRadius):CircleShape(){

	//set the default radius of 1 pixel
	this->maxRadius = dRadius;

}

void MonthCircle::SetMaxRadius(float passedRadius) {

	if (passedRadius > 1) {
		
		this->maxRadius = passedRadius;

	}
}

float MonthCircle::GetMaxRadius() {

	return this->maxRadius;

}
