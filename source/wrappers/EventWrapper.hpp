/*
mvxxx 2017
https://github.com/mvxxx
*/

#pragma once

#include <SFML/Window/Event.hpp>
#include <vector>

/**
* @brief eventWrapper
*/
struct eventWrapper_t
{
	//list of SFML event types
	std::vector<sf::Event::EventType> list;
};
