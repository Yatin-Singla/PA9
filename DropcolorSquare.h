#pragma once

#include <SFML/Graphics.hpp>

class DropcolorSquare : public sf::RectangleShape
{
public:

	DropcolorSquare();

	virtual void SetPosition(int X, int Y);

	int GetDropLength();

	int GetSideLength();

	
private:

	int dropLength;

};

