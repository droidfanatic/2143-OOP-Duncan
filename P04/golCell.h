/*
*@author Daniel DayCee Duncan
*@version 1.1 10/15/18
*@github droidfanatic
*/

#pragma once

#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

/*
* golCell : A single instance of a cell in a Game of Life array
* @Extends:
*   sf::Drawable
* @Data-Elements:
* 	RectangleShape rect;	// sfml rectangle type
* 	bool alive;		// is cell alive or not
*	int neighbors;	// number of neighbors alive
* @Methods:
* 	void draw(RenderTarget& target, RenderStates state) const
*/

class golCell : public Drawable {
public:
	RectangleShape rect;
	bool alive;
	int neighbors;

	golCell();

	bool isAlive();
	int getNeighbors();

	/*
	* void draw: draws an SFML shape to an SFML window.
	*/
	void draw(RenderTarget& target, RenderStates state) const;
};