#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <string>

#include "DropcolorSquare.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;

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

	//Opens a new window for graphics in fullscreen if the device supports it,
	//hard-coded size if not
	void CreateNewWindow(sf::RenderWindow &window, sf::VideoMode &screenResolution, string windowTitle);

	void DropColor(sf::RenderWindow &window, DropcolorSquare squares[50]);

	void DoubleDropColor(sf::RenderWindow &window, DropcolorSquare squaes1[50], DropcolorSquare squares2[50]);
};

