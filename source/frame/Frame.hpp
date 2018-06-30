/*
mvxxx 2017
https://github.com/mvxxx
*/

#pragma once

#include <sfml/Graphics/VertexArray.hpp>
#include "ecs/component/Visible.hpp"
#include "ecs/entity/Entity.hpp"
#include "scene/Scene.hpp"
#include "Math.hpp"

/*not finished*/
class Frame : public mv::Entity, public sf::Drawable
{
	/* ===Objects=== */
public:
  enum class PointType
  {
    START,
    CURRENT
  };

protected:
private:
  sf::Vector2f start;
  sf::Vector2f current;

	/* ===Methods=== */
public:
	Frame( const std::shared_ptr<Scene>& scene );

  void activateSelection(const sf::Vector2f& coords);
  void deactivateSelection();
  void updateSelection(const sf::Vector2f& coords);

  const sf::VertexArray& getFrame();

  void setPoint(const sf::Vector2f& coords, const PointType& status);
protected:
private:
  void initFrame(const std::shared_ptr<Scene>& scene);
  void configureFrame();
  virtual void draw( sf::RenderTarget& target, sf::RenderStates states ) const;
};


