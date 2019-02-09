/*
mvxxx 2019
https://github.com/mvxxx
*/

#pragma once
#include <memory>

#include "../../wrappers/FunctionPointerWrapper_t.hpp"
#include "../../mapManager/mapManager.hpp"
#include "../../renderer/renderer.hpp"
#include "../../wrappers/EventWrapper.hpp"
#include "../../ecs/entity/Entity.hpp"
#include "../../entities/player/player.hpp"
#include "../../inputManager/InputManager.hpp"
#include "../../mapManager/SelectionManager.hpp"

/**
* @brief main substate
*/
class MainGameSubState :public SubState
{
  /* ===Objects=== */
public:
protected:
private:
  //manager of map
  MapManager mapManager;


  //pointer to player
  std::shared_ptr<Player> player;

  //pointer to scene
  std::shared_ptr<Scene> scene;

  /* ===Methods=== */
public:
	/**
	* @brief classic ctor
	* @param scene pointer
	* @param selManager selection manager's pointer
	* 
	*/
  MainGameSubState(std::shared_ptr<Scene> scene);

  /**
  * @brief onStart method
  */
  virtual void onStart() override;

  /**
  * @brief onStop method
  */
  virtual void onStop() override;

  /**
  * @brief continues work of substate
  * @param eventTypes - list of events
  */
  virtual void run(eventWrapper_t& eventTypes) override;

  /**
  * @brief filld renderer 
  * @param renderer
  */
  void fillRenderer(Renderer& renderer);

protected:
private:
};


