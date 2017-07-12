/*
mvxxx 2017
https://github.com/mvxxx
*/

#include "EventControl.hpp"
#include <iostream>

namespace mv
{

	EventControl::EventControl( std::shared_ptr<Scene> scenePointer )
		:scene( scenePointer )
	{
	}

	eventWrapper_t EventControl::checkEvent( sf::Event& event )
	{
		eventWrapper_t eventTypes;

		while ( scene->getWindow()->pollEvent( event ) )
			eventTypes.list.push_back( event.type );
		
		return eventTypes;
	}
}

