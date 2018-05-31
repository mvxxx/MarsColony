#include "Frame.hpp"

Frame::Frame(const std::shared_ptr<Scene>& scene)
{
  this->addComponent<Visible>();
  this->initFrame(scene);
}

void Frame::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
  target.draw(frame, states);
}

void Frame::activateSelection(const sf::Vector2f& coords)
{
  this->setPoint(coords, PointType::START);
}

void Frame::deactivateSelection(const sf::Vector2f& coords)
{
  this->setPoint(coords, PointType::END);
}

inline const sf::VertexArray& Frame::getFrame()
{
  return frame;
}

void Frame::setPoint(const sf::Vector2f& data, const PointType & status)
{
  sf::Vector2f& point = status == PointType::START ? start : end;
  mv::Logger::Log((status == PointType::START ? "Start Point: " : "End Point ") + std::to_string(point.x) + " " + std::to_string(point.y), mv::Logger::STREAM::CONSOLE, mv::Logger::TYPE::INFO);
  point.x = data.x;
  point.y = data.y;

  if ( status == PointType::END )
    configureFrame();
}

void Frame::initFrame(const std::shared_ptr<Scene>& scene)
{
  constexpr int8_t ammountOfCorners = 7; /*it sums to 8*/

  frame.setPrimitiveType(sf::Lines);
  for ( size_t i = 0; i <= ammountOfCorners; i++ )
  {
    frame.append(sf::Vertex(Math::mouseWorldPosition(scene)));
    frame[i].color = sf::Color::Yellow;
  }
}

void Frame::configureFrame()
{
  frame[0].position = start;
  frame[1].position = { start.x,end.y };
  frame[2].position = { start.x,end.y };
  frame[3].position = end;
  frame[4].position = end;
  frame[5].position = { end.x,start.y };
  frame[6].position = { end.x, start.y };
  frame[7].position = start;
}




