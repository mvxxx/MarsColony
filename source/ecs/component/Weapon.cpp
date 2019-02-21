#include "Weapon.hpp"
#include "../../Config.hpp"

Weapon::Weapon(const std::shared_ptr<sf::Texture>& texture,
        const sf::Vector2f& position,
        const Weapon::type& label)
{
    this->appendType<sf::Sprite>();
    this->getAs<sf::Sprite>().setTexture(*texture);
    this->getAs<sf::Sprite>().setPosition(position);

    this->getAs<sf::Sprite>().setTextureRect( sf::IntRect(
            static_cast<int>(static_cast<int>(label)*mv::constants::defaults::WEAPON_DIMENSIONS.x),
            0, static_cast<int>(static_cast<int>(label)*mv::constants::defaults::WEAPON_DIMENSIONS.x),
            static_cast<int>(static_cast<int>(label)*mv::constants::defaults::WEAPON_DIMENSIONS.y)));
}
