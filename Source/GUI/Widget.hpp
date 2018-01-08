#pragma once

#include <SFML/Graphics.hpp>


class Widget {
	protected:
		class Rectangle : public sf::RectangleShape {
			public:
				bool isRolledOn (const sf::RenderWindow& window) const;
				bool isClickedOn(const sf::RenderWindow& window, sf::Event ev);
		};

		class Text : public sf::Text {
			public:
				Text();
		};

	public:
		virtual bool handleEvents(const sf::RenderWindow& window, sf::Event ev) = 0;
		virtual void render(sf::RenderTarget& renderer)				= 0;
		virtual void setPosition(const sf::Vector2f& pos)			= 0;
		virtual sf::Vector2f getSize() const					= 0;
		virtual sf::Vector2f getPos() const					= 0;
};
