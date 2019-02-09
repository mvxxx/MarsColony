/*
mvxxx 2019
https://github.com/mvxxx
*/

#pragma once

/**
 * @brief This component excludes from properBody
 * mainly for UI
 */
class Visible
{
	/* ===Objects=== */
public:
protected:
  bool visible;
private:
  /* ===Methods=== */
public:
  Visible()  
    :visible(false)
  {}

  /**
  * @brief checks flag of visible
  * @return visible flag
  */
  bool isVisible() 
  {
    return visible;
  }

  /**
  * @brief changes state of visible flag
  * @param status - new state
  */
  void setVisible(bool status)
  {
    visible = status;
  }
protected:
private:
};
