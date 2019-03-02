#include "Game.hpp"


void Game::run()
{
	while ( scene->isOpen() )
	{
		state->run();
	}
}

void Game::init()
{
	scene = std::make_shared<Scene>( "MarsCombat", mv::constants::defaults::WINDOW_DIMENSIONS );
	state = std::make_unique<GameState>( scene );
}
