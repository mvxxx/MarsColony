/*
mvxxx 2019
https://github.com/mvxxx
*/
#include "EventControl.hpp"
#include <iostream>
#include "../Utilities.hpp"

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
            if(!extraordinary(event,eventTypes))
            {
                eventTypes.list.push_back({event.type,{}});
            }
        }

		return eventTypes;
	}

    bool EventControl::extraordinary(sf::Event &event, eventWrapper_t& eventTypes)
    {
        /*
        *Extraordinary events
        *The use of them requires more info than only id
        */
        switch ( event.type )
        {
            case sf::Event::MouseWheelMoved:
            {
                if (Utilities::isInWindow(Utilities::mouseWindowPosition( scene ), scene ) )
                {
                    if (event.mouseWheel.delta < 0)
                        eventTypes.list.push_back({event.type, {mv::constants::event_flags::ZOOM_MODE}});
                    else
                        eventTypes.list.push_back({event.type, {mv::constants::event_flags::DECREASE_MODE}});
                    return true;
                    break;
                }
            }
            case sf::Event::MouseButtonPressed:
            {
                if(event.mouseButton.button == sf::Mouse::Left)
                {
                    eventTypes.list.push_back({event.type, {mv::constants::event_flags::LEFT_MOUSE_BUTTON}});
                    return true;
                }
                break;
            }

            case sf::Event::MouseButtonReleased:
            {
                if(event.mouseButton.button == sf::Mouse::Left)
                {
                    eventTypes.list.push_back({event.type, {mv::constants::event_flags::LEFT_MOUSE_BUTTON}});
                    return true;
                }
                break;
            }
            default: return false;
        }
    }
}

