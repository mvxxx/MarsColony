/*
mvxxx 2018
https://github.com/mvxxx
*/

#pragma once

#include <SFML/System/Clock.hpp>

class LoopManager
{
	/* ===Objects=== */
public:
protected:
private:
  sf::Clock clock;
  sf::Time timeSinceLastUpdate;
  sf::Time TimePerFrame;
	/* ===Methods=== */
public:
  LoopManager(const sf::Time& timePerFrame);

  void increaseTime();
  bool canChangeTheFrame();
  void reduceTime();
protected:
private:
};
