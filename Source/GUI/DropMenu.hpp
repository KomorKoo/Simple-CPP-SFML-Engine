#pragma once

#include <memory>
#include <vector>

#include "Button.hpp"

class DropMenu : public Widget {
	private:
		std::vector<std::unique_ptr<Button>> m_buttons;
		Button*				     m_p_mButton;
		bool				     m_isActive;

	public:
		DropMenu(Button& button);

		void addItem(Button button);
		void switchActivity();

		bool handleEvents(const sf::RenderWindow& window, sf::Event ev) override;
		void render(sf::RenderTarget& renderer)				override;
		void setPosition(const sf::Vector2f& pos)			override;
		sf::Vector2f getSize() const					override;
		sf::Vector2f getPos() const					override;
};
