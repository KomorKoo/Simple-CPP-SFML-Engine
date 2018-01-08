#pragma once

#include <SFML/Graphics.hpp>

class Game;

class GameState {
	protected:
		Game* m_p_game;

	public:
		GameState(Game& game)
		:	m_p_game(&game)
		{ }

		virtual ~GameState() = default;

		virtual void handleEvents(sf::Event ev)		= 0;
		virtual void handleInput()			= 0;
		virtual void update(float dt)			= 0;
		virtual void render(sf::RenderTarget& renderer) = 0;
};
