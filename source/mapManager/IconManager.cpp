#include "IconManager.hpp"

IconManager::IconManager(const std::vector<std::pair<Icon::bonus_t ,sf::Vector2i>>& positions)
{

    for(auto& var: positions)
    {
        availablePositions[Utilities::vecToPair<int>(var.second)] =
                {var.first, std::make_shared<Icon>(
                        var.first,
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

    return itr->second.second->getComponent<ProperBody>()->isVisible() ? itr->second.second : nullptr;
}


