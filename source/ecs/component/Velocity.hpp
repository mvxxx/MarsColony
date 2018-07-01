/*
mvxxx 2017
https://github.com/mvxxx
*/

#pragma once

#include <cmath>

class Velocity
{
	/* ===Objects=== */
public:
	float x;
	float y;
protected:
private:
	/* ===Methods=== */
public:
	Velocity( float x = 0.f, float y = 0.f );

	Velocity operator+( const Velocity& second );
	Velocity operator-( const Velocity& second );
	Velocity operator*( const Velocity& second );
	Velocity operator/( const Velocity& second );

	Velocity operator+( const float& second );
	Velocity operator-( const float& second );
	Velocity operator*( const float& second );
	Velocity operator/( const float& second );

	float getValue();
protected:
private:
};
