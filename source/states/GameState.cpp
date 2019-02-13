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

  auto mainSubState = std::make_shared<MainGameSubState>(scenePointer);
  mainSubState->fillRenderer(scenePointer->renderer);

  this->subStates.emplace(State::type_t::mainGame, mainSubState);
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
  scenePointer->handleEventTypes(eventTypes);
}

void GameState::visualProcessing()
{
  scenePointer->clear();
  scenePointer->drawAll();
  scenePointer->display();
}

