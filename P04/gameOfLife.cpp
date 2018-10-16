/*
*@author Daniel DayCee Duncan
*@version 1.1 10/15/18
*@github droidfanatic
*/

#include <fstream>
#include <SFML/Graphics.hpp>
#include "gameOfLife.h"
#include "golCell.h"

using namespace std;
using namespace sf;

//Public

/*
* GameOfLife Constructor extends sfml WindowRef
* @param:
*    RenderWindow : a reference to our sfml window
*
*/
gameOfLife::gameOfLife(RenderWindow &thatWindow) : WindowRef(thatWindow) {
	Rows = 30;
	Cols = 20;
	init();
}

/*
* GameOfLife Constructor extends sfml WindowRef
* @param:
*    RenderWindow : a reference to our sfml window
*    int rows : num of rows in board
*    int cols : num of cols in board
*
*/
gameOfLife::gameOfLife(RenderWindow &thatWindow, int rows, int cols) : WindowRef(thatWindow) {
	Rows = rows;
	Cols = cols;
	init();
}

/*
* Function: populate
* 	reads data file and populates with a predetermined set
* @param:
*	string
* @returns:
*   none
*/
void gameOfLife::populate(string pop) {

	string line;
	char cval = '0';
	int ival = 0;

	ifstream infile;
	infile.open(pop);

	infile >> Rows >> Cols;

	for (int i = 0; i < Rows; i++) {
		infile >> line;
		for (int j = 0; j < Cols; j++) {

			cval = line[j];
			ival = (int)cval - 48;

			World[i][j].alive = ival;
			World[i][j].neighbors = 0;

			World[i][j].rect.setSize(Vector2f(CELLSIZE, CELLSIZE));
			World[i][j].rect.setPosition((i + 1)*CELLSIZE, (j + 1)*CELLSIZE);

			if (World[i][j].isAlive() == 1) {
				World[i][j].rect.setFillColor(Color::Green);
			}
			else {
				World[i][j].rect.setFillColor(Color::Black);
			}
		}
	}

	infile.close();
}

/*
* Function: populate
* 	reads data file and populates with a predetermined set
* @param:
*	char*
* @returns:
*   none
*/
void gameOfLife::populate(char* pop) {

	string line;
	char cval = '0';
	int ival = 0;

	ifstream infile;
	infile.open(pop);

	infile >> Rows >> Cols;

	for (int i = 0; i < Rows; i++) {
		infile >> line;
		for (int j = 0; j < Cols; j++) {

			cval = line[j];
			ival = (int)cval - 48;

			World[i][j].alive = ival;
			World[i][j].neighbors = 0;

			World[i][j].rect.setSize(Vector2f(CELLSIZE, CELLSIZE));
			World[i][j].rect.setPosition((i + 1)*CELLSIZE, (j + 1)*CELLSIZE);

			if (World[i][j].isAlive() == 1) {
				World[i][j].rect.setFillColor(Color::Green);
			}
			else {
				World[i][j].rect.setFillColor(Color::Black);
			}
		}
	}

	countNeighbors();
	infile.close();
}

/*
* Function: run
* 	runs several funtions a user defined number of times
* @param:
*	RenderWindow : a reference to our sfml window
*	int
* @returns:
*   none
*/
void gameOfLife::run(RenderWindow &thatWindow, int numGen) {

	for (int i = 0; i < numGen; i++) {
		generate();
		countNeighbors();
		thatWindow.clear();
		printBoard();

		if (frameCount % frameRate == 0) {
			thatWindow.display();
		}

		frameCount++;
	}
}

/*
* Function: print
* 	prints header and 2d array to outfile 
* @param:
*	string
* @returns:
*   none
*/
void gameOfLife::print(string fout) {

	ofstream outfile;
	outfile.open(fout);
	
	outfile << "/*\n";
	outfile << "*@author Daniel DayCee Duncan\n";
	outfile << "*@version 1.1 10/15/18\n";
	outfile << "*@github droidfanatic\n";
	outfile << "*/\n\n";

	for (int i = 0; i < Rows; i++) {
		for (int j = 0; j < Cols; j++) {
			outfile << World[i][j].isAlive();
		}
		outfile << endl;
	}

	outfile.close();
}

/*
* Function: print
* 	prints header and 2d array to outfile
* @param:
*	char*
* @returns:
*   none
*/
void gameOfLife::print(char* fout) {

	ofstream outfile;
	outfile.open(fout);

	outfile << "/*\n";
	outfile << "*@author Daniel DayCee Duncan\n";
	outfile << "*@version 1.1 10/15/18\n";
	outfile << "*@github droidfanatic\n";
	outfile << "*/\n\n";

	for (int i = 0; i < Rows; i++) {
		for (int j = 0; j < Cols; j++) {
			outfile << World[i][j].isAlive();
		}
		outfile << endl;
	}

	outfile.close();
}


