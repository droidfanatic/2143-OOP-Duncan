/*
*@author Daniel DayCee Duncan
*@version 1.1 10/15/18
*@github droidfanatic
*/

#include <SFML/Graphics.hpp>
#include "golCell.h"

using namespace std;
using namespace sf;

/*
* Constructor
* 	sets alive a neighbor equal to 0 until told otherwise.
* @param:
*	none
* @returns:
*   none
*/
golCell::golCell() {
	alive = 0;
	neighbors = 0;
}

/*
* Function: isAlive
* 	allows users to check if a specific cell is alive
* @param:
*	none
* @returns:
*   bool
*/
bool golCell::isAlive() {
	return alive;
}

/*
* Function: getNeighbors
*	allows users to check the number of alive neighbors of a specific cell
* @param:
*	none
* @returns:
*	int
*/
int golCell::getNeighbors() {
	return neighbors;
}

/*
* void draw: draws an SFML shape to an SFML window.
*/

void golCell::draw(RenderTarget& target, RenderStates state) const {
	target.draw(rect);
}