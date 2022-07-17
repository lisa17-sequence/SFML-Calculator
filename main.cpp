#include "Backend/Operation.h"
#include "Backend/StringToRPN.h"
#include <SFML/Graphics.hpp>


#include <iostream>
#include <vector>

#include "GUI/Button.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(455, 695), "Calculator app");
	window.setPosition(sf::Vector2i(500, 100));

	sf::Font font;
	font.loadFromFile("arial.ttf");

	GUI::ButtonGrid a = a.createGRID();
	a.createTypo(font);
	sf::RectangleShape background(sf::Vector2f(460, 730));
	background.setFillColor(sf::Color(0, 0, 94));
	while (window.isOpen())
	{

		sf::Event event;
		while (window.pollEvent(event))
		{ 
			a.click(window, a, event);
			if (event.type == sf::Event::Closed)
				window.close();
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
				window.close();
		}

		window.clear();
		window.draw(background);
		a.drawGRID(window, a);
		a.text(window);
		window.draw(a.input);
		window.display();
	}
	return 0;
}