/*
mvxxx 2017
https://github.com/mvxxx
*/

#pragma once

#include <SFML/System/Vector2.hpp>
#include "Component.hpp"

//Use it instead of properBody

class SimpleDrawable : public sf::Drawable
{
	/* ===Objects=== */
public:
	bool visible;
protected:
private:
	std::shared_ptr<sf::Drawable> core;
	/* ===Methods=== */
public:
	SimpleDrawable();

	template<class T>
	void appendType();

	std::shared_ptr<sf::Drawable> getCore();

protected:
private:
	virtual void draw( sf::RenderTarget& target, sf::RenderStates states ) const;
};

template <class T>
void SimpleDrawable::appendType()
{
	core = std::make_shared<T>();
}

inline SimpleDrawable::SimpleDrawable()
	:visible( true )
{
}

inline std::shared_ptr<sf::Drawable> SimpleDrawable::getCore()
{
	return core;
}

inline void SimpleDrawable::draw( sf::RenderTarget& target, sf::RenderStates states ) const
{
	target.draw( *core, states );
}




