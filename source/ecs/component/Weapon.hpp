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
     */
    explicit Weapon(const std::shared_ptr<sf::Texture>& texture,
            const sf::Vector2f& position,
            const Weapon::type& label);
protected:
private:
};

