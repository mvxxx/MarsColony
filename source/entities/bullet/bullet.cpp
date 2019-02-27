#include "bullet.hpp"

Bullet::Bullet(const sf::Vector2f &position, float angle, int type, mv::Cache <sf::Texture> &textureCache)
{
    this->addComponent<Velocity>();
    this->addComponent<ProperBody>();
    this->getComponent<Velocity>()->x = mv::constants::bullet::speed * std::cos(Utilities::degreeToRadian(angle));
    this->getComponent<Velocity>()->y = mv::constants::bullet::speed * std::sin(Utilities::degreeToRadian(angle));

    this->getComponent<ProperBody>()->appendType<sf::Sprite>();
    this->getComponent<ProperBody>()->getAs<sf::Sprite>().setTexture(
            *textureCache.get(mv::constants::path::BULLET_TEXTURE_ATLAS));

    this->getComponent<ProperBody>()->getAs<sf::Sprite>().setTextureRect( sf::IntRect(
            static_cast<int>(type*mv::constants::defaults::WEAPON_DIMENSIONS.x),
            0, static_cast<int>(mv::constants::defaults::WEAPON_DIMENSIONS.x),
            static_cast<int>(mv::constants::defaults::WEAPON_DIMENSIONS.y)));

    this->getComponent<ProperBody>()->getAs<sf::Sprite>().setPosition(position);
}

bool Bullet::fly()
{
    return false;
}

void Bullet::checkCollisionWithPlayer(const sf::Vector2f &enemyPlayerPos)
{

}
