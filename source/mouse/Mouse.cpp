#include "Mouse.hpp"

Mouse::Mouse()
{
	this->addComponent<ProperBody>();
	auto body = this->getComponent<ProperBody>()->body;

	body.setTexture( *textureAtlas.get( "data/textures/mouseAtlas.png" ) );
	body.setTextureRect( sf::IntRect( 0, 0, 20, 20 ) );
}

void Mouse::update( std::shared_ptr<Scene> scene )
{
	auto windowPosition = Math::mouseWindowPosition( scene );

	if ( this->getComponent<ProperBody>()->body.getGlobalBounds().contains( static_cast<sf::Vector2f>(sf::Mouse::getPosition( *scene->getWindow() )) ) )
	{
		if ( windowPosition.x > scene->getWindow()->getSize().x - scene->motionSensitivity )
			scene->moveViewRight();
		else if ( windowPosition.x < scene->motionSensitivity )
			scene->moveViewLeft();

		if ( windowPosition.y > scene->getWindow()->getSize().y - scene->motionSensitivity )
			scene->moveViewDown();
		else if ( windowPosition.y < scene->motionSensitivity )
			scene->moveViewTop();
	}
}

void Mouse::draw( sf::RenderTarget& target, sf::RenderStates states ) const
{
	target.draw( *border );
	target.draw( getComponent<ProperBody>()->body, states );
}



