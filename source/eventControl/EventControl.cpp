/*
mvxxx 2017
https://github.com/mvxxx
*/

#include "EventControl.hpp"
#include <iostream>
#include "Utilities.hpp"

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
		{
			eventTypes.list.push_back( event.type );

			/*
			 *Extraordinary events
			 *The use of them requires more info than only id
			*/
			switch ( event.type )
			{
			case sf::Event::MouseWheelMoved:
			{
				if (Utilities::isInWindow(Utilities::mouseWindowPosition( scene ), scene ) )
					if ( event.mouseWheel.delta < 0 )
						scene->zoom( Scene::zoom_t::ZOOM );
					else
						scene->zoom( Scene::zoom_t::DECREASE );
				break;
			}
			}
		}


		return eventTypes;
	}
}

