/*
mvxxx 2017
https://github.com/mvxxx
*/

#include "GameState.hpp"

GameState::GameState( std::shared_ptr<Scene> scenePtr )
	:scenePointer( scenePtr )
{
	this->onStart();
	eventControl = std::make_shared<mv::EventControl>( scenePointer );
}

void GameState::onStart()
{
	auto mainSubState = std::make_shared<MainGameSubState>();
	mainSubState->fillRenderer( scenePointer->renderer );

	this->subStates.emplace( State::type_t::mainGame, mainSubState );
}

void GameState::onStop()
{
}

void GameState::run()
{
	sf::Event event;

	this->loopSubStates();

	eventControl->checkEvent( event );

	scenePointer->clear();
	scenePointer->drawAll();
	scenePointer->display();
}

