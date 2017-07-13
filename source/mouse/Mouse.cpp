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
	auto mouseWindowPosition = Math::mouseWindowPosition( scene );
	auto windowSize = scene->getWindow()->getSize();

	if ( Math::isInWindow( mouseWindowPosition, scene ) )
	{
		if ( mouseWindowPosition.x > windowSize.x - scene->motionSensitivity )
			scene->moveViewRight();
		else if ( mouseWindowPosition.x < scene->motionSensitivity )
			scene->moveViewLeft();

		if ( mouseWindowPosition.y > windowSize.y - scene->motionSensitivity )
			scene->moveViewDown();
		else if ( mouseWindowPosition.y < scene->motionSensitivity )
			scene->moveViewTop();
	}
}

void Mouse::draw( sf::RenderTarget& target, sf::RenderStates states ) const
{
	target.draw( *border );
	target.draw( getComponent<ProperBody>()->body, states );
}



