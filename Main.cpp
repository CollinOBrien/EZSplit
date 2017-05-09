#include "Timer.h"
#include "Layout.h"

using namespace std;
using namespace sf;

void keyPressFunction(Timer, Keyboard::Key);

int main()
{
	sf::RenderWindow window(sf::VideoMode(100, 50), "My window");

	sf::Font font;
	if (!font.loadFromFile("arial.ttf"))
	{
		// error...
	}

	sf::Text text;

	// select the font
	text.setFont(font); // font is a sf::Font

	text.setString("0.00");					// set the string to display

	// set the character size
	text.setCharacterSize(24); // in pixels, not points!

							   // set the color
	text.setFillColor(sf::Color::White);

	// set the text style
	text.setStyle(sf::Text::Bold);
	
	Timer timer;

	string num;

	// run the program as long as the window is open
	while (window.isOpen())
	{

			// check all the window's events that were triggered since the last iteration of the loop
			sf::Event event;
			while (window.pollEvent(event))
			{
				// "close requested" event: we close the window
				if (event.type == sf::Event::Closed)
					window.close();

				if (event.type == Event::KeyPressed)
				{
					Keyboard::Key key = event.key.code;
					keyPressFunction(timer, key);
				}

			}

			num = to_string(timer.getElapsedTime().asSeconds());
			text.setString(num);

			window.clear();
			window.draw(text);
			window.display();
		}
	return 0;
}

void keyPressFunction(Timer timer, Keyboard::Key key)
{
	switch (key)
	{
	case Keyboard::Z:
		timer.restart();
		break;
	default:
		break;
	}
}