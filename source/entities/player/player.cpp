#include "player.hpp"

Player::Player(const sf::Vector2f& position,int16_t lev, int64_t experience, float speedValue)
    :state(state_t::STANDBY),level(lev),exp(experience),speed(speedValue)
{
    this->installComponents(position);
    this->setTextureOptions();
    this->assignInputs();

}

void Player::setTextureOptions()
{
    this->getComponent<ProperBody>()->getAs<sf::Sprite>("top")
            .setTexture(*textureCache.get( mv::constants::path::PLAYER_TEXTURE_TOP ));
    this->getComponent<ProperBody>()->setCenter("top");

    this->getComponent<ProperBody>()->getAs<sf::Sprite>("bottom")
            .setTexture(*textureCache.get( mv::constants::path::PLAYER_TEXTURE_BOTTOM ));
    this->getComponent<ProperBody>()->setCenter("bottom");


}

void Player::update(const std::shared_ptr<Scene>& scene, const std::shared_ptr<Mouse>& mouse)
{
    inputControl.update();
    this->getComponent<UnitPosition>()->update(this->getComponent<ProperBody>()->getAs<sf::Sprite>("top").getPosition());

    this->accelerateMotion();

    this->fitTexture(mouse->getComponent<ProperBody>()->getAs<sf::Sprite>().getPosition());
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
    std::vector<sf::Sprite*> sprites = this->getComponent<ProperBody>()->getAllElementsAs<sf::Sprite>();

    for(auto& spritesPtr: sprites)
    {
        spritesPtr->move(this->getComponent<Velocity>()->getAsVector());
    }
}

void Player::fitTexture(const sf::Vector2f& position)
{
    auto velocity = this->getComponent<Velocity>();
    this->fitBottom(velocity);
    this->fitTop(position, velocity);
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

void Player::installComponents(const sf::Vector2f& position)
{
    this->addComponent<ProperBody>();
    this->addComponent<UnitPosition>();
    this->addComponent<Velocity>();
    this->getComponent<ProperBody>()->appendType<sf::Sprite>("top");
    this->getComponent<ProperBody>()->getAs<sf::Sprite>("top").setPosition( position );
    this->getComponent<ProperBody>()->appendType<sf::Sprite>("bottom");
    this->getComponent<ProperBody>()->getAs<sf::Sprite>("bottom").setPosition( position );
}

void Player::assignInputs()
{
    auto own_pointer = std::make_shared<Player>(*this);
    inputControl.addKeyToCheck( sf::Keyboard::A, std::function<void( Player& )>( &Player::moveLeft ),own_pointer );
    inputControl.addKeyToCheck( sf::Keyboard::D, std::function<void( Player& )>( &Player::moveRight ), own_pointer );
    inputControl.addKeyToCheck( sf::Keyboard::S, std::function<void( Player& )>( &Player::moveDown ), own_pointer );
    inputControl.addKeyToCheck( sf::Keyboard::W, std::function<void( Player& )>( &Player::moveTop ), own_pointer );
}

void Player::fitBottom(const std::shared_ptr<Velocity>& velocity)
{
    if(velocity->getValue() != 0)
    {
        int sign = velocity->x < 0 ? -1 : 1;
        this->getComponent<ProperBody>()->getAs<sf::Sprite>("bottom")
                .setRotation(sign*Utilities::angleBetweenVectors({0.f,-1.f},velocity->getAsVector()));
    }
}

void Player::fitTop(const sf::Vector2f& position, const std::shared_ptr<Velocity>& velocity)
{
    auto selfPosition = this->getComponent<ProperBody>()->getAs<sf::Sprite>("top").getPosition();

    float angle = Utilities::angleBetweenVectors(
            {0.f,-1.f},
            sf::Vector2f{position.x-selfPosition.x,position.y-selfPosition.y});

    angle = position.x - selfPosition.x >= 0 ? angle : 360.f - angle;

    this->getComponent<ProperBody>()->getAs<sf::Sprite>("top")
         .setRotation(angle);
}