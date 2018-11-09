/*
*@author Daniel DayCee Duncan
*@version 1.1 11 / 2 / 18
* @github droidfanatic
*/

#include "counter.h"

/*
* counter constructor
* @param:
*	none
*/
counter::counter() {
	rectangle.setSize(Vector2f(100, 100));
	rectangle.setFillColor(Color::Black);
	rectangle.setOutlineColor(Color::Green);
	rectangle.setOutlineThickness(2);
	rectangle.setOrigin(50, 50);
	rectangle.setPosition(100, 100);

	start = seconds(0.0);
	startTime = 0.0;

	end = seconds(50.0);
	endTime = 0.0;

	//Restarts the clocks time when the user creates it
	clock.restart();
	elapsed = clock.getElapsedTime();

	//Loads the proper font
	if (!font.loadFromFile("Segment7Standard.otf"))
	{
		cout << "error laoding font";
	}
	text.setFont(font);
	text.setCharacterSize(48);
	text.setFillColor(Color::Red);
	text.setPosition(0.0, 0.0);

	this->push_back(rectangle);
	this->push_back(text);
}

/*
* counter constructor
* @param:
*	float stime, etime
*/
counter::counter(float stime, float etime) {
	rectangle.setSize(Vector2f(100, 100));
	rectangle.setFillColor(Color::Black);
	rectangle.setOutlineColor(Color::Green);
	rectangle.setOutlineThickness(2);
	rectangle.setOrigin(50, 50);
	rectangle.setPosition(100, 100);

	start = seconds(stime);
	startTime = stime;

	end = seconds(etime);
	endTime = etime;

	//Restarts the clocks time when the user creates it
	clock.restart();
	elapsed = clock.getElapsedTime();

	//Loads the proper font
	if (!font.loadFromFile("Segment7Standard.otf"))
	{
		cout << "error laoding font";
	}
	text.setFont(font);
	text.setCharacterSize(48);
	text.setFillColor(Color::Red);
	text.setPosition(0.0, 0.0);

	this->push_back(rectangle);
	this->push_back(text);
}

/*
* counter constructor
* @param:
*	float stime, etime, xCord, yCord
*/
counter::counter(float stime, float etime, float xCord, float yCord) {
	rectangle.setSize(Vector2f(100, 100));
	rectangle.setFillColor(Color::Black);
	rectangle.setOutlineColor(Color::Green);
	rectangle.setOutlineThickness(2);
	rectangle.setOrigin(50, 50);
	rectangle.setPosition(100, 100);

	start = seconds(stime);
	startTime = stime;

	end = seconds(etime);
	endTime = etime;

	//Restarts the clocks time when the user creates it
	clock.restart();
	elapsed = clock.getElapsedTime();

	//Loads the proper font
	if (!font.loadFromFile("Segment7Standard.otf"))
	{
		cout << "error laoding font";
	}
	text.setFont(font);
	text.setCharacterSize(48);
	text.setFillColor(Color::Red);
	text.setPosition(xCord, yCord);

	this->push_back(rectangle);
	this->push_back(text);
}

/*
* Function: getTime
* 	calculates the time and returns it to print to screen
* @param:
*	none
* @returns:
*   Text
*/
void counter::updateTime() {
	if (startTime > endTime) { //decrement time test
		elapsed = clock.getElapsedTime();
		time = start.asSeconds() - elapsed.asSeconds();
		text.setString(to_string(time));
	}
	else if (startTime > 0) { //increment time test
		elapsed = clock.getElapsedTime();
		time = start.asSeconds() - elapsed.asSeconds();
		text.setString(to_string(time));
	}
	else { //decrement time test
		elapsed = clock.getElapsedTime();
		time = start.asSeconds() + elapsed.asSeconds();
		text.setString(to_string(time));
	}
	return;
}