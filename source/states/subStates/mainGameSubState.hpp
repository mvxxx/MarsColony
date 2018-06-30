/*
mvxxx 2017
https://github.com/mvxxx
*/

#pragma once

#include "wrappers/FunctionPointerWrapper_t.hpp"
#include "mapManager/mapManager.hpp"
#include "renderer/renderer.hpp"
#include "wrappers/EventWrapper.hpp"
#include "ecs/entity/Entity.hpp"
#include "inputManager/InputManager.hpp"
#include "mapManager/SelectionManager.hpp"


class MainGameSubState :public SubState
{
  /* ===Objects=== */
public:
protected:
private:
  MapManager mapManager;
  mv::InputManager<Scene> cameraControl;
  std::shared_ptr<SelectionManager> selectionManager;

  /* ===Methods=== */
public:

  MainGameSubState(std::shared_ptr<Scene> scene, std::shared_ptr<SelectionManager> selManager);

  virtual void onStart() override;

  virtual void onStop() override;

  virtual void run(eventWrapper_t& eventTypes) override;

  void fillRenderer(Renderer& renderer);

  std::shared_ptr<SelectionManager> getSelectionManager();

protected:
private:
};


