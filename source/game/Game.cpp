/*
mvxxx 2017
https://github.com/mvxxx
*/

#include "Game.hpp"


void Game::run()
{
	init();

	while ( scene->isOpen() )
	{
		state->run();
	}
}

void Game::init()
{
	scene = std::make_shared<Scene>( "MarsColony", sf::Vector2f( 600, 600 ) );
	state = std::make_unique<GameState>( scene );
}
