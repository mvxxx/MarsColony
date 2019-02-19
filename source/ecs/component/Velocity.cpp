#include "Velocity.hpp"

Velocity::Velocity(float _x, float _y )
	:x(_x),y(_y)
{
}

Velocity Velocity::operator+( const Velocity & second )
{
	return { x + second.x, y + second.y };
}

Velocity Velocity::operator-( const Velocity & second )
{
	return { x - second.x, y - second.y };
}

Velocity Velocity::operator*( const Velocity & second )
{
	return { x * second.x, y * second.y };
}

Velocity Velocity::operator/( const Velocity & second )
{
	return { x / second.x, y / second.y };
}

Velocity Velocity::operator+( const float & second )
{
	return { x + second, y + second };
}

Velocity Velocity::operator-( const float & second )
{
	return { x - second, y - second };
}

Velocity Velocity::operator*( const float & second )
{
	return { x * second, y * second };
}

Velocity Velocity::operator/( const float & second )
{
	return { x / second, y / second };
}

float Velocity::getValue()
{
	return static_cast<float>(sqrt( pow( x, 2 ) + pow( y, 2 ) ));
}

sf::Vector2f Velocity::getAsVector()
{
    return {this->x,this->y};
}
