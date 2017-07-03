/*
mvxxx 2017
https://github.com/mvxxx
*/

#pragma once

#include "ecs/entity/Entity.hpp"

#include "ecs/component/ProperBody.hpp"
#include "ecs/component/unitPosition.hpp"
#include <SFML/Graphics/RenderTarget.hpp>

#include "Math.hpp"

class Cell : public mv::Entity
{
	/* ===Objects=== */
public:
protected:
private:
	/* ===Methods=== */
public:
	Cell::Cell( sf::Vector2f position, sf::Vector2f cellDimensions, sf::Texture& texture, int id );
protected:
private:
	virtual void draw( sf::RenderTarget& target, sf::RenderStates states );
};