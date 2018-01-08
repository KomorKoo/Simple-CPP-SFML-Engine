#pragma once

#include <SFML/Graphics.hpp>
#include <memory>
#include <stack>

#include "GameStates\GameState.hpp"

class Game {
	private:
		sf::RenderWindow m_window;
		std::stack<std::unique_ptr<GameState>> m_states;

	public:
		Game();

		void run();

		void pushState(std::unique_ptr<GameState> state);
		void changeState(std::unique_ptr<GameState> state);
		bool popState();

		const sf::RenderWindow& getWindow() const;

	private:
		void handleEvents();
};