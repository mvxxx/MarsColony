/*
mvxxx 2017
https://github.com/mvxxx
*/

#pragma once

#include "scene/Scene.hpp"
#include "states/GameState.hpp"

class Game
{
	/* ===Objects=== */
public:
protected:
private:
	std::shared_ptr<Scene> scene;
	std::unique_ptr<State> state;
	/* ===Methods=== */
public:
	void run();
protected:
private:
	void init();
};
