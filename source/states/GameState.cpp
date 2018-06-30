/*
mvxxx 2017
https://github.com/mvxxx
*/

#include "GameState.hpp"

GameState::GameState(std::shared_ptr<Scene> scenePtr)
  :scenePointer(scenePtr),
	loopManager(sf::seconds(mv::constants::loop::TIME_PER_FRAME))
{
  this->onStart();
  eventControl = std::make_shared<mv::EventControl>(scenePointer);
}

void GameState::onStart()
{
  scenePointer->getWindow()->setMouseCursorVisible(false);
  
  mouse = std::make_shared<Mouse>(scenePointer);

  selectionManager = std::make_shared<SelectionManager>(scenePointer);
  scenePointer->assignSelectionManager(selectionManager);

  auto mainSubState = std::make_shared<MainGameSubState>(scenePointer,selectionManager);
  mainSubState->fillRenderer(scenePointer->renderer);

  this->subStates.emplace(State::type_t::mainGame, mainSubState);

  scenePointer->renderer.addSingle(mouse, 1, DrawMap::renderType_t::UI);

}

void GameState::onStop()
{
}

void GameState::run()
{
  loopManager.increaseTime();

  while ( !loopManager.canChangeTheFrame() )
  {
    logicProcessing();
    loopManager.reduceTime();
  }

  visualProcessing();
}

void GameState::logicProcessing()
{
  sf::Event event;
  auto eventTypes = eventControl->checkEvent(event);
  this->loopSubStates(eventTypes);
  mouse->update(scenePointer);
  scenePointer->handleEventTypes(eventTypes);
}

void GameState::visualProcessing()
{
  scenePointer->clear();
  scenePointer->drawAll();
  scenePointer->display();
}

