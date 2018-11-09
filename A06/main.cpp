#include "counter.h"

using namespace std;
using namespace sf;

int main()
{
	RenderWindow window(VideoMode(500, 500), "SFML Clock");

	counter clock(50.0, 0.0);

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(clock);
		clock.updateTime();
		window.display();
	}

	return 0;
}