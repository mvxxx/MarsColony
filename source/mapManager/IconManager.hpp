/*
mvxxx 2019
https://github.com/mvxxx
*/

#pragma once

#include "../../external/SFML/include/SFML/System/Vector2.hpp"
#include "../../external/SFML/include/SFML/System/Clock.hpp"

#include "../entities/icon/Icon.hpp"
#include "../Utilities.hpp"

#include <map>
#include <queue>
#include <memory>

class IconManager
{
    /* ===Objects=== */
public:
protected:
private:
    //possible positions of icons
    std::map<std::pair<int,int>,std::pair<Icon::bonus_t,std::shared_ptr<Icon>>> availablePositions;


    //used for spawns icons
    sf::Clock timer;

    //requests for spawn icons
    std::queue<sf::Vector2i> requests;

    mv::Cache<sf::Texture> iconTextures;
    /* ===Methods=== */
public:
    /**
     * @brief classic ctor
     * @param positions - available positions for icons' spawn (with given type)
     */
    explicit IconManager(const std::vector<std::pair<Icon::bonus_t ,sf::Vector2i>>& positions);

    /**
     * @brief manages icons, spawns them, control timer
     */
    void update();

    /**
     * @brief looking for icon which is touched by entity
     * @param unitPos - unit position of considered entity
     * @return pointer to touched icon | if entity doesn't touch anything, then nullptr
     */
    std::shared_ptr<Icon> getTouchedIcon(const sf::Vector2i& unitPos);
protected:
private:
};