/*
*@author Daniel DayCee Duncan
*@version 1.1 10/15/18
*@github droidfanatic
*/

#include <string>
#include <SFML/Graphics.hpp>
#include "golCell.h"

using namespace std;
using namespace sf;

#define CELLSIZE 10

class gameOfLife {
private:
	golCell **World;
	golCell **NextGen;
	int Rows;
	int Cols;
	RenderWindow &WindowRef;
	int frameRate = 5;
	int frameCount = 0;

	void init();
	bool onWorld(int r, int c);
	void countNeighbors();
	void resetBoards();
	void applyTransition();
	void generate();

	//Game Of Life Rules
	void underKill(int r, int c);
	void overKill(int r, int c);
	void revive(int r, int c);
	void sustain(int r, int c);

public:
	gameOfLife(RenderWindow &thatWindow);
	gameOfLife(RenderWindow &thatWindow,int rows, int cols);
	void populate(string pop);
	void populate(char* pop);
	void run(RenderWindow &thatWindow, int numGen);
	void print(string fout);
	void print(char* fout);

	//prints to sfml window
	void printBoard();
};