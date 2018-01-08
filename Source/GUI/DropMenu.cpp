#include "DropMenu.hpp"

#include <iostream>

DropMenu::DropMenu(Button& button)
:	m_isActive(false) {

	m_p_mButton = &button;
}

void DropMenu::addItem(Button button) {
	m_buttons.push_back(std::make_unique<Button>(button));

	m_buttons.back()->setPosition({ m_p_mButton->getPos().x, m_p_mButton->getPos().y + m_p_mButton->getSize().y * m_buttons.size() });
}

void DropMenu::switchActivity() {
	m_isActive = !m_isActive;
}

bool DropMenu::handleEvents(const sf::RenderWindow& window, sf::Event ev) {
	if (!m_buttons.empty() && m_isActive) {
		for (auto& button : m_buttons)
			button->handleEvents(window, ev);

		return true;
	}

	return false;
}

void DropMenu::render(sf::RenderTarget& renderer) {
	if (!m_buttons.empty() && m_isActive) {
		for (auto& button : m_buttons)
			button->render(renderer);
	}
}

void DropMenu::setPosition(const sf::Vector2f& pos) {
	m_p_mButton->setPosition(pos);

	for (int i = 0; i < m_buttons.size(); i++) {
		m_buttons[i]->setPosition({ m_p_mButton->getPos().x, m_p_mButton->getPos().y + m_p_mButton->getSize().y * (i + 1) });
	}
}

sf::Vector2f DropMenu::getSize() const {
	return { m_p_mButton->getSize().x, m_p_mButton->getSize().y + m_p_mButton->getSize().y * m_buttons.size() };
}

sf::Vector2f DropMenu::getPos() const {
	return m_p_mButton->getPos();
}
