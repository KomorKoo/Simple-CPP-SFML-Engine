#include <iostream>

#include "Button.hpp"

void Button::updateText() {
	m_buttonText.setOrigin(m_buttonText.getGlobalBounds().width / 2.0f,
			       m_buttonText.getGlobalBounds().height / 1.15f);
}

Button::Button(const sf::Vector2f& pos, ButtonSize size) {
	switch (size) {
		case ButtonSize::Small:
			m_buttonShape.setSize({ 384, 92 });
			break;

		case ButtonSize::Narrow:
			m_buttonShape.setSize({ 384, 128 });
			break;

		case ButtonSize::Wide:
			m_buttonShape.setSize({ 512, 64 });
			break;

		case ButtonSize::Big:
			m_buttonShape.setSize({ 512, 128 });
			break;
	}

	setPosition(pos);
	m_buttonShape.setOrigin(m_buttonShape.getSize().x / 2.0f, m_buttonShape.getSize().y / 2.0f);
	updateText();
}

Button::Button(const Button& other) {
	m_buttonShape = other.m_buttonShape;
	m_buttonText  = other.m_buttonText;
	m_function    = other.m_function;
}

void Button::setFunction(std::function<void(void)> function) {
	m_function = function;
}

void Button::setText(const std::string& text) {
	m_buttonText.setString(text);
	updateText();
}

void Button::setTexture(const sf::Texture& texture) {
	m_buttonShape.setTexture(&texture);
}

bool Button::handleEvents(const sf::RenderWindow& window, sf::Event ev) {
	auto pos = sf::Mouse::getPosition(window);

	if (m_buttonShape.getGlobalBounds().contains(pos.x, pos.y)) {
		if (ev.type == sf::Event::MouseButtonPressed) {
			if (ev.mouseButton.button == sf::Mouse::Left) {
				m_function();

				return true;
			}
		}
	}

	return false;
}

void Button::render(sf::RenderTarget& renderer) {
	renderer.draw(m_buttonShape);
	renderer.draw(m_buttonText);
}

void Button::setPosition(const sf::Vector2f& pos) {
	m_buttonPos = pos;

	m_buttonShape.setPosition(pos);
	m_buttonText.setPosition(pos);

	updateText();
}

sf::Vector2f Button::getSize() const {
	return m_buttonShape.getSize();
}

sf::Vector2f Button::getPos() const {
	return m_buttonShape.getPosition();
}
