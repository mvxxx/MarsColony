#include "UIManager.hpp"

UIManager::UIManager(mv::Cache<sf::Texture>& iconTexture, const sf::View& view)
{
    this->installComponents(iconTexture, view);
    this->installTexts();
}

void UIManager::updateScore(int first, int second)
{

}

void UIManager::updateHealth(int health)
{

}

void UIManager::updateAmmoType(int weaponType)
{

}

void UIManager::updateAmmoNumber(int ammo)
{

}

void UIManager::updateAmmo(int weaponType, int ammo)
{

}

void UIManager::installComponents(mv::Cache<sf::Texture>& iconTexture, const sf::View& view)
{
    this->addComponent<ProperBody>();

    std::function<void(std::string, int, const sf::Vector2f&)> setPropeties
    = [=] (const std::string& label, int type, const sf::Vector2f& pos)
            mutable
    {
        this->getComponent<ProperBody>()->appendType<sf::Sprite>(label);
        this->getComponent<ProperBody>()->getAs<sf::Sprite>(label).setTexture
                (*iconTexture.get(mv::constants::path::ICON_TEXTURE_ATLAS));
        this->getComponent<ProperBody>()->getAs<sf::Sprite>(label)
                .setTextureRect(
                        sf::IntRect(
                                static_cast<int>(type*mv::constants::defaults::ICON_DIMENSIONS.x),
                                0, static_cast<int>(mv::constants::defaults::ICON_DIMENSIONS.x),
                                static_cast<int>(mv::constants::defaults::ICON_DIMENSIONS.y))
                        );

        this->getComponent<ProperBody>()->setCenter();
        this->getComponent<ProperBody>()->getAs<sf::Sprite>(label).setPosition(pos);
    };

    setPropeties("health", static_cast<int>(IconManager::bonus_t::health_lite),
            {mv::constants::defaults::ICON_DIMENSIONS.x/2.f,mv::constants::defaults::ICON_DIMENSIONS.y/2.f});
    setPropeties("ammo",static_cast<int>(IconManager::bonus_t::ammo_machine_gun),
                 {mv::constants::defaults::ICON_DIMENSIONS.x/2.f,3*mv::constants::defaults::ICON_DIMENSIONS.y/2.f});

    this->getComponent<ProperBody>()->appendType<sf::Sprite>("scoreboard");
    this->getComponent<ProperBody>()->getAs<sf::Sprite>("scoreboard").setTexture
            (*iconTexture.get(mv::constants::path::SCOREBOARD));
    this->getComponent<ProperBody>()->setCenter();
    this->getComponent<ProperBody>()->getAs<sf::Sprite>("scoreboard")
            .setPosition(view.getSize().x/2.f,
            this->getComponent<ProperBody>()->getAs<sf::Sprite>("scoreboard").getLocalBounds().height/2.f
            +view.getCenter().y-view.getSize().y/2.f);
}

void UIManager::installTexts()
{

}
