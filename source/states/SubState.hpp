/*
mvxxx 2017
https://github.com/mvxxx
*/

#pragma once

#include "wrappers/EventWrapper.hpp"

class SubState
{
	/* ===Objects=== */
public:
protected:
private:
	/* ===Methods=== */
public:

	virtual void onStart() = 0;

	virtual void onStop() = 0;

	virtual void run( eventWrapper_t& eventTypes ) = 0;

protected:
private:
};
