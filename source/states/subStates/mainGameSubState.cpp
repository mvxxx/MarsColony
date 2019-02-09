/*
mvxxx 2017
https://github.com/mvxxx
*/

#include "mainGameSubState.hpp"


MainGameSubState::MainGameSubState( std::shared_ptr<Scene> sceneptr)
	:scene(sceneptr)
{

	this->onStart();
}

void MainGameSubState::onStart()
{
	mapManager.createWorld( "../data/defaultMaps/map0.txt" );
	player = std::make_shared<Player>(sf::Vector2f{100.f,100.f},1,0,mv::constants::mob::DEFAULT_SPEED);
}

void MainGameSubState::onStop()
{
}

void MainGameSubState::run( eventWrapper_t& eventTypes )
{
	mapManager.manageAll();
	player->update(scene);
}

void MainGameSubState::fillRenderer( Renderer& renderer )
{
  renderer.addCollection( mapManager.tilesManager.getTiles(), 0, DrawMap::renderType_t::DEFAULT );
  renderer.addSingle(player,1,DrawMap::renderType_t::DEFAULT);
}
