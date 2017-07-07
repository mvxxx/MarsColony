/*
mvxxx 2017
https://github.com/mvxxx
*/

#include "mainGameSubState.hpp"


MainGameSubState::MainGameSubState( std::shared_ptr<Scene> scene )
	:selectionManager( scene )
{
	this->onStart();
	cameraControl.addKeyToCheck( sf::Keyboard::A, []() { &Scene::help } );
}

void MainGameSubState::onStart()
{
	mapManager.createWorld( "data/defaultMaps/map0.txt" );

}

void MainGameSubState::onStop()
{
}

void MainGameSubState::run( eventWrapper_t& eventTypes )
{
	mapManager.manageAll();
	selectionManager.manage( eventTypes );
}

void MainGameSubState::fillRenderer( Renderer& renderer )
{
	renderer.addCollection( mapManager.tilesManager.getTiles(), 0 );
}
