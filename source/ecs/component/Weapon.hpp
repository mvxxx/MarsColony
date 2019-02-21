/*
mvxxx 2019
https://github.com/mvxxx
*/

#pragma once

#include "ProperBody.hpp"
#include <string>

/**
 * @brief Component which represents weapon
 */
class Weapon : private ProperBody
{
    /* ===Objects=== */
public:
    enum class type
    {
        machine_gun = 0,
        laser = 1,
        rocket_launcher = 2
    };
protected:
private:
    std::string label;
    uint16_t ammo;
    /* ===Methods=== */
public:
    /**
     * @brief Classic ctor
     * @param texture - of gun's sprite
     * @param position - of gun's sprite
     * @param label - type of weapon
     * @param entitySpr - sprite of player object
     */
    explicit Weapon(const std::shared_ptr<sf::Texture>& texture,
            const sf::Vector2f& position,
            const Weapon::type& label,
            const sf::Sprite& entitySpr);
protected:
private:

    /**
     * @brief Installs components required for player
     * @param texture - of gun's sprite
     * @param position - of gun's sprite
     * @param label - type of weapon
     */
    void installComponents(const std::shared_ptr<sf::Texture>& texture,
                           const sf::Vector2f& position,
                           const Weapon::type& label);

    /**
    * @brief Sets relative position of gun
    * @param label -type of weapon
    * @param entitySpr - sprite of player object
    */
    void setRelativePosition(const Weapon::type& label, const sf::Sprite& entitySpr);
};

