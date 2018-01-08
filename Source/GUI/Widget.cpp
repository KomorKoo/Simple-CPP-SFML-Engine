#include "Widget.hpp"
#include "../ResourceHandling/ResourceHolder.hpp"

bool Widget::Rectangle::isRolledOn(const sf::RenderWindow& window) const {
	auto pos = sf::Mouse::getPosition(window);

	return getGlobalBounds().contains(pos.x, pos.y);
}

bool Widget::Rectangle::isClickedOn(const sf::RenderWindow& window, sf::Event ev) {
	if (isRolledOn(window)) {
		if (ev.type == sf::Event::MouseButtonPressed)
			return ev.mouseButton.button == sf::Mouse::Left;
	}

	return false;
}

Widget::Text::Text() {
	setCharacterSize(40);
	setFillColor    (sf::Color::White);
	setOutlineColor (sf::Color::Black);
	setFont		    (ResourceHolder::get().fonts.get("Inconsolata"));
}
