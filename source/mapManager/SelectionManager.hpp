/*
mvxxx 2017
https://github.com/mvxxx
*/

#pragma once

#include "ecs/entity/Entity.hpp"
#include "scene/Scene.hpp"
#include "TilesManager.hpp"
#include "mouse/Border.hpp"


class Border;

/*not finished*/
class SelectionManager :public Manager<mv::Entity>, public EventDock
{
	/* ===Objects=== */
public:
protected:
private:
	std::shared_ptr<Scene> scene;
  std::shared_ptr<Border> border;
	/* ===Methods=== */
public:
	SelectionManager( std::shared_ptr<Scene> _scene );

	//to do: implement in future
	virtual void manage() override {};

	virtual void addEntityToManage( std::shared_ptr<mv::Entity> entity ) override;

	virtual void handleEventTypes( const eventWrapper_t& eventList ) override;

  std::shared_ptr<Border> getBorder();
protected:
private:
	void callSelection();
	void cancelSelection();
};
