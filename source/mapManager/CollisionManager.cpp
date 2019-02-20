#include "CollisionManager.hpp"
#include "../ecs/component/unitPosition.hpp"


void CollisionManager::addToCollisionMap(std::shared_ptr<mv::Entity> entity)
{
    if(!this->checkRequirments(entity) || !entity->getComponent<Collidable>()->isCollidable())
    {
        return;
    }

    std::pair<int,int> coordinates = {entity->getComponent<UnitPosition>()->i,
                                          entity->getComponent<UnitPosition>()->j};

    auto vectorItr = collisionMap.find(coordinates);

    if (vectorItr == collisionMap.end())
    {
            collisionMap[coordinates] = {entity};
    }
    else
    {
        if(std::find(vectorItr->second.begin(),vectorItr->second.end(),entity) == vectorItr->second.end())
        {
            vectorItr->second.emplace_back(entity);
        }
        else
        {
            mv::Logger::Log(mv::constants::error::collisionManager::ENTITY_IN_DATA,
                            mv::Logger::STREAM::BOTH,
                            mv::Logger::TYPE::WARNING);
        }
    }

}

bool CollisionManager::checkCollsionStatus(int i, int j)
{
    for(auto& entity : collisionMap[{i,j}])
    {
        if(entity->getComponent<Collidable>()->isCollidable())
            return true;
    }
    return false;
}

bool CollisionManager::checkCollsionStatus(const std::vector<std::pair<int,int>>& fields)
{
    for(auto& pair : fields)
    {
        for(auto& entity : collisionMap[pair])
        {
            if(entity->getComponent<Collidable>()->isCollidable())
                return true;
        }
    }
    return false;
}

bool CollisionManager::checkRequirments(const std::shared_ptr<mv::Entity> &entity)
{
    if(!entity->hasComponent<Collidable>())
    {
        mv::Logger::Log(mv::constants::error::collisionManager::ENTITY_WITHOUT_COLLIDABLE,
                        mv::Logger::STREAM::BOTH,
                        mv::Logger::TYPE::WARNING);
        return false;
    }

    if(!entity->hasComponent<UnitPosition>())
    {
        mv::Logger::Log(mv::constants::error::collisionManager::ENTITY_WITHOUT_UNITPOSITION,
                        mv::Logger::STREAM::BOTH,
                        mv::Logger::TYPE::WARNING);
        return false;
    }

    return true;
}
