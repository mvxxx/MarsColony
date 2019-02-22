/*
mvxxx 2019
https://github.com/mvxxx
*/

#pragma once

#include "../../ecs/entity/Entity.hpp"
#include "../../ecs/component/ProperBody.hpp"
#include "../../cache/Cache.hpp"

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
    std::shared_ptr<mv::Cache<sf::Texture>> textureCache;

protected:
private:
    float rotateSpeed;
    /* ===Methods=== */
public:

    /**
     * @brief classic ctor
     * @param rotateSpeed - speed of rotation in Z axis
     * @param bonus - type of icon
     * @param cache - texture container
     * @param pos - position of icon
     */
    Icon(float _rotateSpeed, const bonus_t& bonus, std::shared_ptr<mv::Cache<sf::Texture>> cache,
            const sf::Vector2f& pos);

protected:
private:
};