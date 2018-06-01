/*
mvxxx 2017
https://github.com/mvxxx
*/

#pragma once

#include "states/State.hpp"
#include "subStates/mainGameSubState.hpp"
#include "eventControl/EventControl.hpp"
#include "mouse/Mouse.hpp"
#include "LoopManager/LoopManager.hpp"


class GameState :public State
{
	/* ===Objects=== */
public:
protected:
private:
	std::shared_ptr<mv::EventControl> eventControl;
	std::shared_ptr<Scene> scenePointer;
	std::shared_ptr<Mouse> mouse;
  LoopManager loopManager;
	/* ===Methods=== */
public:

	GameState( std::shared_ptr<Scene> scenePointer );

	virtual void onStart() override;

	virtual void onStop() override;

	void run();

protected:
private:
  void logicProcessing();
  void visualProcessing();
};