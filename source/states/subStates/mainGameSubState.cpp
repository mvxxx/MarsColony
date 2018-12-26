/*
mvxxx 2017
https://github.com/mvxxx
*/

#include "mainGameSubState.hpp"


MainGameSubState::MainGameSubState( std::shared_ptr<Scene> scene)
{

	this->onStart();
}

void MainGameSubState::onStart()
{
	mapManager.createWorld( "data/defaultMaps/map0.txt" );
	player = std::make_shared<Player>(sf::Vector2f{100.f,100.f},1,0);
}

void MainGameSubState::onStop()
{
}

void MainGameSubState::run( eventWrapper_t& eventTypes )
{
	mapManager.manageAll();
	cameraControl.update();
}

void MainGameSubState::fillRenderer( Renderer& renderer )
{
  renderer.addCollection( mapManager.tilesManager.getTiles(), 0, DrawMap::renderType_t::DEFAULT );
  renderer.addSingle(player,1,DrawMap::renderType_t::DEFAULT);
}
