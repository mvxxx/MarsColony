/*
mvxxx 2017
https://github.com/mvxxx
*/

#pragma once

#include "../scene/Scene.hpp"
#include "../states/GameState.hpp"


/**
* @brief class that is responsible for starting game
*/
class Game
{
	/* ===Objects=== */
public:
protected:
private:
	//main scene
	std::shared_ptr<Scene> scene;

	//state of game
	std::unique_ptr<State> state;
	/* ===Methods=== */
public:
	/**
	* @brief init game
	*/
	void init();

	/**
	* @brief run game
	*/
	void run();	
protected:
private:
};
