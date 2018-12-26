/*
mvxxx 2017
https://github.com/mvxxx
*/

#pragma once

#include "../../../external/SFML/include/SFML/Graphics/Sprite.hpp"
#include "../../../external/SFML/include/SFML/Graphics/Drawable.hpp"
#include "../../../external/SFML/include/SFML/Graphics/RenderTarget.hpp"
#include "../../../external/SFML/include/SFML/Graphics/RenderWindow.hpp"

#include "Visible.hpp"

#include <memory>

/**
* @brief That is the basic physical body of  objects
*/
class ProperBody : public sf::Drawable, public Visible
{
	/* ===Objects=== */
public:
	// body which is able to been drawn
	std::shared_ptr<sf::Drawable> body;

	//inform us if object collide with others
	bool collidable;
protected:
private:
	/* ===Methods=== */
public:
	/**
	* @brief ctor
	*/
  ProperBody()
    :collidable(false)
	{
    visible = true;
  }

  /**
  * @brief sets center of object
  * @warning this object must be type of sprite
  */
	void setCenter()
	{
		if ( sf::Sprite* sprite = dynamic_cast< sf::Sprite* >(&*body) )
		{
			sprite->setOrigin( sprite->getGlobalBounds().width / 2.f, sprite->getGlobalBounds().height / 2.f );
		}
	}

	/**
	* @brief draws object
	* @param window window where object will be drawn
	*/
	void draw( sf::RenderWindow& window );

	/**
	* @brief assign type
	* @param T - type to assign
	*/
	template<class T>
	void appendType()
	{
		body = std::make_shared<T>();
	}

	/**
	* @brief gets object as T
	* @param T - type to assign
	* @return reference to Type
	*/
	template<class T>
	T& getAs()
	{
		return *dynamic_cast<T*>(&*body);
	}

protected:
private:
	/**
	* @brief draws object
	* @param target from SFML
	* @param states from SFML
	*/
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
