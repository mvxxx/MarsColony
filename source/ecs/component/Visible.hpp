/*
mvxxx 2017
https://github.com/mvxxx
*/

#pragma once

/*
 * This component excludes from properBody
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

  bool isVisible() 
  {
    return visible;
  }

  void setVisible(bool status)
  {
    visible = status;
  }
protected:
private:
};
