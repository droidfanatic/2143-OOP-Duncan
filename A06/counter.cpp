/*
*@author Daniel DayCee Duncan
*@version 1.1 11/14/18
* @github droidfanatic
*/

#include "counter.h"

/*
* counter constructor
* @param:
*	none
*/
counter::counter() {
	coordX = 50;
	coordY = 50;

	frameRate = 0;

	//-X coordinate wall collision detection
	if (coordX == 50) {
		bounceX = -1;
	}
	//+X coordinate wall collision detection
	else if (coordX == 450) {
		bounceX = 1;
	}

	//-Y coordinate wall collision detection
	if (coordY == 50) {
		bounceY = -1;
	}
	//+Y coordinate wall collision detection
	else if (coordY == 350) {
		bounceY = 1;
	}

	start = seconds(0.0);
	startTime = 0.0;

	end = seconds(50.0);
	endTime = 0.0;

	//Restarts the clocks time when the user creates it
	clock.restart();
	elapsed = clock.getElapsedTime();

	//Sets time to the starting time
	time = start.asSeconds();
	text.setString(to_string(time));

	//Loads the proper font
	if (!font.loadFromFile("Segment7Standard.otf"))
	{
		cout << "error laoding font";
	}

	//sets parameters for rectangle and text
	setRecParam();
	setTextParam();

	//pushes drawable items onto the group draw vector
	this->push_back(rectangle);
	this->push_back(text);
}

/*
* counter constructor
* @param:
*	float stime, etime
*/
counter::counter(int stime, int etime) {
	coordX = 50.0;
	coordY = 50.0;

	frameRate = 0;
	
	//-X coordinate wall collision detection
	if (coordX == 50) {
		bounceX = -1;
	}
	//+X coordinate wall collision detection
	else if (coordX == 450) {
		bounceX = 1;
	}

	//-Y coordinate wall collision detection
	if (coordY == 50) {
		bounceY = -1;
	}
	//+Y coordinate wall collision detection
	else if (coordY == 350) {
		bounceY = 1;
	}

	start = seconds(stime);
	startTime = stime;

	end = seconds(etime);
	endTime = etime;

	//Restarts the clocks time when the user creates it
	clock.restart();
	elapsed = clock.getElapsedTime();

	//Sets time to the starting time
	time = start.asSeconds();
	text.setString(to_string(time));

	//Loads the proper font
	if (!font.loadFromFile("Segment7Standard.otf"))
	{
		cout << "error laoding font";
	}

	//sets parameters for rectangle and text
	setRecParam();
	setTextParam();
	
	//pushes drawable items onto the group draw vector
	this->push_back(rectangle);
	this->push_back(text);
}

/*
* counter constructor
* @param:
*	float stime, etime, xCoord, yCoord
*/
counter::counter(int stime, int etime, float xCoord, float yCoord) {
	coordX = xCoord;
	coordY = yCoord;

	frameRate = 0;

	//-X coordinate wall collision detection
	if (coordX == 50) {
		bounceX = -1;
	}
	//+X coordinate wall collision detection
	else if (coordX == 450) {
		bounceX = 1;
	}

	//-Y coordinate wall collision detection
	if (coordY == 50) {
		bounceY = -1;
	}
	//+Y coordinate wall collision detection
	else if (coordY == 350) {
		bounceY = 1;
	}

	start = seconds(stime);
	startTime = stime;

	end = seconds(etime);
	endTime = etime;

	//Restarts the clocks time when the user creates it
	clock.restart();
	elapsed = clock.getElapsedTime();

	//Sets time to the starting time
	time = start.asSeconds();
	text.setString(to_string(time));

	//Loads the proper font
	if (!font.loadFromFile("Segment7Standard.otf"))
	{
		cout << "error laoding font";
	}

	//sets parameters for rectangle and text
	setRecParam();
	setTextParam();

	//pushes drawable items onto the group draw vector
	this->push_back(rectangle);
	this->push_back(text);
}

/*
* Function: updateTime
* 	calculates the time and returns it to print to screen
* @param:
*	none
* @returns:
*   none
*/
void counter::updateTime() {

	if (time == endTime) { //keeps the time from going past end time
		time = end.asSeconds();
		text.setString(to_string(time));
	}
	else if (startTime > endTime) { //decrement time test
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

	//this changes the location of the clock and rectangle every 25 loops
	if (frameRate == 25) {
		bounce();
		frameRate = 0;
	}
	else {
		frameRate++;
	}

	return;
}

/*
* Function: setColors
* 	sets the colors of the clock, the background, and the border
* @param:
*	color clock, background, border
* @returns:
*   none
*/
void counter::setColors(Color cClock, Color cBackground, Color cBorder) {
	text.setFillColor(cClock);
	rectangle.setFillColor(cBackground);
	rectangle.setOutlineColor(cBorder);
}

/*
* Function: atEnd
* 	checks to see if the clock has reached it's end time
* @param:
*	none
* @returns:
*   none
*/
bool counter::atEnd() {
	if (time == endTime) {
		return true;
	}
	else return false;
}

/*
* Function: bounce
* 	causes the clocks and background to bounce around the screen
* @param:
*	none
* @returns:
*   none
*/
void counter::bounce() {
	//-X coordinate wall collision detection
	if (coordX == 50) {
		bounceX = -1;
	}
	//+X coordinate wall collision detection
	else if (coordX == 450) {
		bounceX = 1;
	}

	//-Y coordinate wall collision detection
	if (coordY == 50) {
		bounceY = -1;
	}
	//+Y coordinate wall collision detection
	else if (coordY == 350) {
		bounceY = 1;
	}

	//changes location
	coordX -= bounceX;
	coordY -= bounceY;

	//set location
	rectangle.setPosition(coordX, coordY);
	text.setPosition(coordX, coordY);
}

/*
* Function: setRecParam
* 	sets the rectangle's color, size, origin, and position
* @param:
*	none
* @returns:
*   none
*/
void counter::setRecParam() {
	rectangle.setSize(Vector2f(100, 100));
	rectangle.setFillColor(Color::Black);
	rectangle.setOutlineColor(Color::Green);
	rectangle.setOutlineThickness(2);
	rectangle.setOrigin(50, 50);
	rectangle.setPosition(coordX, coordY);
	return;
}

/*
* Function: setTextParam
* 	sets the rectangle's color, size, origin, and position
* @param:
*	none
* @returns:
*   none
*/
void counter::setTextParam() {
	text.setFont(font);
	text.setCharacterSize(48);
	text.setFillColor(Color::Red);
	text.setOrigin(24, 24);
	text.setPosition(coordX, coordY);
	return;
}