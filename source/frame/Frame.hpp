/*
mvxxx 2017
https://github.com/mvxxx
*/

#pragma once

#include <sfml/Graphics/VertexArray.hpp>
#include "features/Visible.hpp"
#include "ecs/entity/Entity.hpp"
#include "scene/Scene.hpp"
#include "Math.hpp"

/*not finished*/
class Frame : public sf::Drawable, public Visible
{
	/* ===Objects=== */
public:
  enum class PointType
  {
    START,
    END
  };

protected:
private:
  sf::Vector2f start;
  sf::Vector2f end;

  sf::VertexArray frame;
	/* ===Methods=== */
public:
	Frame( std::shared_ptr<Scene> scene );

  void activateSelection(const sf::Vector2f& coords);
  void deactivateSelection(const sf::Vector2f& coords);

  const sf::VertexArray& getFrame();

  void setPoint(const sf::Vector2f& coords, const PointType& status);
protected:
private:
  void configureFrame();
	virtual void draw( sf::RenderTarget& target, sf::RenderStates states ) const;
};


