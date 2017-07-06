/*
mvxxx 2017
https://github.com/mvxxx
*/

#pragma once

#include <sfml/Graphics/VertexArray.hpp>
#include "ecs/entity/Entity.hpp"
#include "scene/Scene.hpp"
#include "Math.hpp"

class Border : public mv::Entity
{
	/* ===Objects=== */
public:
protected:
private:
	sf::VertexArray selection;
	/* ===Methods=== */
public:
	Border( std::shared_ptr<Scene> scene );
protected:
private:
};


