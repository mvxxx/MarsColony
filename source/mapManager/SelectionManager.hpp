/*
mvxxx 2017
https://github.com/mvxxx
*/

#pragma once
#include "ecs/entity/Entity.hpp"
#include "scene/Scene.hpp"
#include "TilesManager.hpp"
#include <SFML/Window/Event.hpp>


class Border;

class SelectionManager :public Manager<mv::Entity>
{
	/* ===Objects=== */
public:
protected:
private:
	std::shared_ptr<Scene> scene;
	/* ===Methods=== */
public:
	SelectionManager( std::shared_ptr<Scene> _scene );

	void manage() override;
	virtual void addEntityToManage( std::shared_ptr<mv::Entity> entity ) override;
protected:
private:
	void callSelection();
	void cancelSelection();
};
