#include "DropcolorSquare.h"


DropcolorSquare::DropcolorSquare()
{
	//Variables to hold the random R, G, and B values
	int R = 0, G = 0, B = 0;

	//to determine range for drop length
	sf::VideoMode deviceScreenResolution = sf::VideoMode::getDesktopMode();

	//set the size of the square @ 1/50 the width of the screen
	int sideLength = (deviceScreenResolution.width / 50);

	this->setSize(sf::Vector2f((float)sideLength, (float)sideLength));


	//randomize the RGB values
	R = rand() % 256;

	G = rand() % 256;

	B = rand() % 256;

	//set the fill color
	this->setFillColor(sf::Color(R, G, B));
	
	//set the dropLength
	this->dropLength = rand() % (deviceScreenResolution.height);

}

void DropcolorSquare::SetPosition(int X, int Y) {

	//set postion
	this->setPosition((float)X, (float)Y);

}

int DropcolorSquare::GetDropLength() {

	return this->dropLength;
}


int DropcolorSquare::GetSideLength() {


	return (int) this->getSize().x;


}


