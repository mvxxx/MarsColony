#include "mainGameSubState.hpp"

MainGameSubState::MainGameSubState( const std::shared_ptr<Scene>& sceneptr)
	:scene(sceneptr)
{
	this->onStart();
}

void MainGameSubState::onStart()
{
	Loader loader;
	WorldWrapper_t mapPack = loader.loadMap( mv::constants::path::MAP );
	mapManager.createWorld(mapPack, collisionManager);
	this->player = std::make_shared<Player>(
            sf::Vector2f{mapPack.firstPlayerPosition.x * mv::constants::defaults::CELL_DIMENSION.x,
             mapPack.firstPlayerPosition.y * mv::constants::defaults::CELL_DIMENSION.y},
	        1,0,
	        5.f*mv::constants::mob::DEFAULT_SPEED,
			scene->getCacheByName("player"), scene->getCacheByName("weapon"));
	this->mouse = std::make_shared<Mouse>(this->scene);
	this->iconManager = std::make_shared<IconManager>(mapPack.iconsData);
	uimanager = std::make_shared<UIManager>(iconManager->getIconTextures(),*scene->getViews().at(Scene::viewType_t::DEFAULT));
}

void MainGameSubState::onStop()
{
}

void MainGameSubState::run( eventWrapper_t& eventTypes )
{
	player->update(scene, collisionManager, scene->getCacheByName("player"), scene->getCacheByName("weapon"));
	iconManager->update();
	iconManager->getTouchedIcon(player->getComponent<UnitPosition>()->getAsVec2i());
	mouse->update(this->scene);
}

void MainGameSubState::fillRenderer( Renderer& renderer )
{
  renderer.addCollection( mapManager.tilesManager.getTiles(), 0, DrawMap::renderType_t::DEFAULT );
  auto icons = iconManager->getIconsContainer();
  for(auto& ic : icons) {renderer.addSingle(ic,1,DrawMap::renderType_t::DEFAULT);}
  renderer.addSingle(player,1,DrawMap::renderType_t::DEFAULT);
  renderer.addSingle(mouse, 1, DrawMap::renderType_t::UI);
  renderer.addSingle(uimanager,1, DrawMap::renderType_t::UI);
}
