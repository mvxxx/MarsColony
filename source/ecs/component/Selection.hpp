/*
mvxxx 2017
https://github.com/mvxxx
*/

#pragma once

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/VertexArray.hpp>
#include "Math.hpp"
#include "logger/Logger.hpp"



class Selection
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

  sf::VertexArray frame;
  bool visible;

  /* ===Methods=== */
public:
  void init(std::shared_ptr<Scene> scene);
  const sf::VertexArray& getFrame();

  void setPoint(const sf::Vector2f& coords, const PointStatus& status);
protected:
private:
  void configureFrame();
};


inline void Selection::init(std::shared_ptr<Scene> scene)
{
  visible = false;
  constexpr int8_t ammountOfCorners = 7; /*it sums to 8*/

  frame.setPrimitiveType(sf::Lines);
  for ( size_t i = 0; i <= ammountOfCorners; i++ )
  {
    frame.append(sf::Vertex(Math::mouseWorldPosition(scene)));
    frame[i].color = sf::Color::Yellow;
  }
}

inline const sf::VertexArray& Selection::getFrame()
{
  return frame;
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
  frame[0].position = start;
  frame[1].position = { start.x,end.y };
  frame[2].position = { start.x,end.y };
  frame[3].position = end;
  frame[4].position = end;
  frame[5].position = { end.x,start.y };
  frame[6].position = { end.x, start.y };
  frame[7].position = start;
  visible = true;
}



