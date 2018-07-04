#pragma once

/**
* @brief Represents point
*/
template <class T>
class Point
{
public:
	//x
  T x;
  
  //y
  T y;

  /**
  * @brief classic ctor
  * @param x - given x-coordinate
  * @param y - given y-coordinate
  */
  Point(const T& _x, const T& _y)
    :x(_x), y(_y){}

  /**
  * @brief classic ctor
  */
  Point()
  {}
};