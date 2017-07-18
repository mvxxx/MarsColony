#include "Mouse.hpp"

Mouse::Mouse( std::shared_ptr<Scene> scene )
{
	this->addComponent<ProperBody>();
	auto properBody = this->getComponent<ProperBody>();
	properBody->appendType<sf::Sprite>();

	properBody->getAs<sf::Sprite>().setTexture( *textureAtlas.get( "data/textures/mouseAtlas.png" ) );
	properBody->setCenter();

	border = std::make_shared<Border>( scene );
}

void Mouse::update( std::shared_ptr<Scene> scene )
{
	auto mouseWindowPosition = Math::mouseWindowPosition( scene );
	auto windowSize = scene->getWindow()->getSize();

	this->getComponent<ProperBody>()->getAs<sf::Sprite>().setPosition( Math::mouseWorldPosition( scene ) );

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

std::shared_ptr<Border> Mouse::getBorder()
{
	return border;
}




