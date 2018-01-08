#include "Game.hpp"
#include "GameStates\DebugState.hpp"

Game::Game()
:	m_window({1280, 720}, "Hehe Xd") {

	m_states.push(std::make_unique<DebugState>(*this));
}

void Game::run() {
	while (m_window.isOpen()) {
		handleEvents();

		m_window.clear();

		m_states.top()->handleInput();
		m_states.top()->update(0.0f);
		m_states.top()->render(m_window);

		m_window.display();
	}
}

void Game::pushState(std::unique_ptr<GameState> state) {
	m_states.push(std::move(state));
}

void Game::changeState(std::unique_ptr<GameState> state) {
	if (!m_states.empty())
		m_states.pop();

	m_states.push(std::move(state));
}

bool Game::popState() {
	if(m_states.empty())
		return false;

	m_states.pop();
	return true;
}

const sf::RenderWindow& Game::getWindow() const {
	return m_window;
}

void Game::handleEvents() {
	sf::Event ev;

	while (m_window.pollEvent(ev)) {
		m_states.top()->handleEvents(ev);

		switch (ev.type) {
			case sf::Event::Closed:
				m_window.close();
				break;

			default:
				break;
		}
	}
}