//Private

/*
* Creates the game board, resets it (0's it out)
*/
void gameOfLife::init(){
	World = new golCell *[Rows];
	NextGen = new golCell *[Rows];

	for (int i = 0; i < Rows; i++) {
		World[i] = new golCell[Cols];
		NextGen[i] = new golCell[Cols];
	}

	resetBoards();
}

/*
* Function: onWorld
* 	determines whether whether the cell is on or off the world
* @param:
*	int r
*	int c
* @returns:
*   bool
*/
bool gameOfLife::onWorld(int r, int c) {
	if (r == -1 || c == -1)
		return false;
	else
		return true;
}

/*
* Function: countNeighbors
* 	counts the alive neighbors around a cell
* @param:
*	none
* @returns:
*   none
*/
void gameOfLife::countNeighbors() {
	int nCount = 0;

	for (int i = 0; i < Rows; i++) {
		for (int j = 0; j < Cols; j++) {
			for (int k = i - 1; k <= i + 1; k++) {
				for (int p = j - 1; p <= j + 1; p++) {
					if (k == i && j == p) {
						continue;
					}

					if (onWorld(k, p) && World[k][p].isAlive()) {
						nCount++;
					}
				}
			}
			World[i][j].neighbors = nCount;
			nCount = 0;
		}
	}
}

/*
* Function: resetBoards
* 	resets both boards to all 0's
* @param:
*	none
* @returns:
*   none
*/
void gameOfLife::resetBoards(){
	for (int i = 0; i < Rows; i++) {
		for (int j = 0; j < Cols; j++) {
			World[i][j].alive = 0;
			World[i][j].neighbors = 0;
			NextGen[i][j].alive = 0;
			NextGen[i][j].neighbors = 0;
		}
	}
}

/*
* Function: applyTransition
* 	Sets the World 2D array equal to the NextGen 2D array
* @param:
*	none
* @returns:
*   none
*/
void gameOfLife::applyTransition() {
	for (int i = 0; i < Rows; i++) {
		for (int j = 0; j < Cols; j++) {
			World[i][j].alive = NextGen[i][j].isAlive();
			World[i][j].neighbors = NextGen[i][j].getNeighbors();

			World[i][j].rect.setSize(Vector2f(CELLSIZE, CELLSIZE));
			World[i][j].rect.setPosition((i + 1)*CELLSIZE, (j + 1)*CELLSIZE);

			if (World[i][j].isAlive() == 1) {
				World[i][j].rect.setFillColor(Color::Green);
			}
			else {
				World[i][j].rect.setFillColor(Color::Black);
			}
		}
	}
}

/*
* Function: generate
* 	applies rules to World 2D array to creat NextGen 2D array
* @param:
*	none
* @returns:
*   none
*/
void gameOfLife::generate() {
	for (int i = 0; i < Rows; i++) {
		for (int j = 0; j < Cols; j++) {
			underKill(i, j);
			overKill(i, j);
			revive(i, j);
			sustain(i, j);
		}
	}

	applyTransition();
}

/*
* Function: underKill
* 	kills any cell that is under populated
* @param:
*	int r
*	int c
* @returns:
*   none
*/
void gameOfLife::underKill(int r, int c) {
	if (World[r][c].getNeighbors() < 2)
		NextGen[r][c].alive = 0;
	else
		return;
}

/*
* Function: overKill
* 	kills any cell that is over populated
* @param:
*	int r
*	int c
* @returns:
*   none
*/
void gameOfLife::overKill(int r, int c) {
	if (World[r][c].getNeighbors() > 3)
		NextGen[r][c].alive = 0;
	else
		return;
}

/*
* Function: revive
* 	revives any call that has 3 neighbors
* @param:
*	int r
*	int c
* @returns:
*   none
*/
void gameOfLife::revive(int r, int c) {
	if (World[r][c].getNeighbors() == 3)
		NextGen[r][c].alive = 1;
	else
		return;
}

/*
* Function: sustain
* 	sustains any cell that is properly populated
* @param:
*	int r
*	int c
* @returns:
*   none
*/
void gameOfLife::sustain(int r, int c) {
	if (World[r][c].getNeighbors() == 2 && World[r][c].isAlive())
		NextGen[r][c].alive = 1;
	else
		return;
}

/*
* Function: printBoard
* 	Prints board to an sfml window
* @param:
*	None
* @returns:
*   None
*/
void gameOfLife::printBoard() {
	int x = 0;
	int y = 0;
	for (int i = 0; i < Rows; i++) {
		for (int j = 0; j < Cols; j++) {
			if (World[i][j].alive) {
				y = (i + 1) * CELLSIZE;
				x = (j + 1) * CELLSIZE;
				WindowRef.draw(World[i][j].rect);
			}
		}
	}
}
