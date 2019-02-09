/*
mvxxx 2019
https://github.com/mvxxx
*/

#pragma once

#include "../wrappers/EventWrapper.hpp"

/**
* @brief represents single substate
*/
class SubState
{
	/* ===Objects=== */
public:
protected:
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
	virtual void run( eventWrapper_t& eventTypes ) = 0;

protected:
private:
};
