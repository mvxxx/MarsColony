/*
mvxxx 2017
https://github.com/mvxxx
*/

#include "cell.hpp"

Cell::Cell( sf::Vector2f position, sf::Vector2f cellDimensions, sf::Texture& texture, int id )
{
	this->addComponent<ProperBody>();
	this->addComponent<UnitPosition>();

	this->getComponent<ProperBody>()->body.setPosition( position );
	this->getComponent<ProperBody>()->body.setTexture( texture );
	this->getComponent<ProperBody>()->body.setTextureRect( sf::IntRect( id*cellDimensions.x, 0, cellDimensions.x, cellDimensions.y ) );

	this->getComponent<UnitPosition>()->setUnitPosition( Math::convertToUnitPosition( position, cellDimensions ) );
}
