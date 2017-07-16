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
	scenePointer->getWindow()->setMouseCursorVisible( false );

	mouse = std::make_shared<Mouse>();
	scenePointer->renderer.addSingle( mouse, 1, DrawMap::renderType_t::UI);

	auto mainSubState = std::make_shared<MainGameSubState>( scenePointer );
	mainSubState->fillRenderer( scenePointer->renderer );

	this->subStates.emplace( State::type_t::mainGame, mainSubState );
}

void GameState::onStop()
{
}

void GameState::run()
{
	sf::Event event;
	auto eventTypes = eventControl->checkEvent( event );

	this->loopSubStates( eventTypes );

	mouse->update( scenePointer );

	scenePointer->handleEventTypes( eventTypes );

	scenePointer->clear();
	scenePointer->drawAll();
	scenePointer->display();
}

