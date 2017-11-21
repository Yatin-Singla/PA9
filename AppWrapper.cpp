#include "AppWrapper.h"

AppWrapper::AppWrapper()
{
	//construct greatness
}

void AppWrapper::StartApplication() {

	//init for rand
	srand(time(NULL));

	//call the menu function
	this->DisplayMenu();

}

void AppWrapper::DisplayMenu() {

	//Menu controller
	int option = 0;

	//lLoop that controls the exit of the app
	do {

		//Loop that takes care of input validation
		do {

			//clear the console
			system("cls");

			//print the menu for visualizations
			cout << "\"Insert Better Menu Title\"\n\n1. Squares Playground\n2. Exit" << endl;

			cin >> option;

		} while (option < 1 || option > 2);	//exit condition will change with new menu items 



		//Switch statement for each item number in the menu
		switch (option) {

		case 1:

			//Start the playground
			this->SquaresPlayground();

			break;

		case 2:
			//Display exit message? exit condition will be triggered to exit this function
			//and end the application
			cout << "\nLater, fam" << endl;

			break;
		}

	} while (option != 2);
	



}

void AppWrapper::SquaresPlayground() {

	//Declare a RenderWindow object
	sf::RenderWindow window;

	//returns VideoMode for current display resolution of the device being used
	sf::VideoMode deviceScreenResolution = sf::VideoMode::getDesktopMode();

	//create the window
	this->CreateNewWindow(window, deviceScreenResolution, "Sqaures Playground");

	//create the array of 50 squares with already randomized values 
	DropcolorSquare squares1[50];

	DropcolorSquare squares2[50];



	//pass to a drawing algo?
	//pattern for drawing (to look like movement) is clear, draw, display
	this->DoubleDropColor(window, squares1, squares2);


}

void AppWrapper::CreateNewWindow(sf::RenderWindow &window, sf::VideoMode &screenResolution, string windowTitle) {

	if (screenResolution.isValid()) {

		//Create a window at full resolution capability/size	
		window.create(screenResolution, windowTitle);

	}
	else {

		//invalid window size, create a window with a hard-coded size
		window.create(sf::VideoMode(600, 600), windowTitle);

	}

}

void AppWrapper::DropColor(sf::RenderWindow &window, DropcolorSquare squares[50]) {

	//variable to track X position of printing
	int printPos = 0;

	
	for (int i = 0; i < 50; i++) {

		//start at (0,0), move right 1 side length each loop
		squares[i].SetPosition(printPos, 0);

		int dropLength = squares[i].GetDropLength();

		//vertical drop loop
		for (int j = 0; j < dropLength; j+=2) {
			
			squares[i].SetPosition(printPos, j);
			 
			window.draw(squares[i]);

			window.display();

		}

		printPos += squares[i].GetSideLength();

	}


}

void AppWrapper::DoubleDropColor(sf::RenderWindow &window, DropcolorSquare squares1[50], DropcolorSquare squares2[50]) {

	//variable to track X position of printing
	int printPos = 0;

	//Top half of the visual
	for (int i = 0; i < 50; i++) {

		//start at (0,0), move right 1 side length each loop
		squares1[i].SetPosition(printPos, 0);

		int dropLength = squares1[i].GetDropLength();

		//vertical drop loop
		for (int j = 0; j < dropLength; j += 2) {

			squares1[i].SetPosition(printPos, j);

			window.draw(squares1[i]);

			window.display();

		}

		printPos += squares1[i].GetSideLength();

	}

	printPos = 0;

	//the furthest down on the screen we want to print
	int pos2 = squares2[0].getSize().x * 49;


	for (int i = 0; i < 50; i++) {

		//start at (0,0), move right 1 side length each loop
		squares2[i].SetPosition(printPos, pos2);


		int dropLength = squares2[i].GetDropLength();

		//vertical drop loop
		for (int j = pos2; j > (pos2 - dropLength); j -= 2) {

			squares2[i].SetPosition(printPos, j);

			window.draw(squares2[i]);

			window.display();

		}

		printPos += squares2[i].GetSideLength();

	}

}





	
	/*sf::RectangleShape squares[50];


	sf::RectangleShape rect;

	rect.setSize(sf::Vector2f(50, 40));
	
	rect.setFillColor(sf::Color::White);*/

	
	//pattern for drawing is clear, draw, display

	//for (int i = 0; i < 1000; i++) {

	//	//rect.setPosition(0, i);

	//	window.clear();
	//	
	//	//window.draw(rect);

	//	window.display();
	//	
	//	

	//}

	//
	//Testing
	//
	//while (window.isOpen())
	//{
	//	//polling of events.. may find use elsewhere
	//	sf::Event event;
	//	while (window.pollEvent(event))
	//	{
	//		if (event.type == sf::Event::Closed)
	//			window.close();
	//	}


	//	window.clear();
	//	
	//	window.display();
	//}
	//
	//End Test
	//

	





