/*
mvxxx 2017
https://github.com/mvxxx
*/

#pragma once

#include "ecs/entity/Entity.hpp"
#include "scene/Scene.hpp"
#include "TilesManager.hpp"
#include "frame/Frame.hpp"
#include "Math.hpp"


class Frame;

/*not finished*/
class SelectionManager :public Manager<mv::Entity>, public EventDock
{
	/* ===Objects=== */
public:
protected:
private:
	std::shared_ptr<Scene> scene;
  std::shared_ptr<Frame> frame;
	/* ===Methods=== */
public:
	SelectionManager( std::shared_ptr<Scene> _scene );

	//to do: implement in future
	virtual void manage() override {};

	virtual void addEntityToManage( std::shared_ptr<mv::Entity> entity ) override;

	virtual void handleEventTypes( const eventWrapper_t& eventList ) override;

  std::shared_ptr<Frame> getFrame();
protected:
private:
	void callSelection();
	void cancelSelection();
};
