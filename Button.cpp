#include "Button.h"
#include <iostream>
#include <string>
#include <vector>
namespace GUI {
	ButtonGrid ButtonGrid::createGRID()
	{
		ButtonGrid grid;
		float yOffset = 220;
		float xOffset = 0;
		for (std::size_t i = 0; i < 20; ++i) {
			if (i % 4 == 0) {
				yOffset += 80;
				xOffset = 0;
			}
			Button button({ xOffset, yOffset });
			//button.buttonShape.setPosition(xOffset, yOffset);
			//assert(button.buttonShape.getPosition().x == 0);
			xOffset += 115;
			grid.buttonGrid.push_back(button);
		}
		return grid;
	}

	void ButtonGrid::drawGRID(sf::RenderWindow& window, const ButtonGrid& grid)
	{
		for (Button item : grid.buttonGrid)
		{
			window.draw(item.buttonShape);
		}
	}
	void ButtonGrid::click(sf::RenderWindow& window, GUI::ButtonGrid& grid, const sf::Event& event)
	{
		for (int i = 0; i < 20; ++i) {
			static std::string s;
			const auto START_X = grid[i].buttonShape.getPosition().x;
			const auto END_X = grid[i].buttonShape.getPosition().x + grid[i].buttonShape.getSize().x;
			const auto START_Y = grid[i].buttonShape.getPosition().y;
			const auto END_Y = grid[i].buttonShape.getPosition().y + grid[i].buttonShape.getSize().y;



			if (sf::Mouse::getPosition(window).x > START_X &&
				sf::Mouse::getPosition(window).x < END_X &&
				sf::Mouse::getPosition(window).y > START_Y &&
				sf::Mouse::getPosition(window).y < END_Y &&
				event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
			{
				std::string cop{};
				switch (i) {
				case 0:
					cop = "(";
					s += "(";
					std::cout << cop;
					break;
				case 1:
					cop = ")";
					s += ")";
					std::cout << cop;
					break;
				case 2:
					cop = "B";
					s.erase(s.length() - 1, 1);
					std::cout << "\b \b";
					break;
				case 3:
					cop = "/";
					s += "/";
					std::cout << cop;
					break;
				case 4:
					cop = "7";
					s += "7";
					std::cout << cop;
					break;
				case 5:
					cop = "8";
					s += "8";
					std::cout << cop;
					break;
				case 6:
					cop = "9";
					s += "9";
					std::cout << cop;
					break;
				case 7:
					cop = "*";
					s += "*";
					std::cout << cop;
					break;
				case 8:
					cop = "4";
					s += "4";
					std::cout << cop;
					break;
				case 9:
					cop = "5";
					s += "5";
					std::cout << cop;
					break;
				case 10:
					cop = "6";
					s += "6";
					std::cout << cop;
					break;
				case 11:
					cop = "-";
					s += "-";
					std::cout << cop;
					break;
				case 12:
					cop = "1";
					s += "1";
					std::cout << cop;
					break;
				case 13:
					cop = "2";
					s += "2";
					std::cout << cop;
					break;
				case 14:
					cop = "3";
					s += "3";
					std::cout << cop;
					break;
				case 15:
					cop = "+";
					s += "+";
					std::cout << cop;
					break;
					/*case 16:
						if (s[0] == '-')
							s.erase(0, 1);
						else
							s.insert(0, "-");
						cop = s[0];
						std::cout << cop;
						break;
						*/
				case 17:
					cop = "0";
					s += "0";
					std::cout << cop;
					break;
				case 18:
					cop = ".";
					s += ".";
					std::cout << cop;
					break;
				case 19:
					cop = "=";
					std::cout << ' ' << s;
					break;


				}
			}

			if (event.type == sf::Event::TextEntered and event.text.unicode == 32) {
				std::cout << ' ' << s;
				s = {};
			}

		}
	}
	void ButtonGrid::text(sf::RenderWindow& window)
	{
		std::vector<sf::Text> textOfButtons{};
		std::vector<std::string> glifs{ "(", " )", "B", "/", "7", "8", "9", "*", "4", "5", "6", "-", "1", "2", "3", "+", "±", "0", "." , "=" };
		std::vector<sf::Text> vec{};
		sf::Font font;
		font.loadFromFile("C:\\Users\\Sakhil\\Downloads\\arial\\arial.ttf");
		sf::Text text;
		text.setFont(font);
		text.setCharacterSize(60);
		text.setFillColor(sf::Color(100, 0, 100));
		text.setStyle(sf::Text::Bold);
		text.setCharacterSize(60);
		float yOffset = 300;
		float xOffset = 35;
		for (std::size_t i = 0; i < 20; ++i) {
			if (i % 4 == 0 and i != 0) {
				yOffset += 80;
				xOffset = 35;
			}
			if (glifs[i] == "*") {
				text.setPosition(xOffset + 5, yOffset + 10);
				text.setString(glifs[i]);
				vec.push_back(text);
				window.draw(text);
				xOffset += 115;
				continue;
			}
			if (glifs[i] == ".") {
				text.setPosition(xOffset + 10, yOffset);
				text.setString(glifs[i]);
				vec.push_back(text);
				window.draw(text);
				xOffset += 115;
				continue;
			}
			text.setPosition(xOffset, yOffset);
			text.setString(glifs[i]);
			xOffset += 115;
			vec.push_back(text);
			window.draw(text);
		}
	}
}