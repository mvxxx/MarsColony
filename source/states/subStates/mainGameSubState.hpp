/*
mvxxx 2017
https://github.com/mvxxx
*/

#pragma once

#include "../../wrappers/FunctionPointerWrapper_t.hpp"
#include "../../mapManager/mapManager.hpp"
#include "../../renderer/renderer.hpp"
#include "../../wrappers/EventWrapper.hpp"
#include "../../ecs/entity/Entity.hpp"
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

  //camera control
  mv::InputManager<Scene> cameraControl;

  //pointer to selection manager
  std::shared_ptr<SelectionManager> selectionManager;

  /* ===Methods=== */
public:
	/**
	* @brief classic ctor
	* @param scene pointer
	* @param selManager selection manager's pointer
	* 
	*/
  MainGameSubState(std::shared_ptr<Scene> scene, std::shared_ptr<SelectionManager> selManager);

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

  /**
  * @brief selectionManager getter
  * @return shared_ptr to selection manager
  */
  std::shared_ptr<SelectionManager> getSelectionManager();

protected:
private:
};


