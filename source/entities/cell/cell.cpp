#include "cell.hpp"

Cell::Cell( sf::Vector2f position, sf::Vector2f cellDimensions, sf::Texture& texture, int id )
{
	this->addComponent<ProperBody>();
	this->addComponent<UnitPosition>();
	this->addComponent<Collidable>();

	this->getComponent<ProperBody>()->appendType<sf::Sprite>();

	this->getComponent<ProperBody>()->getAs<sf::Sprite>().setPosition( position );
	this->getComponent<ProperBody>()->getAs<sf::Sprite>().setTexture( texture );
	this->getComponent<ProperBody>()->getAs<sf::Sprite>().setTextureRect( sf::IntRect( static_cast<int>(id*cellDimensions.x), 0, static_cast<int>(cellDimensions.x), static_cast<int>(cellDimensions.y) ) );

	this->getComponent<UnitPosition>()->setUnitPosition(Utilities::convertToUnitPosition( position, cellDimensions ) );

	if(id == mv::constants::id::stone)
	{
		this->getComponent<Collidable>()->setStatus(true);
	}
}
