#pragma once

#include <SFML/Graphics.hpp>
#include<vector>

namespace GUI {
	//std::vector<sf::RectangleShape> createGRID();

	class Button
	{

	public:
		Button(sf::Text text) : buttonText{ text }
		{
			buttonShape.setSize({ 110, 75 });
			buttonShape.setFillColor(sf::Color (209, 237, 242));
		}
		Button(sf::Vector2f place)
		{
			buttonShape.setSize({ 110, 75 });
			buttonShape.setPosition(place);
			buttonShape.setFillColor(sf::Color(209, 237, 242));
		}

		Button(const Button& other) = default;
		Button(Button&& other) = default;

		Button& operator=(const Button& button) = default;
		Button& operator=(Button&& button) = default;

		Button() = default;
		~Button() = default;
	public:
		sf::RectangleShape buttonShape;
		sf::Text buttonText;
	};

	class ButtonGrid
	{
	public:
		ButtonGrid(std::vector<Button> buttonGrid_) : buttonGrid{ buttonGrid_ }
		{}
		ButtonGrid() = default;

		~ButtonGrid() = default;

		ButtonGrid createGRID();
		void drawGRID(sf::RenderWindow& window, const ButtonGrid& grid);

		Button operator[](std::size_t index) { return buttonGrid[index]; }
		ButtonGrid getGrid() const { return buttonGrid; }
	public:
		std::vector<Button> buttonGrid;
		void click(sf::RenderWindow& window, GUI::ButtonGrid& grid, const sf::Event& event);
		void text(sf::RenderWindow& window);
	};
}
