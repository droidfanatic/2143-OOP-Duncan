/*
*Course: CMPS 2143 - OOP
*
*Purpose: tests to see if sfml is working
*
*@author Daniel DayCee Duncan
*@version 1.1 10/1/18
*@github droidfanatic
*/

#include <SFML/Graphics.hpp>
int main() {
	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear();
		window.draw(shape);
		window.display();
	}
	return 0;
}
