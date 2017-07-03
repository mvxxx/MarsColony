/*
mvxxx 2017
https://github.com/mvxxx
*/

#pragma once

#include <vector>
#include <map>
#include <memory>

#include "SubState.hpp"

class Scene;

class State :public SubState
{
	/* ===Objects=== */
public:
	enum class type_t
	{
		mainGame
	};
protected:
	std::map<type_t, std::shared_ptr<SubState>> subStates;
private:
	/* ===Methods=== */
public:

protected:
	void loopSubStates();
private:
};


inline void State::loopSubStates()
{
	for ( auto& subState : subStates )
	{
		subState.second->run();
	}
}
