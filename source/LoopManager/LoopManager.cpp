/*
mvxxx 2018
https://github.com/mvxxx
*/

#include "LoopManager.hpp"

LoopManager::LoopManager(const sf::Time & timePerFrame)
  :TimePerFrame(timePerFrame)
{
  timeSinceLastUpdate = sf::Time::Zero;
}

void LoopManager::increaseTime()
{
  timeSinceLastUpdate += clock.restart();
}

bool LoopManager::canChangeTheFrame()
{
  return timeSinceLastUpdate <= TimePerFrame;
}

void LoopManager::reduceTime()
{
  timeSinceLastUpdate -= TimePerFrame;
}
