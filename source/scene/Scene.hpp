/*
mvxxx 2017
https://github.com/mvxxx
*/

#pragma once

#include <memory>
#include <unordered_map>

#include "../../external/SFML/include/SFML/Graphics/RenderWindow.hpp"
#include "../../external/SFML/include/SFML/Graphics/View.hpp"
#include "../../external/SFML/include/SFML/System/Vector2.hpp"

#include "../states/State.hpp"
#include "../renderer/renderer.hpp"
#include "../eventDock/EventDock.hpp"

class SelectionManager;

/**
* @brief scene which represents world
*/
class Scene : public EventDock
{
	/* ===Objects=== */
public:
	// motion sensitivity
	const float motionSensitivity;

	//speed of view
	const float viewSpeed;

	//zoom speed
	const float zoomSpeed;

	//renderer
	Renderer renderer;

	/**
	* @brief Enum which determines the state changes distance
	*/
	enum class zoom_t
	{
		ZOOM,
		DECREASE
	};

	/**
	* @brief Enum which determines type of view
	*/
	enum class viewType_t
	{
		DEFAULT,
		UI
	};

protected:
private:
	//actual state
	std::unique_ptr<State> state;
	
	//pointer to SFML window
	std::shared_ptr<sf::RenderWindow> window;

	//database of all views
	std::unordered_map<viewType_t, std::shared_ptr<sf::View> > views;

	/**
	* @brief Enum which determines direction
	*/
	enum class direction_t
	{
		TOP,
		RIGHT,
		DOWN,
		LEFT
	};

	/* ===Methods=== */
public:
	/**
	* @brief classic ctor
	* @param title of window
	* @param dimensions of window
	*/
	Scene( const std::string& title, const sf::Vector2f& dimensions );

	/**
	* @brief check if window is opened
	* @return true if is opened, false otherwise
	*/
	bool isOpen() const;

	/**
	* @brief closes window
	*/
	void close() const;


	/**
	* @brief draws all objects
	*/
	void drawAll();

	/**
	* @brief clears scene
	*/
	void clear() const;

	/**
	* @brief displays all objects
	*/
	void display() const;

	/**
	* @brief zoom
	* @param type of zoom
	* @see zoom_t
	*/
	void zoom( const zoom_t& type );

	/**
	* @brief sets view
	* @param type of view
	* @see viewType_t
	*/
	void setView( viewType_t type );

	/**
	* @brief assigns selection manager
	* @param manager - pointer to selection manager
	*/
	void assignSelectionManager(std::shared_ptr<SelectionManager> manager);

	/**
	* @brief getter for window
	* @return shared_ptr to window (SFML)
	*/
	std::shared_ptr<sf::RenderWindow> getWindow() const;

	/**
	* @brief getter for views
	* @return shared_ptr to views' database
	*/
	const std::unordered_map<viewType_t, std::shared_ptr<sf::View> >& getViews() { return views; }

	/**
	* @brief move view right 
	*/
	void moveViewRight();

	/**
	* @brief move view left
	*/
	void moveViewLeft();

	/**
	* @brief move view top
	*/
	void moveViewTop();

	/**
	* @brief move view down
	*/
	void moveViewDown();

	/**
	* @brief handles event types
	* @param eventList - list of events which are needed to be checked
	*/
	virtual void handleEventTypes( const eventWrapper_t& eventList ) override;

protected:
private:
	/**
	* @brief move view
	* @param direction of moving
	*/
	void moveView( direction_t direction );
};
