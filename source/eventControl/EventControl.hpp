/*
mvxxx 2017
https://github.com/mvxxx
*/

#pragma once

#include "../scene/Scene.hpp"
#include "../wrappers/EventWrapper.hpp"
#include <memory>


/*
				===---===
	If you want to extend event control you need to implement eventDock in your class
	If your event need more informations than only id of event, implement it in checkEvent method
			    ===---===
*/

namespace mv
{
	/**
	* @brief Event control class
	* It supports evenDock
	* You can implement there more advanced informations about SFML events
	*/
	class EventControl
	{
		/* ===Objects=== */
	public:
	protected:
	private:
		//pointer to scene
		std::shared_ptr<Scene> scene;
		/* ===Methods=== */
	public:
		/**
		* @brief classic ctor
		*/
		EventControl(std::shared_ptr<Scene> scenePointer);

		/**
		* @brief checks events
		* You can implement there more advanced informations about SFML events
		* @param event - SFML's event container
		* @return filled up wrapper of events
		*/
		eventWrapper_t checkEvent(sf::Event& event);
	protected:
	private:
	};
}
