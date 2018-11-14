/*
*Course: CMPS 2143 - OOP
*Program: Assignment 06
*
*Purpose: a sfml clock that can be used to count up or down. extends group to
*			allow it to be drawable
*
*@author Daniel DayCee Duncan
*@version 1.1 11/14/18
*@github droidfanatic
*/

#include "counter.h"

using namespace std;
using namespace sf;

int main()
{
	RenderWindow window(VideoMode(500, 400), "SFML Clock");

	counter clock(25, 0, 50, 50);
	counter clock2(0, 25, 450, 50);

	clock.setColors(Color::Blue, Color::Red, Color::White);

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}
		if (window.isOpen() && clock.atEnd() && clock2.atEnd())
			window.close();

		window.clear();

		window.draw(clock);
		window.draw(clock2);

		clock.updateTime();
		clock2.updateTime();

		window.display();
	}

	return 0;
}