#include "UIManager.hpp"

UIManager::UIManager(mv::Cache<sf::Texture>& iconTexture, const sf::View& view, int ammo, int health)
{
    this->installComponents(iconTexture, view);
    if(!font.loadFromFile(mv::constants::path::FONT))
    {
        mv::Logger::Log(mv::constants::error::uimanager::FONT_NOT_LOADED,
                mv::Logger::STREAM::BOTH,mv::Logger::TYPE::ERROR);
    }
    this->installTexts(ammo, health);
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

        this->getComponent<ProperBody>()->setCenter(label);
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

void UIManager::installTexts(int ammo, int health)
{
    std::function<void(const std::string&, const std::string&, const std::string& , const sf::Vector2f&)> textPropeties
    = [=](const std::string& labelText, const std::string& labelIcon, const std::string& str, const sf::Vector2f& shift)
            {
                this->getComponent<ProperBody>()->appendType<sf::Text>(labelText);
                this->getComponent<ProperBody>()->setCenter(labelText);
                this->getComponent<ProperBody>()->getAs<sf::Text>(labelText).setFont(font);
                this->getComponent<ProperBody>()->getAs<sf::Text>(labelText).setString(str);
                this->getComponent<ProperBody>()->getAs<sf::Text>(labelText).setPosition(
                        this->getComponent<ProperBody>()->getAs<sf::Sprite>(labelIcon).getPosition()+shift);
            };

    textPropeties("ammo_text","ammo",std::to_string(ammo),
            sf::Vector2f{0.5f*this->getComponent<ProperBody>()->getAs<sf::Sprite>("ammo").getLocalBounds().width,0});

    textPropeties("health_text","health",std::to_string(health),
                  sf::Vector2f{0.5f*this->getComponent<ProperBody>()->getAs<sf::Sprite>("health").getLocalBounds().width,0});
}
