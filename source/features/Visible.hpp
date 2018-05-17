/*
mvxxx 2017
https://github.com/mvxxx
*/

#pragma once

class Visible
{
	/* ===Objects=== */
public:
protected:
  bool visible;
private:
  /* ===Methods=== */
public:
  Visible(bool status)
    :visible(status)
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
