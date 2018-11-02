/*
*Course: CMPS 2143 - OOP
*Program: Assignment 05
*
*Purpose: a sfml clock that can be used to count up or down
*
*@author Daniel DayCee Duncan
*@version 1.1 11/2/18
*@github droidfanatic
*/

#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

using namespace std;
using namespace sf;

class counter : public Text, Font{
private:
	float startTime;
	float endTime;
	float time;

	Clock clock; //creates a clock that has already started counting
	Time start;
	Time end;
	Time elapsed;
	Text text;
	Font font;


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
	counter(float stime, float etime);

/*
* counter constructor
* @param:
*		float stime, etime, xCord, yCord
*/
	counter(float stime, float etime, float xCord, float yCord);

/*
* Function: getTime
* 	calculates the time and returns it to print to screen
* @param:
*	none
* @returns:
*   Text
*/
	Text getTime();
};