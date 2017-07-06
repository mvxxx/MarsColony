/*
mvxxx 2017
https://github.com/mvxxx
*/

#pragma once

#include <vector>
#include <map>
#include <memory>

#include <sfml/window/event.hpp>

#include "SubState.hpp"

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
	void loopSubStates( sf::Event& event );
private:
};


inline void State::loopSubStates( sf::Event& event )
{
	for ( auto& subState : subStates )
	{
		subState.second->run( event );
	}
}
