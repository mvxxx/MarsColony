/*
mvxxx 2017
https://github.com/mvxxx
*/

#pragma once

#include <map>
#include <memory>
#include "SubState.hpp"

struct eventWrapper_t;
class Scene;

class State
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
	virtual void onStart() = 0;

	virtual void onStop() = 0;

	virtual void run() = 0;
protected:
	void loopSubStates( eventWrapper_t& eventTypes );
private:
};


inline void State::loopSubStates( eventWrapper_t& eventTypes )
{
	for ( auto& subState : subStates )
	{
		subState.second->run( eventTypes );
	}
}
