/*
mvxxx 2017
https://github.com/mvxxx
*/

#pragma once

#include <SFML/Window/Event.hpp>
#include <vector>

struct eventWrapper_t
{
	std::vector<sf::Event::EventType> list;
};
