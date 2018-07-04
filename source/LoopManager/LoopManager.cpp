/*
mvxxx 2018
https://github.com/mvxxx
*/

#include "LoopManager.hpp"

LoopManager::LoopManager(const sf::Time & _timePerFrame)
  :timePerFrame(_timePerFrame)
{
  timeSinceLastUpdate = sf::Time::Zero;
}

void LoopManager::increaseTime()
{
  timeSinceLastUpdate += clock.restart();
}

bool LoopManager::canChangeTheFrame()
{
  return timeSinceLastUpdate <= timePerFrame;
}

void LoopManager::reduceTime()
{
  timeSinceLastUpdate -= timePerFrame;
}
