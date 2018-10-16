/*
*Course: CMPS 2143 - OOP
*Program: Program 4
*
*Purpose: a solution to conways game of life
*
*@author Daniel DayCee Duncan
*@version 1.1 10/15/18
*@github droidfanatic
*/

#include <SFML/Graphics.hpp>
#include <cstdlib>
#include "gameOfLife.h"

using namespace std;

int main(int argc, char **argv) {
	RenderWindow window(VideoMode(600, 600), "Game of Life");

	gameOfLife G(window, 600, 600); // create with some window size

	//converts command line char value to int
	int numGens = atoi(argv[2]);

	G.populate(argv[1]);
	G.run(window, numGens); // run for argv[2] generations.
	G.print(argv[3]); //prints to output.txt or given output file name
}