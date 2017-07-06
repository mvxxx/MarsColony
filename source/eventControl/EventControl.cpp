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
		{
			eventTypes.list.push_back( event.type );

			switch ( event.type )
			{
			case sf::Event::Closed:
			{
				scene->close();
				break;
			}

			/*case sf::Event::MouseWheelMoved:
			{
				if (event.mouseWheel.delta < 0)
					Scene::getInstance().zoom(Scene::ZOOM_STATE::ZOOM);
				else
					Scene::getInstance().zoom(Scene::ZOOM_STATE::DECREASE);

				break;
			}*/
			/*there you can add new case*/
			}
		}

		return eventTypes;
	}
}

