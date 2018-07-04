/*
mvxxx 2018
https://github.com/mvxxx
*/

#pragma once

#include <SFML/System/Clock.hpp>

/**
* @brief manager for const-step loop
*/
class LoopManager
{
	/* ===Objects=== */
public:
protected:
private:
  //sfml clock for timing
  sf::Clock clock;

  // It is used for managing lopp
  sf::Time timeSinceLastUpdate;

  // Time per each frame
  sf::Time timePerFrame;

	/* ===Methods=== */
public:

	/**
	* @brief ctor
	* @param _timePerFrame - time per frame
	* @see timePerFrame
	*/
  LoopManager(const sf::Time& _timePerFrame);
  
  /**
  * @brief increases time - needed for managing loop
  */
  void increaseTime();

  /**
  * @brief informs app if it can be changed the frame
  */
  bool canChangeTheFrame();

  /**
  * @brief reduce time which is needed for change the frame
  */
  void reduceTime();
protected:
private:
};
