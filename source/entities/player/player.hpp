#pragma once

#include "../../cache/Cache.hpp"
#include "../../ecs/entity/Entity.hpp"
#include "../../ecs/component/ProperBody.hpp"
#include "../../ecs/component/unitPosition.hpp"
#include "../../Utilities.hpp"


class Player : public mv::Entity
{
    /* ===Objects=== */
public:
protected:
private:
    enum class state_t
    {
        STANDBY,
        FIGHTING
    };

    int16_t level;
    int64_t exp;
    mv::Cache<sf::Texture> textureCache;
    state_t state;
    /* ===Methods=== */
public:

    /**
    * @brief player ctor
    * @param position - position of player
    * @param lev - current level
    * @param experience - current experience
    */
    Player(const sf::Vector2f& position,int16_t lev, int64_t experience);
protected:
private:
    /**
     * @brief sets default texture options
     */
     void setTextureOptions();
};