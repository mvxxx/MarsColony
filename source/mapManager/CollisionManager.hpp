/*
mvxxx 2019
https://github.com/mvxxx
*/
#pragma once

#include <map>

#include "../ecs/component/Collidable.hpp"
#include "../ecs/entity/Entity.hpp"
#include "manager.hpp"

/**
 * @brief class which manages collision of static objects
 * assigned to it.
 */
class CollisionManager
{
    /* ===Objects=== */
public:
protected:
private:

    /**
     * @brief Checks if entity contains Collidable && UnitPosition components
     * @param entity
     * @return true if entity contains necessary components
     */
    bool checkRequirments(const std::shared_ptr<mv::Entity>& entity);

    std::map<std::pair<int,int>,std::vector<std::shared_ptr<mv::Entity>>> collisionMap;
    /* ===Methods=== */
public:
    /**
    * @brief adds entity to managing loop
    * @param entity - pointer to given object
    */
    void addToCollisionMap( std::shared_ptr<mv::Entity> entity );

    /**
     * @brief Checks if on given (i,j) field collision occurs
     * @param i - x in unit system
     * @param j - y in unit system
     * @return true if collision occurs, false otherwise
     */
    bool checkCollsionStatus(int i, int j) const;

    /**
     * @brief Checks if on given vec(i,j) field collision occurs
     * @param fields - unit positions of fields to consider
     * @return true if collision occurs, false otherwise
     */
    bool checkCollsionStatus(const std::vector<std::pair<int,int>>& fields) const;

protected:
private:
};