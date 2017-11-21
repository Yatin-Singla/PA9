#include "AppWrapper.h"

AppWrapper::AppWrapper()
{
	//construct greatness
}

void AppWrapper::StartApplication() {

	//init for rand
	srand((unsigned int)time(NULL));

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
			cout << "\"Insert Better Menu Title\"\n\n1. Squares Playground\n2. Circles Playground\n3. Exit" << endl;

			cin >> option;

		} while (option < 1 || option > 3);	//exit condition will change with new menu items 



		//Switch statement for each item number in the menu
		switch (option) {

		case 1:

			//Start the playground
			this->SquaresPlayground();
			break;

		case 2:

			//Start the playgrund
			this->CirclesPlayground();
			break;

		case 3:

			//Display exit message? exit condition will be triggered to exit this function
			//and end the application
			cout << "Later, fam" << endl;
			break;

		}

	} while (option != 3);
	



}

void AppWrapper::SquaresPlayground() {

	//Declare a RenderWindow object
	sf::RenderWindow window;

	//returns VideoMode for current display resolution of the device being used
	sf::VideoMode deviceScreenResolution = sf::VideoMode::getDesktopMode();

	//create the window
	this->CreateNewWindow(window, deviceScreenResolution, "Sqaures Playground");

	
	//pass to a drawing algo?
	//pattern for drawing (to look like movement) is clear, draw, display
	this->DoubleDropColor(window);
	//this->DropColor(window);

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

void AppWrapper::DropColor(sf::RenderWindow &window) {


	//create the array of 50 squares with already randomized values 
	DropcolorSquare squares[50];

	//variable to track X position of printing
	int printPos = 0;

	
	for (int i = 0; i < 50; i++) {

		//start at (0,0), move right 1 side length each loop
		squares[i].SetPosition(printPos, 0);

		int dropLength = squares[i].GetDropLength();

		//vertical drop loop
		for (int j = 0; j < dropLength; j += 2) {

			squares[i].SetPosition(printPos, j);

			window.draw(squares[i]);

			window.display();

		}

		printPos += squares[i].GetSideLength();

	}

	
	//necessary to keep the window open and not crash the program during/after execution
	while (window.isOpen()){
		//polling of events.. may find use elsewhere
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
	}
}

void AppWrapper::DoubleDropColor(sf::RenderWindow &window) {


	//create two arrays of 50 squares with already randomized values 
	DropcolorSquare squares1[50];
	DropcolorSquare squares2[50];


	//variable to track X position of printing
	int printPos = 0;

	//Top half of the visual
	for (int i = 0; i < 50; i++) {

		//start at (0,0), move right 1 side length each loop
		squares1[i].SetPosition(printPos, 0);

		int dropLength = squares1[i].GetDropLength();

		//vertical drop loop
		for (int j = 0; j < dropLength; j += 10) {

			squares1[i].SetPosition(printPos, j);

			window.draw(squares1[i]);

			window.display();

		}

		printPos += squares1[i].GetSideLength();

	}

	printPos = 0;

	//the furthest down on the screen we want to print
	int pos2 = (int) squares2[0].getSize().x * 49;


	for (int i = 0; i < 50; i++) {

		//start at (0,0), move right 1 side length each loop
		squares2[i].SetPosition(printPos, pos2);


		int dropLength = squares2[i].GetDropLength();

		//vertical drop loop
		for (int j = pos2; j > (pos2 - dropLength); j -= 10) {

			squares2[i].SetPosition(printPos, j);

			window.draw(squares2[i]);

			window.display();

		}

		printPos += squares2[i].GetSideLength();

	}

	//necessary to keep the window open and not crash the program during/after execution
	while (window.isOpen()) {
		//polling of events.. may find use elsewhere
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
	}

}

void AppWrapper::CirclesPlayground() {


	//Declare a RenderWindow object
	sf::RenderWindow window;

	//returns VideoMode for current display resolution of the device being used
	sf::VideoMode deviceScreenResolution = sf::VideoMode::getDesktopMode();

	//create the window
	this->CreateNewWindow(window, deviceScreenResolution, "Circles Playground");

	//Do the dance
	this->Untitled(window);
}


void AppWrapper::Untitled(sf::RenderWindow &window) {

	//the array of monthly lightning strike data
	Month Year2001[12];
	

	//read the data from the file into the array of month data
	if (InitializeMonthArray(Year2001)) {

		//
		// Testing
		//
		for (int i = 0; i < 12; i++) {

			cout << "Month: " << Year2001[i].GetMonthTitle() << " Number of strikes: " << Year2001[i].GetNumberOfStrikes() << endl;

		}
		//
		// Testing
		//

	}
	else {

		//display error message and pause for acknowledgement
		system("cls");
		cout << "Unable to open file/file not found!" << endl;
		system("pause");

	}

}

bool AppWrapper::InitializeMonthArray(Month passedMonthArray[12]) {
	
	//return control variable
	bool success = false;

	//declare the ifstream that holds the strike data
	ifstream strikeData("lightning-strikes.csv");

	if (strikeData.is_open()) {

		//worker variable used to get non-useful information when needed
		string trash = "";

		int currentMonth = 0;

		//header info for the data
		getline(strikeData, trash);
		
		
		//continue to loop until stream reaches the end
		while (!strikeData.eof()) {

			//the year
			getline(strikeData, trash, ',');

			//the month
			strikeData >> currentMonth;

			//if the title hasn't already been assigned, assign int
			if (passedMonthArray[currentMonth -1].GetMonthTitle() == 0) {

				passedMonthArray[currentMonth -1].SetMonthTitle(currentMonth);

			}

			//add one more strike to the current month
			passedMonthArray[currentMonth -1].SetNumberOfStrikes(passedMonthArray[currentMonth - 1].GetNumberOfStrikes() + 1);
		}

		//update success for process
		success = true;
	}
	

	//return outcome
	return success;
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

	





