/*
mvxxx 2017
https://github.com/mvxxx
*/
#pragma once

#include <SFML/Window/Mouse.hpp>
#include "ecs/entity/Entity.hpp"
#include "ecs/component/ProperBody.hpp"
#include "cache/Cache.hpp"
#include "scene/Scene.hpp"

class Mouse :public mv::Entity
{
	/* ===Objects=== */
public:
protected:
private:
	mv::Cache<sf::Texture> textureAtlas;
	/* ===Methods=== */
public:
	Mouse();

	void update( std::shared_ptr<Scene> scene );
protected:
private:
};
