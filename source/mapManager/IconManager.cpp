#include "IconManager.hpp"

IconManager::IconManager(const std::vector<std::pair<bonus_t ,sf::Vector2i>>& positions)
{

    for(auto& var: positions)
    {
        availablePositions[Utilities::vecToPair<int>(var.second)] =
                {var.first, std::make_shared<Icon>(
                        static_cast<int>(var.first),
                        *iconTextures.get(mv::constants::path::ICON_TEXTURE_ATLAS),
                        sf::Vector2f{mv::constants::defaults::ICON_DIMENSIONS.x*var.second.x,
                                     mv::constants::defaults::ICON_DIMENSIONS.y*var.second.y})};
    }
}

void IconManager::update()
{
    if(!requests.empty() && timer.getElapsedTime().asSeconds() >= mv::constants::icon::respawnTime)
    {
            availablePositions[Utilities::vecToPair<int>(requests.front())].second->
            getComponent<ProperBody>()->setVisible(true);
            requests.pop();
            timer.restart();
    }

}

std::shared_ptr<Icon> IconManager::getTouchedIcon(const sf::Vector2i &unitPos)
{
    auto itr = availablePositions.find(Utilities::vecToPair<int>(unitPos));

    if(itr == availablePositions.end())
    {
        return nullptr;
    }

    if(itr->second.second->getComponent<ProperBody>()->isVisible())
    {
        itr->second.second->getComponent<ProperBody>()->setVisible(false);

        if(requests.empty())
        {
            timer.restart();
        }

        requests.emplace(unitPos);
        return itr->second.second;
    }

    return nullptr;
}

std::vector<std::shared_ptr<mv::Entity>> IconManager::getIconsContainer()
{
    auto vec = std::vector<std::shared_ptr<mv::Entity>>();

    for(auto& var: availablePositions)
    {
        vec.emplace_back(var.second.second);
    }

    return vec;
}

mv::Cache<sf::Texture> &IconManager::getIconTextures()
{
    return iconTextures;
}


