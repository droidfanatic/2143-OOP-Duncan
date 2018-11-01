#include "counter.h"

counter::counter() {
	start = seconds(0.0);
	startTime = 0.0;

	end = seconds(50.0);
	endTime = 0.0;

	clock.restart();
	elapsed = clock.getElapsedTime();

	if (!font.loadFromFile("Segment7Standard.otf"))
	{
		cout << "error laoding font";
	}
	text.setFont(font);
	text.setCharacterSize(48);
	text.setFillColor(Color::Red);
	text.setPosition(0.0, 0.0);
}

counter::counter(float stime, float etime) {
	start = seconds(stime);
	startTime = stime;

	end = seconds(etime);
	endTime = etime;

	clock.restart();
	elapsed = clock.getElapsedTime();

	if (!font.loadFromFile("Segment7Standard.otf"))
	{
		cout << "error laoding font";
	}
	text.setFont(font);
	text.setCharacterSize(48);
	text.setFillColor(Color::Red);
	text.setPosition(0.0, 0.0);
}

counter::counter(float stime, float etime, float xCord, float yCord) {
	start = seconds(stime);
	startTime = stime;

	end = seconds(etime);
	endTime = etime;

	clock.restart();
	elapsed = clock.getElapsedTime();

	if (!font.loadFromFile("Segment7Standard.otf"))
	{
		cout << "error laoding font";
	}
	text.setFont(font);
	text.setCharacterSize(48);
	text.setFillColor(Color::Red);
	text.setPosition(xCord, yCord);
}

Text counter::getTime() {
	if (startTime > endTime) {
		elapsed = clock.getElapsedTime();
		time = start.asSeconds() - elapsed.asSeconds();
		text.setString(to_string(time));
	}
	else if (startTime > 0) {
		elapsed = clock.getElapsedTime();
		time = start.asSeconds() - elapsed.asSeconds();
		text.setString(to_string(time));
	}
	else {
		elapsed = clock.getElapsedTime();
		time = start.asSeconds() + elapsed.asSeconds();
		text.setString(to_string(time));
	}
	return text;
}