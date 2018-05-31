/*
mvxxx 2017
https://github.com/mvxxx
*/

#pragma once

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

#include <ecs/component/Visible.hpp>

class ProperBody : public sf::Drawable, public Visible
{
	/* ===Objects=== */
public:
	std::shared_ptr<sf::Drawable> body;
	bool collidable;
protected:
private:
	/* ===Methods=== */
public:
  ProperBody()
    :collidable(false)
	{
    visible = true;
  }

	void setCenter()
	{
		if ( sf::Sprite* sprite = dynamic_cast< sf::Sprite* >(&*body) )
		{
			sprite->setOrigin( sprite->getGlobalBounds().width / 2.f, sprite->getGlobalBounds().height / 2.f );
		}
	}

	void draw( sf::RenderWindow& window );

	template<class T>
	void appendType()
	{
		body = std::make_shared<T>();
	}

	template<class T>
	T& getAs()
	{
		return *dynamic_cast<T*>(&*body);
	}

protected:
private:
	virtual void draw( sf::RenderTarget& target, sf::RenderStates states ) const;
};

inline void ProperBody::draw(sf::RenderWindow& window)
{
	window.draw( *body );
}

inline void ProperBody::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw( *body, states );
}
