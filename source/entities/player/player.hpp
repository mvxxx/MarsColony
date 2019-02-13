/*
mvxxx 2019
https://github.com/mvxxx
*/

#pragma once

#include "../../cache/Cache.hpp"
#include "../../ecs/entity/Entity.hpp"
#include "../../ecs/component/ProperBody.hpp"
#include "../../ecs/component/unitPosition.hpp"
#include "../../ecs/component/Velocity.hpp"
#include "../../inputManager/InputManager.hpp"
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
    float speed;
    mv::Cache<sf::Texture> textureCache;
    state_t state;
    mv::InputManager<Player> inputControl;
    /* ===Methods=== */
public:

    /**
    * @brief player ctor
    * @param position - position of player
    * @param lev - current level
    * @param experience - current experience
    */
    Player(const sf::Vector2f& position,int16_t lev, int64_t experience, float speedValue);

    /**
     * @brief updates player's behavior
     */
    void update(const std::shared_ptr<Scene>& scene);
protected:
private:
    /**
     * @brief sets default texture options
     */
     void setTextureOptions();

    /**
     * @brief move player top
     */
     void moveTop();

    /**
    * @brief move view right
    */
     void moveRight();

    /**
    * @brief move view down
    */
     void moveDown();

    /**
    * @brief move view left
    */
     void moveLeft();

    /**
    * @brief moves player in use of velocity data
    */
     void accelerateMotion();

    /**
    * @brief fits texture to actual state of motion
    */
     void fitTexture();

    /**
    * @brief Updates position of view
    */
     void adaptView(const std::shared_ptr<Scene>& scene);

    /**
    * @brief Reduces velocity after move
    */
     void reduceVelocity();

     /**
     * @brief Installs components required for player
     */
     void installComponents(const sf::Vector2f& position);

    /**
    * @brief Assigns inputs required for player
    */
     void assignInputs();
};