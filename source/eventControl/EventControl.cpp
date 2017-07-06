/*
mvxxx 2017
https://github.com/mvxxx
*/

#include "EventControl.hpp"

namespace mv
{

	EventControl::EventControl( std::shared_ptr<Scene> scenePointer )
		:scene(scenePointer)
	{	
	}

	void EventControl::checkEvent(sf::Event& event)
	{
		while(scene->getWindow()->pollEvent(event))
		{
			switch (event.type)
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
	}
}

