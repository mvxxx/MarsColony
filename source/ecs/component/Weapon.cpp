#include "Weapon.hpp"
#include "../../Config.hpp"

Weapon::Weapon(const std::shared_ptr<sf::Texture>& texture,
        const sf::Vector2f& position,
        const Weapon::type& label,
        const sf::Sprite& entitySpr)
{

    this->installComponents(texture, position, label);
    this->setRelativePosition(label, entitySpr);
}

void Weapon::installComponents(const std::shared_ptr<sf::Texture> &texture, const sf::Vector2f &position,
                               const Weapon::type &label)
{
    this->appendType<sf::Sprite>();
    this->getAs<sf::Sprite>().setTexture(*texture);
    this->getAs<sf::Sprite>().setPosition(position);

    this->getAs<sf::Sprite>().setTextureRect( sf::IntRect(
            static_cast<int>(static_cast<int>(label)*mv::constants::defaults::WEAPON_DIMENSIONS.x),
            0, static_cast<int>(static_cast<int>(label)*mv::constants::defaults::WEAPON_DIMENSIONS.x),
            static_cast<int>(static_cast<int>(label)*mv::constants::defaults::WEAPON_DIMENSIONS.y)));
}

void Weapon::setRelativePosition(const Weapon::type &label, const sf::Sprite& entitySpr)
{
    int8_t sign = -1;
    switch(static_cast<int>(label))
    {
        case static_cast<int>(type::machine_gun):
            sign = 1;
            break;

        default:
            break;
    }
    this->getAs<sf::Sprite>().setPosition(
            entitySpr.getPosition().x+sign*entitySpr.getGlobalBounds().width*(0.5f-mv::constants::weapon::shift),
            entitySpr.getPosition().y+sign*entitySpr.getGlobalBounds().height*(0.5f-mv::constants::weapon::shift)
    );
}
