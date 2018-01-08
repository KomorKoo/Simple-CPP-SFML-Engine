#include <iostream>

#include "DebugState.hpp"
#include "../ResourceHandling/ResourceHolder.hpp"
#include "../Game.hpp"

DebugState::DebugState(Game& game)
:	GameState    (game)
,   	m_menuTrigger({ 640.0f, 100.0f }, ButtonSize::Big)
,	m_dropMenu   (m_menuTrigger) {

	m_menuTrigger.setFunction([]() {
		;
	});
	m_menuTrigger.setText("Temp menu");
	m_menuTrigger.setTexture(ResourceHolder::get().textures.get("dropMenuMotherButton"));


	Button tempButton({ 0.0f, 0.0f }, ButtonSize::Narrow);

	tempButton.setTexture(ResourceHolder::get().textures.get("dropMenuMotherButton"));

	//Button #1
	tempButton.setFunction([]() {
		std::cout << "Pong" << std::endl;
	});
	tempButton.setText("Ping");
	m_dropMenu.addItem(tempButton);

	//Button #2
	tempButton.setFunction([]() {
		std::cout << "NIGGER" << std::endl;
	});
	tempButton.setText("SAAAAAY");
	m_dropMenu.addItem(tempButton);

	//Button #3
	tempButton.setFunction([]() {
		exit(0);
	});
	tempButton.setText("Exit");
	m_dropMenu.addItem(tempButton);

	m_dropMenu.setPosition({ m_p_game->getWindow().getSize().x / 2.0f,
				 m_p_game->getWindow().getSize().y / 6.0f });
}

void DebugState::handleEvents(sf::Event ev) {
	if (m_menuTrigger.handleEvents(m_p_game->getWindow(), ev))
		m_dropMenu.switchActivity();

	m_dropMenu.handleEvents(m_p_game->getWindow(), ev);
}

void DebugState::handleInput() {
	;
}

void DebugState::update(float dt) {
	;
}

void DebugState::render(sf::RenderTarget& renderer) {
	m_menuTrigger.render(renderer);
	m_dropMenu.render(renderer);
}
