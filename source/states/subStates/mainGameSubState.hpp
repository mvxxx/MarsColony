/*
mvxxx 2019
https://github.com/mvxxx
*/

#pragma once
#include <memory>

#include "../../wrappers/FunctionPointerWrapper_t.hpp"
#include "../../mapManager/mapManager.hpp"
#include "../../mapManager/IconManager.hpp"
#include "../../renderer/renderer.hpp"
#include "../../wrappers/EventWrapper.hpp"
#include "../../ecs/entity/Entity.hpp"
#include "../../entities/player/player.hpp"
#include "../../inputManager/InputManager.hpp"
#include "../../mouse/Mouse.hpp"


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

  //manager of collisions
  CollisionManager collisionManager;

  //pointer to mouse
  std::shared_ptr<Mouse> mouse;

  //pointer to player
  std::shared_ptr<Player> player;

  //pointer to scene
  std::shared_ptr<Scene> scene;

  std::shared_ptr<IconManager> iconManager;

  /* ===Methods=== */
public:
	/**
	* @brief classic ctor
	* @param scene pointer
	* @param selManager selection manager's pointer
	* 
	*/
  MainGameSubState(const std::shared_ptr<Scene>& sceneptr);

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


