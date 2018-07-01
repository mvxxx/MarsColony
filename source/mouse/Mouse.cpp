#include "Mouse.hpp"

Mouse::Mouse( std::shared_ptr<Scene> scene )
{
	this->addComponent<ProperBody>();
	auto properBody = this->getComponent<ProperBody>();
	properBody->appendType<sf::Sprite>();

	properBody->getAs<sf::Sprite>().setTexture( *textureAtlas.get( "data/textures/mouseAtlas.png" ) );
	properBody->setCenter();
	properBody->getAs<sf::Sprite>().setPosition(Utilities::mouseWorldPosition(scene, Scene::viewType_t::DEFAULT));
}

void Mouse::update( std::shared_ptr<Scene> scene )
{
	auto mouseWindowPosition = Utilities::mouseWindowPosition( scene );
	auto windowSize = scene->getWindow()->getSize();

	this->getComponent<ProperBody>()->getAs<sf::Sprite>().setPosition(Utilities::mouseWorldPosition( scene, Scene::viewType_t::UI ) );

	if (Utilities::isInWindow( mouseWindowPosition, scene ) )
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




