#pragma once

#include <functional>

#include "Widget.hpp"


enum class ButtonSize {
	Small,
	Narrow,
	Wide,
	Big
};

class Button : public Widget {
	private:
		Rectangle	 m_buttonShape;
		Text		 m_buttonText;
		sf::Vector2f m_buttonPos;

		std::function<void(void)> m_function = []() {};

	private:
		void updateText();

	public:
		Button(const sf::Vector2f& pos, ButtonSize size);
		Button(const Button& other);

		void setFunction(std::function<void(void)> function);
		void setText	(const std::string& text);
		void setTexture	(const sf::Texture& texture);

		bool handleEvents(const sf::RenderWindow& window, sf::Event ev) override;
		void render(sf::RenderTarget& renderer)							override;
		void setPosition(const sf::Vector2f& pos)						override;
		sf::Vector2f getSize() const									override;
		sf::Vector2f getPos() const										override;
};
