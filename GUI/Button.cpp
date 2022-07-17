#include "../Backend/StringToRPN.h"
#include "../Backend/Operation.h"
#include "Button.h"

#include <iostream>
#include <string>
#include <vector>

#include <sstream>
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
	std::string dotsCounter = "";
	void ButtonGrid::click(sf::RenderWindow& window, GUI::ButtonGrid& grid, const sf::Event& event)
	{
		std::string si;
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
				if (s == "") {
					input.setString("");
				}
				switch (i) {
				case 0:
					cop = "(";
					s += "(";
					std::cout << cop;
					input.setString(input.getString() + '(');
					break;
				case 1:
					cop = ")";
					s += ")";
					std::cout << cop;
					input.setString(input.getString() + ')');
					break;
				case 2:
					cop = "B";
					if (s == "")
						break;
					s.erase(s.length() - 1, 1);
					std::cout << "\b \b";
					si = input.getString();
					si = si.erase(si.length() - 1, 1);
					input.setString(s);
					break;
				case 3:
					dotsCounter = "";
					cop = "/";
					s += "/";
					std::cout << cop;
					input.setString(input.getString() + '/');
					break;
				case 4:
					cop = "7";
					s += "7";
					std::cout << cop;
					input.setString(input.getString() + '7');
					break;
				case 5:
					cop = "8";
					s += "8";
					std::cout << cop;
					input.setString(input.getString() + '8');
					break;
				case 6:
					cop = "9";
					s += "9";
					std::cout << cop;
					input.setString(input.getString() + '9');
					break;
				case 7:
					dotsCounter = "";
					cop = "*";
					s += "*";
					std::cout << cop;
					input.setString(input.getString() + '*');
					break;
				case 8:
					cop = "4";
					s += "4";
					std::cout << cop;
					input.setString(input.getString() + '4');
					break;
				case 9:
					cop = "5";
					s += "5";
					std::cout << cop;
					input.setString(input.getString() + '5');
					break;
				case 10:
					cop = "6";
					s += "6";
					std::cout << cop;
					input.setString(input.getString() + '6');
					break;
				case 11:
					dotsCounter = "";
					cop = "-";
					s += "-";
					std::cout << cop;
					input.setString(input.getString() + '-');
					break;
				case 12:
					cop = "1";
					s += "1";
					std::cout << cop;
					input.setString(input.getString() + '1');
					break;
				case 13:
					cop = "2";
					s += "2";
					std::cout << cop;
					input.setString(input.getString() + '2');
					break;
				case 14:
					cop = "3";
					s += "3";
					std::cout << cop;
					input.setString(input.getString() + '3');
					break;
				case 15:
					dotsCounter = "";
					cop = "+";
					s += "+";
					std::cout << cop;
					input.setString(input.getString() + '+');
					break;
				case 16:
					dotsCounter = "";
					cop = "^";
					s += "^";
					std::cout << cop;
					input.setString(input.getString() + '^');
					break;
				case 17:
					cop = "0";
					s += "0";
					std::cout << cop;
					input.setString(input.getString() + '0');
					break;
				case 18:
					if (dotsCounter.find(".") == std::string::npos) {
						dotsCounter += '.';
						cop = ".";
						s += ".";
						std::cout << cop;
						input.setString(input.getString() + '.');
						break;
					}
					else {
						cop = "";
						s += "";
						std::cout << cop;
						input.setString(input.getString() + "");
						break;
					}
				case 19:
					dotsCounter = "";
					cop = "=";
					if (s == "")
						break;
					std::cout << " ";
					StringToRPN tempRPN;
					Operation outcomestr(tempRPN.RPN(s));
					input.setString(outcomestr.getResult());
					s = "";
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
		std::vector<std::string> glifs{ "(", " )", "B", "/", "7", "8", "9", "*", "4", "5", "6", "-", "1", "2", "3", "+", "^", "0", "." , "=" };
		std::vector<sf::Text> vec{};
		sf::Font font;
		font.loadFromFile("arial.ttf");
		sf::Text text;
		text.setFont(font);
		text.setCharacterSize(60);
		text.setFillColor(sf::Color(255, 255, 255));
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
		//window.draw(input);
	}
}