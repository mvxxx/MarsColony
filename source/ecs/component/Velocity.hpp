/*
mvxxx 2017
https://github.com/mvxxx
*/

#pragma once

#include <cmath>

/**
* @brief Velocity component
*/
class Velocity
{
	/* ===Objects=== */
public:
	//velocity x
	float x; 

	//velocity y
	float y;
protected:
private:
	/* ===Methods=== */
public:
	/**
	* @brief Velocity ctor
	*/
	Velocity( float x = 0.f, float y = 0.f );

	Velocity operator+( const Velocity& second );
	Velocity operator-( const Velocity& second );
	Velocity operator*( const Velocity& second );
	Velocity operator/( const Velocity& second );

	Velocity operator+( const float& second );
	Velocity operator-( const float& second );
	Velocity operator*( const float& second );
	Velocity operator/( const float& second );

	/**
	* @brief returns value of velocity
	*/
	float getValue();
protected:
private:
};
