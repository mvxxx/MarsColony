#include "Icon.hpp"

Icon::Icon(const bonus_t& bonus, const sf::Texture& texture
        ,const sf::Vector2f& pos)
        : type(bonus)
{
    this->addComponent<ProperBody>();
    this->getComponent<ProperBody>()->appendType<sf::Sprite>();

    this->getComponent<ProperBody>()->getAs<sf::Sprite>().setTexture(texture);
    this->getComponent<ProperBody>()->getAs<sf::Sprite>().setTextureRect( sf::IntRect(
            static_cast<int>(static_cast<int>(type)*mv::constants::defaults::ICON_DIMENSIONS.x),
            0, static_cast<int>(mv::constants::defaults::ICON_DIMENSIONS.x),
            static_cast<int>(mv::constants::defaults::ICON_DIMENSIONS.y)));

    this->getComponent<ProperBody>()->setCenter();
    this->getComponent<ProperBody>()->getAs<sf::Sprite>().setPosition(pos);

    this->addComponent<UnitPosition>();
    this->getComponent<UnitPosition>()->update(pos);
}

std::pair<Icon::bonus_t, int16_t> Icon::collect()
{
    return {type,static_cast<int16_t>(mv::constants::icon::VALUES[static_cast<int>(type)])};
}