#include <SFML/Graphics.hpp>

using namespace sf;

struct golCell {
	bool isAlive;
	int neighborCount;
	RectangleShape Rect;
	int Width;
	int Height;

	golCell() {
		Width = 10;
		Height = 10;
		Rect.setSize(sf::Vector2f(Width, Height));
		Rect.setFillColor(Color::Green);
		Rect.setOutlineColor(Color::Black);
		Rect.setOutlineThickness(1);
	}

	void setCellPos(int x, int y) {
		Rect.setPosition(x*Width, y*Height);
	}

};

struct gameOfLife {
	int Width;
	int Height;
	int frameRate;
	int frameCount;

	RenderWindow Window;
	golCell** World;
	gameOfLife(int width, int height) {
		Width = width;
		Height = height;
		Window.create(VideoMode(Width, Height), "Game of Life");

		World = new golCell*[height];

		for (int i = 0; i<height; i++) {
			World[i] = new golCell[width];
			for (int j = 0; j<width; j++) {
				World[i][j].setCellPos(i, j);
			}
		}
	}

	void drawWorld() {
		Window.clear();
		for (int i = 0; i<Height; i++) {
			for (int j = 0; j<Width; j++) {
				Window.draw(World[i][j].Rect);
			}
		}
		Window.display();
	}
};



int main() {

	gameOfLife Gol(500, 500);

	Gol.frameRate = 5;
	Gol.frameCount = Gol.frameRate;

	while (Gol.Window.isOpen())
	{
		Event event;
		while (Gol.Window.pollEvent(event))
		{
			if (Gol.frameCount == Gol.frameRate) {
				Gol.drawWorld();
				Gol.frameCount = 0;
			}
			if (event.type == Event::Closed)
				Gol.Window.close();
		}

		Gol.frameCount++;
	}

	return 0;
}