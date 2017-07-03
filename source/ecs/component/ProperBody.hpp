/*
mvxxx 2017
https://github.com/mvxxx
*/

#pragma once

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

class ProperBody : public sf::Drawable
{
	/* ===Objects=== */
public:
	sf::Sprite body;
	bool collidable;
protected:
private:
	/* ===Methods=== */
public:
	ProperBody()
		:collidable(false)
	{
		body.setOrigin( body.getGlobalBounds().width / 2.f, body.getGlobalBounds().height / 2.f );
	}

	void draw( sf::RenderWindow& window );

protected:
private:
	virtual void draw( sf::RenderTarget& target, sf::RenderStates states ) const;
};

inline void ProperBody::draw(sf::RenderWindow& window)
{
	window.draw( body );
}

inline void ProperBody::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw( body, states );
}
