/*
mvxxx 2017
https://github.com/mvxxx
*/

#pragma once

#include "../ecs/entity/Entity.hpp"
#include "../scene/Scene.hpp"
#include "TilesManager.hpp"
#include "../frame/Frame.hpp"
#include "../Utilities.hpp"


class Frame;

/**
* @brief manager for control selection
*/
class SelectionManager :public Manager<mv::Entity>, public EventDock
{
	/* ===Objects=== */
public:
protected:
private:
	//pointer to scene
	std::shared_ptr<Scene> scene;

	//pointer to frame
    std::shared_ptr<Frame> frame;
	/* ===Methods=== */
public:
	/**
	* @brief classic ctor
	* @param _scene pointer
	*/
	SelectionManager( std::shared_ptr<Scene> _scene );

	/**
	* @brief to do: implement in future
	*/
	virtual void manage() override {};

	/**
	* @brief adds entity to managing loop
	* @param entity - pointer to given object
	*/
	virtual void addEntityToManage( std::shared_ptr<mv::Entity> entity ) override;

	/**
	* @brief handles event types
	* @param eventList - list of events which are needed to be checked
	*/
	virtual void handleEventTypes( const eventWrapper_t& eventList ) override;

	/**
	* @brief getter for frame
	* @return frame pointer
	*/
	std::shared_ptr<Frame> getFrame();
protected:
private:
};
