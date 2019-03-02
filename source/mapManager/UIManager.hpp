/*
mvxxx 2019
https://github.com/mvxxx
*/
#include <unordered_map>
#include <functional>

#include "../../external/SFML/include/SFML/Graphics/Text.hpp"

#include "../cache/Cache.hpp"
#include "../ecs/entity/Entity.hpp"
#include "../ecs/component/ProperBody.hpp"
#include "IconManager.hpp"

#pragma once

class UIManager :public mv::Entity
{
/* ===Objects=== */
public:
protected:
private:
    sf::Font font;
    /* ===Methods=== */
public:

    /**
     * @brief classic ctor
     * @param iconTexture - cache for icons
     * @param ammo
     * @param health
     */
    UIManager(mv::Cache<sf::Texture>& iconTexture, const sf::View& view, int ammo, int health);

    /**
     * @brief updates score on the scoreboard
     * @param first - score of player
     * @param second - score of enemy
     */
    void updateScore(int first, int second);

    /**
     * @brief update shealth on screen
     * @param health
     */
    void updateHealth(int health);

    /**
     * @brief updates texture of ammo symbol
     * @param weaponType
     */
    void updateAmmoType(int weaponType);

    /**
     * @brief updates displayed number of ammo
     * @param ammo
     */
    void updateAmmoNumber(int ammo);

    /**
     * @brief updates both ammo number and type of weapon
     * @param weaponType
     * @param ammo
     */
    void updateAmmo(int weaponType, int ammo);
protected:
private:

    /**
    * @brief Installs components required for UI
    * @param iconTexture - cache for icons
    */
    void installComponents(mv::Cache<sf::Texture>& iconTexture, const sf::View& view);

    /**
    * @brief Installs texts required for UI
    * @param ammo
    * @param health
    */
    void installTexts(int ammo, int health);
};