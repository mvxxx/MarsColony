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

void Player::update(const std::shared_ptr<Scene>& scene)
{
    inputControl.update();
    this->accelerateMotion();
    this->fitTexture();
    this->adaptView(scene);
    this->reduceVelocity();
}

void Player::moveTop()
{
    this->getComponent<Velocity>()->y -= speed * mv::constants::mob::DEFAULT_SPEED;
}

void Player::moveRight()
{
    this->getComponent<Velocity>()->x += speed * mv::constants::mob::DEFAULT_SPEED;
}

void Player::moveDown()
{
    this->getComponent<Velocity>()->y += speed * mv::constants::mob::DEFAULT_SPEED;
}

void Player::moveLeft()
{
    this->getComponent<Velocity>()->x -= speed * mv::constants::mob::DEFAULT_SPEED;
}

void Player::accelerateMotion()
{
    this->getComponent<ProperBody>()->getAs<sf::Sprite>().move
            (this->getComponent<Velocity>()->getAsVector());
}

void Player::fitTexture()
{
    //todo
}

void Player::adaptView(const std::shared_ptr<Scene>& scene)
{
    scene->moveDefaultView(this->getComponent<Velocity>()->getAsVector());
}

void Player::reduceVelocity()
{
    auto velocity = this->getComponent<Velocity>();
    velocity->x = 0;
    velocity->y = 0;
}
