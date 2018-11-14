/*
*@author Daniel DayCee Duncan
*@version 1.1 11/14/18
* @github droidfanatic
*/

#include "Group.h"
#include <iostream>
#include <string>

class counter : public Group {
private:
	int coordX;
	int coordY;
	int bounceX;
	int bounceY;

	int frameRate; // controls the speed of bouncing

	int startTime;
	int endTime;
	int time;

	Clock clock; //creates a clock that has already started counting
	Time start;
	Time end;
	Time elapsed;
	Text text;
	Font font;

	RectangleShape rectangle;

/*
* Function: setRecParam
* 	sets the rectangle's color, size, origin, and position
* @param:
*	none
* @returns:
*   none
*/
	void setRecParam();

/*
* Function: setTextParam
* 	sets the text's color, size, origin, and position
* @param:
*	none
* @returns:
*   none
*/
	void setTextParam();

/*
* Function: bounce
* 	causes the clocks and background to bounce around the screen
* @param:
*	none
* @returns:
*   none
*/
	void bounce();

public:
/*
* counter constructor
* @param:
*		none
*/
	counter();

/*
* counter constructor
* @param:
*		float stime, etime
*/
	counter(int stime, int etime);

/*
* counter constructor
* @param:
*		float stime, etime, xCoord, yCoord
*/
	counter(int stime, int etime, float xCoord, float yCord);

/*
* Function: updateTime
* 	calculates the time and returns it to print to screen
* @param:
*	none
* @returns:
*   none
*/
	void updateTime();

/*
* Function: setColors
* 	sets the colors of the clock, the background, and the border
* @param:
*	color clock, background, border
* @returns:
*   none
*/
	void setColors(Color cClock, Color cBackground, Color cBorder);

/*
* Function: atEnd
* 	checks to see if the clock has reached it's end time
* @param:
*	none
* @returns:
*   bool
*/
	bool atEnd();
};