/*
mvxxx 2019
https://github.com/mvxxx
*/

#pragma once

#include "../../ecs/entity/Entity.hpp"
#include "../../ecs/component/ProperBody.hpp"
#include "../../cache/Cache.hpp"
#include "../../ecs/component/unitPosition.hpp"

class Icon : public mv::Entity
{
    /* ===Objects=== */
public:
    enum class bonus_t
    {
        ammo_machine_gun,
        ammo_rocket_launcher,
        ammo_laser,
        health_lite,
        health_medium,
        health_ultra
    };

    const bonus_t type;

protected:
private:
    /* ===Methods=== */
public:

    /**
     * @brief classic ctor
     * @param rotateSpeed - speed of rotation in Z axis
     * @param bonus - type of icon
     * @param texture - for icon
     * @param pos - position of icon
     */
    Icon(const bonus_t& bonus, const sf::Texture& texture,
            const sf::Vector2f& pos);

    /**
     * @brief collects that icon
     * @return type of bonus and value
     */
    std::pair<bonus_t,int16_t> collect();
protected:
private:
};