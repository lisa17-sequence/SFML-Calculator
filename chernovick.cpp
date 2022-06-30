#include <SFML/Graphics.hpp>
#include <iostream>
#include<vector>
#include "Button.h"
int main()
{

	sf::RenderWindow window(sf::VideoMode(455, 895), "my window! <3 =^-^=");
	window.setPosition(sf::Vector2i(500, 100));
	GUI::ButtonGrid a = a.createGRID();

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
		a.drawGRID(window, a);
		a.text(window);
		window.display();
	}
	return 0;
}