/*
mvxxx 2017
https://github.com/mvxxx
*/

#pragma once

#include <SFML/System/Vector2.hpp>
#include "Math.hpp"
#include "logger/Logger.hpp"



class Selection : public mv::Entity
{
  /* ===Objects=== */
public:
  enum class PointStatus
  {
    START,
    END
  };
protected:
private:
  sf::Vector2f start;
  sf::Vector2f end;

  /* ===Methods=== */
public:
  Selection();
  void init(std::shared_ptr<Scene> scene);
  sf::VertexArray& getBorder();

  void setPoint(const sf::Vector2f& coords, const PointStatus& status);
protected:
private:
  void configureFrame();
};

inline Selection::Selection()
{
  this->addComponent<ProperBody>();
  this->getComponent<ProperBody>()->appendType<sf::VertexArray>();
}

inline void Selection::init(std::shared_ptr<Scene> scene)
{
  constexpr int8_t ammountOfCorners = 7; /*it sums to 8*/

  sf::VertexArray& vertexArray = this->getComponent<ProperBody>()->getAs<sf::VertexArray>();

  vertexArray.setPrimitiveType(sf::Lines);
  for ( size_t i = 0; i <= ammountOfCorners; i++ )
  {
    vertexArray.append(sf::Vertex(Math::mouseWorldPosition(scene)));
    vertexArray[i].color = sf::Color::Yellow;
  }
}

inline sf::VertexArray& Selection::getBorder()
{
  return this->getComponent<ProperBody>()->getAs<sf::VertexArray>();
}

inline void Selection::setPoint(const sf::Vector2f& data, const PointStatus & status)
{
  sf::Vector2f& point = status == PointStatus::START ? start : end;
  mv::Logger::Log((status == PointStatus::START ? "Start Point: " : "End Point ") + std::to_string(point.x) + " " + std::to_string(point.y), mv::Logger::STREAM::CONSOLE, mv::Logger::TYPE::INFO);
  point.x = data.x;
  point.y = data.y;

  if ( status == PointStatus::END )
    configureFrame();
}

inline void Selection::configureFrame()
{
  auto vertexArray = this->getComponent<ProperBody>()->getAs<sf::VertexArray>();
  int t = vertexArray.getVertexCount();
  vertexArray[0].position = start;
  vertexArray[1].position = { start.x,end.y };
  vertexArray[2].position = { start.x,end.y };
  vertexArray[3].position = end;
  vertexArray[4].position = end;
  vertexArray[5].position = { end.x,start.y };
  vertexArray[6].position = { end.x, start.y };
  vertexArray[7].position = start;
  this->getComponent<ProperBody>()->setVisible(true);
}



