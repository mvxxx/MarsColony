#include "player.hpp"

Player::Player(const sf::Vector2f& position,int16_t lev, int64_t experience, float speedValue)
    :state(state_t::STANDBY),level(lev),exp(experience),speed(speedValue)
{
    this->addComponent<ProperBody>();
    this->addComponent<UnitPosition>();
    this->addComponent<Velocity>();
    this->getComponent<ProperBody>()->appendType<sf::Sprite>();
    this->getComponent<ProperBody>()->getAs<sf::Sprite>().setPosition( position );
    this->setTextureOptions();

    auto own_pointer = std::make_shared<Player>(*this);
    inputControl.addKeyToCheck( sf::Keyboard::A, std::function<void( Player& )>( &Player::moveLeft ),own_pointer );
    inputControl.addKeyToCheck( sf::Keyboard::D, std::function<void( Player& )>( &Player::moveRight ), own_pointer );
    inputControl.addKeyToCheck( sf::Keyboard::S, std::function<void( Player& )>( &Player::moveDown ), own_pointer );
    inputControl.addKeyToCheck( sf::Keyboard::W, std::function<void( Player& )>( &Player::moveTop ), own_pointer );

    //loading standby texture atlas
    textureCache.get("data/textures/player.png");

    //loading fighting texture atlas
}

void Player::setTextureOptions()
{
    this->getComponent<ProperBody>()->getAs<sf::Sprite>().setTexture
    (*textureCache.get("data/textures/player.png"));
}

void Player::update()
{
    inputControl.update();
}

void Player::moveTop()
{
    this->getComponent<ProperBody>()->getAs<sf::Sprite>().move( 0.f ,-mv::constants::mob::DEFAULT_SPEED * this->speed );
}

void Player::moveRight()
{
    this->getComponent<ProperBody>()->getAs<sf::Sprite>().move( mv::constants::mob::DEFAULT_SPEED * this->speed, 0.f );
}

void Player::moveDown()
{
    this->getComponent<ProperBody>()->getAs<sf::Sprite>().move( 0.f , mv::constants::mob::DEFAULT_SPEED * this->speed );
}

void Player::moveLeft()
{
    this->getComponent<ProperBody>()->getAs<sf::Sprite>().move( -mv::constants::mob::DEFAULT_SPEED * this->speed, 0.f );
}
