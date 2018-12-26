#include "player.hpp"

Player::Player(const sf::Vector2f& position,int16_t lev, int64_t experience)
    :state(state_t::STANDBY),level(lev),exp(experience)
{
    this->addComponent<ProperBody>();
    this->addComponent<UnitPosition>();

    this->getComponent<ProperBody>()->appendType<sf::Sprite>();

    this->getComponent<ProperBody>()->getAs<sf::Sprite>().setPosition( position );

    this->setTextureOptions();

    //loading standby texture atlas
    textureCache.get("data/textures/player.png");

    //loading fighting texture atlas
}

void Player::setTextureOptions()
{
    this->getComponent<ProperBody>()->getAs<sf::Sprite>().setTexture
    (*textureCache.get("data/textures/player.png"));
}
