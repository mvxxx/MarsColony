#include "Icon.hpp"

Icon::Icon(float _rotateSpeed, const bonus_t& bonus, std::shared_ptr<mv::Cache<sf::Texture>> cache
        ,const sf::Vector2f& pos)
    :rotateSpeed(_rotateSpeed),
    type(bonus),
    textureCache(std::move(cache))
{
    this->addComponent<ProperBody>();
    this->getComponent<ProperBody>()->appendType<sf::Sprite>();

    this->getComponent<ProperBody>()->getAs<sf::Sprite>(mv::constants::path::ICON_TEXTURE_ATLAS);
    this->getComponent<ProperBody>()->getAs<sf::Sprite>().setTextureRect( sf::IntRect(
            static_cast<int>(static_cast<int>(type)*mv::constants::defaults::ICON_DIMENSIONS.x),
            0, static_cast<int>(mv::constants::defaults::ICON_DIMENSIONS.x),
            static_cast<int>(mv::constants::defaults::ICON_DIMENSIONS.y)));

    this->getComponent<ProperBody>()->setCenter();
    this->getComponent<ProperBody>()->getAs<sf::Sprite>().setPosition(pos);
}
