#include <iostream>
#include "AppWrapper.h"

//included in the AppWrapper
//#include <SFML/Graphics.hpp> 
//using std::cout;
//using std::endl;

int main() {


	AppWrapper newApp;

	//hit that go button!
	newApp.StartApplication();


	return 0;
}


/* cout << "init" << endl;

sf::RenderWindow window(sf::VideoMode(600, 600), "SFML works!");
sf::CircleShape shape(100.f);
shape.setFillColor(sf::Color::Green);

while (window.isOpen())
{
sf::Event event;
while (window.pollEvent(event))
{
if (event.type == sf::Event::Closed)
window.close();
}

window.clear();
window.draw(shape);
window.display();
}*/


