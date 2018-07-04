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
#include "mapManager/SelectionManager.hpp"

/**
* @brief state of game
*/
class GameState :public State
{
	/* ===Objects=== */
public:
protected:
private:
	//event control
	std::shared_ptr<mv::EventControl> eventControl;

	// pointer to scene
	std::shared_ptr<Scene> scenePointer;

	//pointer to mouse
	std::shared_ptr<Mouse> mouse;

	//pointer to selection manager
	std::shared_ptr<SelectionManager> selectionManager;

	//manager's loop
    LoopManager loopManager;
	/* ===Methods=== */
public:
	/**
	* @brief classic ctor
	* @param scenePointer pointer to main scene
	*/
	GameState( std::shared_ptr<Scene> scenePointer );

	/**
	* @brief onStart method
	*/
	virtual void onStart() override;

	/**
	* @brief onStop method
	*/
	virtual void onStop() override;

	/**
	* @brief continues work of state
	*/
	void run();

protected:
private:
  /**
  * @brief logic part of processing
  */
  void logicProcessing();

  /**
  * @brief visual part of processing
  */
  void visualProcessing();
};