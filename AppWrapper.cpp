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



