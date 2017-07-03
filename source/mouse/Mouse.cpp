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
	this->getComponent<ProperBody>()->body.setPosition( static_cast<sf::Vector2f>(sf::Mouse::getPosition()) );
	std::cout << this->getComponent<ProperBody>()->body.getPosition().x << std::endl;
}
