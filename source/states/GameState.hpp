/*
mvxxx 2019
https://github.com/mvxxx
*/

#pragma once

#include "../states/State.hpp"
#include "subStates/mainGameSubState.hpp"
#include "../eventControl/EventControl.hpp"
#include "../LoopManager/LoopManager.hpp"

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