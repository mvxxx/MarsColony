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
#include "../../mapManager/CollisionManager.hpp"
#include "../../Utilities.hpp"
#include "../../mouse/Mouse.hpp"


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
     * @param scene - pointer for main scene
     * @param colManager - collsion manager for static elements of map
     */
    void update(const std::shared_ptr<Scene>& scene, const CollisionManager& colManager);
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
    * @param position - postion of mouse
    * @param velocity - velocity component of player
    */
     void fitTexture(const sf::Vector2f& position);

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

     /**
     * @brief fits bottom texture
     * @param velocity - velocity component of player
     */
     void fitBottom(const std::shared_ptr<Velocity>& velocity);

    /**
    * @brief fits top texture
    * @param position - postion of mouse
    * @param velocity - velocity component of player
    */
    void fitTop(const sf::Vector2f& position, const std::shared_ptr<Velocity>& velocity);

    /**
     * @param colManager - collision manager for static elements of map
     * @return true if movement is possible, false otherwise
     */
    bool isAbleToMove(const CollisionManager& colManager);
};