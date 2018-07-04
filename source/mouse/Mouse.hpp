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
#include "Utilities.hpp"

/**
* @brief class which represents mouse
*/
class Mouse :public mv::Entity
{
	/* ===Objects=== */
public:
protected:
private:
	// atlas of textures for mouse
	mv::Cache<sf::Texture> textureAtlas;
	/* ===Methods=== */
public:
	/**
	* @brief classic ctor
	* @param scene pointer
	*/
	Mouse( std::shared_ptr<Scene> scene );

	/**
	* @brief updates mouse
	* @param scene ptr
	*/
	void update( std::shared_ptr<Scene> scene );
protected:
private:
};
