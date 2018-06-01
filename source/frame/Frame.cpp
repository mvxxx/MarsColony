#include "Frame.hpp"

Frame::Frame(const std::shared_ptr<Scene>& scene)
{
  this->addComponent<ProperBody>();
  this->getComponent<ProperBody>()->appendType<sf::VertexArray>();
  this->getComponent<ProperBody>()->setVisible(false);
  this->initFrame(scene);
}

void Frame::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
  target.draw(this->getComponent<ProperBody>()->getAs<sf::VertexArray>(), states);
}

void Frame::activateSelection(const sf::Vector2f& coords)
{
  this->getComponent<ProperBody>()->setVisible(true);
  this->setPoint(coords, PointType::START);
}

void Frame::deactivateSelection()
{
  sf::VertexArray& frame = this->getComponent<ProperBody>()->getAs<sf::VertexArray>();

  frame[0].position = { 0,0 };
  frame[1].position = { 0,0 };
  frame[2].position = { 0,0 };
  frame[3].position = { 0,0 };
  frame[4].position = { 0,0 };
  frame[5].position = { 0,0 };
  frame[6].position = { 0,0 };
  frame[7].position = { 0,0 };

  this->getComponent<ProperBody>()->setVisible(false);
}

void Frame::updateSelection(const sf::Vector2f& coords)
{
  this->setPoint(coords, PointType::CURRENT);
}

inline const sf::VertexArray& Frame::getFrame()
{
  return   this->getComponent<ProperBody>()->getAs<sf::VertexArray>();
}

void Frame::setPoint(const sf::Vector2f& data, const PointType & status)
{
  sf::Vector2f& point = status == PointType::START ? start : current;
  point.x = data.x;
  point.y = data.y;
  configureFrame();
}

void Frame::initFrame(const std::shared_ptr<Scene>& scene)
{
  constexpr int8_t ammountOfCorners = 7; /*it sums to 8*/
  sf::VertexArray& frame = this->getComponent<ProperBody>()->getAs<sf::VertexArray>();
  frame.setPrimitiveType(sf::Lines);
  mv::Logger::Log(std::to_string(frame.getVertexCount()));
  for ( size_t i = 0; i <= ammountOfCorners; i++ )
  {
    frame.append(sf::Vertex(Math::mouseWorldPosition(scene)));
    frame[i].color = sf::Color::Yellow;
  }
  mv::Logger::Log(std::to_string(frame.getVertexCount()));
}

void Frame::configureFrame()
{
  sf::VertexArray& frame = this->getComponent<ProperBody>()->getAs<sf::VertexArray>();
  frame[0].position = start;
  frame[1].position = { start.x,current.y };
  frame[2].position = { start.x,current.y };
  frame[3].position = current;
  frame[4].position = current;
  frame[5].position = { current.x,start.y };
  frame[6].position = { current.x, start.y };
  frame[7].position = start;
}




