#include "AppWrapper.h"

AppWrapper::AppWrapper()
{
	//construct greatness
}

void AppWrapper::StartApplication() {

	//just calls the display menu function..
	//may do some other inits later, we'll see
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
	

	//think this is where I will call the shape draing algo..
	//coming back to this tomorrow
	//...

	//
	//Testing
	//
	while (window.isOpen())
	{
		//polling of events.. may find use elsewhere
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}


		window.clear();
		
		window.display();
	}
	//
	//Testing
	//

	
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

