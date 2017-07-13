/*
mvxxx 2017
https://github.com/mvxxx
*/

#pragma once

#include "scene/Scene.hpp"
#include "wrappers/EventWrapper.hpp"
#include <memory>


/*
				===---===
	If you want to extend event control you need to implement eventDock in your class
	If your event need more informations than only id of event, implement it in checkEvent method
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
		eventWrapper_t checkEvent(sf::Event& event);
		EventControl( std::shared_ptr<Scene> scenePointer );
	protected:
	private:
	};
}
