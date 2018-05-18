/*
mvxxx 2017
https://github.com/mvxxx
*/

#pragma once

#include <sfml/Graphics/VertexArray.hpp>
#include "ecs/entity/Entity.hpp"
#include "scene/Scene.hpp"
#include "ecs/component/Selection.hpp"
#include "Math.hpp"

/*not finished*/
class Border : public mv::Entity, public sf::Drawable
{
	/* ===Objects=== */
public:
protected:
private:
	/* ===Methods=== */
public:
	Border( std::shared_ptr<Scene> scene );

  void activateSelection(const Point<int>& coords);
  void deactivateSelection(const Point<int>& coords);
protected:
private:
	virtual void draw( sf::RenderTarget& target, sf::RenderStates states ) const;
};


