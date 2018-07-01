/*
mvxxx 2017
https://github.com/mvxxx
*/

#include "Velocity.hpp"

Velocity::Velocity(float _x, float _y )
	:x(_x),y(_y)
{
}

Velocity Velocity::operator+( const Velocity & second )
{
	return Velocity( x + second.x, y + second.y );
}

Velocity Velocity::operator-( const Velocity & second )
{
	return Velocity( x - second.x, y - second.y );
}

Velocity Velocity::operator*( const Velocity & second )
{
	return Velocity( x * second.x, y * second.y );
}

Velocity Velocity::operator/( const Velocity & second )
{
	return Velocity( x / second.x, y / second.y );
}

Velocity Velocity::operator+( const float & second )
{
	return Velocity( x + second, y + second );
}

Velocity Velocity::operator-( const float & second )
{
	return Velocity( x - second, y - second );
}

Velocity Velocity::operator*( const float & second )
{
	return Velocity( x * second, y * second );
}

Velocity Velocity::operator/( const float & second )
{
	return Velocity( x / second, y / second );
}

float Velocity::getValue()
{
	return sqrt( pow( x, 2 ) + pow( y, 2 ) );
}
