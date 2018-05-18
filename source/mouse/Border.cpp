#include "Border.hpp"

Border::Border( std::shared_ptr<Scene> scene )
{
	this->addComponent<Selection>();
	this->getComponent<Selection>()->init( scene );
}

void Border::draw( sf::RenderTarget& target, sf::RenderStates states ) const
{
	target.draw( this->getComponent<Selection>()->getBorder(), states );
}

void Border::activateSelection(const sf::Vector2f& coords)
{
  this->getComponent<Selection>()->setPoint(coords, Selection::PointStatus::START);
}

void Border::deactivateSelection(const sf::Vector2f& coords)
{
  this->getComponent<Selection>()->setPoint(coords, Selection::PointStatus::END);
}



