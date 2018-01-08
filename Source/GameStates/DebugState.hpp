#pragma once

#include "GameState.hpp"
#include "../GUI/Button.hpp"
#include "../GUI/DropMenu.hpp"

class DebugState : public GameState {
	private:
		Button   m_menuTrigger;
		DropMenu m_dropMenu;

	public:
		DebugState(Game& game);

		void handleEvents(sf::Event ev)		override;
		void handleInput()			override;
		void update(float dt)			override;
		void render(sf::RenderTarget& renderer) override;
};
