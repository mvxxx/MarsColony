/*
mvxxx 2019
https://github.com/mvxxx
*/

#pragma once

#include <map>
#include <memory>
#include "SubState.hpp"

struct eventWrapper_t;
class Scene;

/**
* @brief Class for representing state
*/
class State
{
	/* ===Objects=== */
public:
	/**
	* @brief type of state
	*/
	enum class type_t
	{
		mainGame
	};
protected:
	// substates database
	std::map<type_t, std::shared_ptr<SubState>> subStates;
private:
	/* ===Methods=== */
public:
	/**
	* @brief onStart method
	*/
	virtual void onStart() = 0;

	/**
	* @brief onStop method
	*/
	virtual void onStop() = 0;

	/**
	* @brief run method
	*/
	virtual void run() = 0;
protected:

	/**
	* @brief loops through each of substates
	* @param eventTypes list of events
	*/
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
