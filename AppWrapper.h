#pragma once


#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <string>
#include <fstream>

#include "DropcolorSquare.h"
#include "Month.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ifstream;
using std::getline;

class AppWrapper
{
public:

	//Defualt constructor.. notining in there for now
	AppWrapper();

	//App entry point
	void StartApplication();



private:

	//Main menu function
	void DisplayMenu();

	//Playground using squares
	void SquaresPlayground();

	//Playground using circles
	void CirclesPlayground();

	//Opens a new window for graphics in fullscreen if the device supports it,
	//hard-coded size if not
	void CreateNewWindow(sf::RenderWindow &window, sf::VideoMode &screenResolution, string windowTitle);

	//Bar visualization from top
	void DropColor(sf::RenderWindow &window);

	//Bar visualization from top and bottom
	void DoubleDropColor(sf::RenderWindow &window);

	void Untitled(sf::RenderWindow &window);

	bool InitializeMonthArray(Month passedMonthArray[12]);
};

