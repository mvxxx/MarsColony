/*
mvxxx 2017
https://github.com/mvxxx
*/

#include "mainGameSubState.hpp"


MainGameSubState::MainGameSubState( std::shared_ptr<Scene> scene )
	:selectionManager( scene )
{
	this->onStart();

	cameraControl.addKeyToCheck( sf::Keyboard::A, std::function<void( Scene& )>( &Scene::moveViewLeft ), scene );
	cameraControl.addKeyToCheck( sf::Keyboard::D, std::function<void( Scene& )>( &Scene::moveViewRight ), scene );
	cameraControl.addKeyToCheck( sf::Keyboard::S, std::function<void( Scene& )>( &Scene::moveViewDown ), scene );
	cameraControl.addKeyToCheck( sf::Keyboard::W, std::function<void( Scene& )>( &Scene::moveViewTop ), scene );
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
	selectionManager.handleEventTypes( eventTypes );
	cameraControl.update();
}

void MainGameSubState::fillRenderer( Renderer& renderer )
{
	renderer.addCollection( mapManager.tilesManager.getTiles(), 0, DrawMap::renderType_t::DEFAULT );
}
