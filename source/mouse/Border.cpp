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

void Border::activateSelection(const Point<int>& coords)
{
  this->getComponent<Selection>()->setPoint(coords, Selection::PointStatus::START);
}

void Border::deactivateSelection(const Point<int>& coords)
{
  this->getComponent<Selection>()->setPoint(coords, Selection::PointStatus::END);
}



