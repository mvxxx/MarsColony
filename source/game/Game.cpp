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
	scene = std::make_shared<Scene>( "MarsCombat", sf::Vector2f( 1000, 1000 ) );
	state = std::make_unique<GameState>( scene );
}
