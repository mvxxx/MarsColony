/*
mvxxx 2019
https://github.com/mvxxx
*/

#pragma once

/**
 * @brief Informs if object is collidable with others
 */
class Collidable
{
    /* ===Objects=== */
public:
protected:
    bool collidable;
private:
    /* ===Methods=== */
public:

    /**
     * @param colliding - true if tile collides with others
     */
    Collidable()
            :collidable(false)
    {}

    /**
    * @brief checks flag of colliding
    * @return collidable flag
    */
    bool isCollidable()
    {
        return collidable;
    }

    /**
    * @brief changes state of collidable flag
    * @param status - new state
    */
    void setStatus(bool status)
    {
        collidable = status;
    }
protected:
private:
};
