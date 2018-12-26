/*
mvxxx 2017
https://github.com/mvxxx
*/

#pragma once

#include "../../external/SFML/include/SFML/Window/Event.hpp"
#include <vector>

struct eventData_t
{
	sf::Event::EventType eventInfo;
	std::vector<std::string> additionals;

	eventData_t(sf::Event::EventType& ev, const std::vector<std::string>& add)
	:eventInfo(ev),additionals(add){}
};

/**
* @brief eventWrapper
*/
struct eventWrapper_t
{
	//list of SFML event types
	std::vector<eventData_t> list;
};
