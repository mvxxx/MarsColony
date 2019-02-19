#include "mainGameSubState.hpp"

MainGameSubState::MainGameSubState( const std::shared_ptr<Scene>& sceneptr)
	:scene(sceneptr)
{

	this->onStart();
}

void MainGameSubState::onStart()
{
	mapManager.createWorld( mv::constants::path::MAP );
	player = std::make_shared<Player>(sf::Vector2f{400.f,400.f},1,0,mv::constants::mob::DEFAULT_SPEED);
	mouse = std::make_shared<Mouse>(this->scene);
}

void MainGameSubState::onStop()
{
}

void MainGameSubState::run( eventWrapper_t& eventTypes )
{
	mapManager.manageAll();
	player->update(scene, mouse);
	mouse->update(this->scene);
}

void MainGameSubState::fillRenderer( Renderer& renderer )
{
  renderer.addCollection( mapManager.tilesManager.getTiles(), 0, DrawMap::renderType_t::DEFAULT );
  renderer.addSingle(player,1,DrawMap::renderType_t::DEFAULT);
  renderer.addSingle(mouse, 1, DrawMap::renderType_t::UI);
}
