#include "Mouse.hpp"

Mouse::Mouse()
{
	this->addComponent<ProperBody>();
	auto body = this->getComponent<ProperBody>()->body;

	body.setTexture( *textureAtlas.get( "data/textures/mouseAtlas.png" ) );
	body.setTextureRect( sf::IntRect(0,0,20,20) );
}

void Mouse::update( std::shared_ptr<Scene> scene )
{
	sf::Vector2f worldPos = scene->getWindow() -> mapPixelToCoords( sf::Mouse::getPosition( *scene->getWindow() ) );

	this->getComponent<ProperBody>()->body.setPosition( worldPos );

	std::cout << this->getComponent<ProperBody>()->body.getPosition().x << std::endl;
}
