/*
mvxxx 2019
https://github.com/mvxxx
*/

#pragma once

#include "../../../external/SFML/include/SFML/Graphics/Texture.hpp"
#include "../../ecs/component/Velocity.hpp"

#include "../../ecs/entity/Entity.hpp"
#include "../../cache/Cache.hpp"
#include "../../Utilities.hpp"
#include "../player/player.hpp"

/**
* @brief bullet class
*/
class Bullet : public mv::Entity
{
    /* ===Objects=== */
public:
protected:
private:
    std::string owner;
    /* ===Methods=== */
public:
    /**
     * @brief classic ctor
     * @param position - position of bullet
     * @param type - id of bullet type
     * @param angle - direction of bullet (in degrees)
     * @param textureCache - texture storage
     */
    Bullet(const sf::Vector2f& position, float angle, int type, mv::Cache<sf::Texture>& textureCache);

    /**
     * @brief continue flight
     * @return false if hit into wall | true otherwise
     */
    bool fly();

    /**
    * @brief checks collision with enemy player
    * @param enemyPlayerPos
    */
    void checkCollisionWithPlayer(const sf::Vector2f& enemyPlayerPos);
protected:
private:
};