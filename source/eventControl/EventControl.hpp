/*
mvxxx 2017
https://github.com/mvxxx
*/

#pragma once

#include <SFML/Window/Event.hpp>
#include "scene/Scene.hpp"
#include <memory>


/*
				===---===
	If you want to extend event control you need to modife checkControl() method:
	-Add new case like this:

	case sf::Event::MouseLeft:
	{
		do sth...
		break;
	}
			    ===---===
*/

namespace mv
{
	class EventControl
	{
		/* ===Objects=== */
	public:
	protected:
	private:
		std::shared_ptr<Scene> scene;
		/* ===Methods=== */
	public:
		void checkEvent(sf::Event& event);
		EventControl( std::shared_ptr<Scene> scenePointer );
	protected:
	private:
	};
}
