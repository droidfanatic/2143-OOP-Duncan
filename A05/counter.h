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

	Clock clock;
	Time start;
	Time end;
	Time elapsed;
	Text text;
	Font font;


public:
	counter();
	counter(float stime, float etime);
	counter(float stime, float etime, float xCord, float yCord);
	Text getTime();
};