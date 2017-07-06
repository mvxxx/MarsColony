/*
mvxxx 2017
https://github.com/mvxxx
*/

#pragma once

#include <SFML/Window/Event.hpp>

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

	virtual void run( sf::Event event ) = 0;

protected:
private:
};