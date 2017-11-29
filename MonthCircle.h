#pragma once

#include <SFML/Graphics.hpp>

using sf::CircleShape;

class MonthCircle : public  CircleShape
{
public:

	//MonthCircle constructor invoking the CircleShape constructor
	MonthCircle(float dRadius = 1.0);

	//Setter for the max radius
	void SetMaxRadius(float passedRadius);

	//Getter for the max radius
	float GetMaxRadius();

private:

	float maxRadius;


};

