/*
mvxxx 2019
https://github.com/mvxxx
*/

#pragma once

#include "../../../external/SFML/include/SFML/Graphics/Sprite.hpp"
#include "../../../external/SFML/include/SFML/Graphics/Drawable.hpp"
#include "../../../external/SFML/include/SFML/Graphics/RenderTarget.hpp"
#include "../../../external/SFML/include/SFML/Graphics/RenderWindow.hpp"

#include "Visible.hpp"

#include <memory>
#include <map>

/**
* @brief That is the basic physical body of  objects
*/
class ProperBody : public sf::Drawable, public Visible
{
	/* ===Objects=== */
public:
	// body which is able to been drawn
	// key - label to recognize drawable object
	// if object contains only one element in body - then use "default" label
	std::map<std::string, std::shared_ptr<sf::Drawable>> body;

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
  * @info if not specified, then sets center for all
  */
	void setCenter(const std::string& label)
	{
		if ( sf::Sprite* sprite = dynamic_cast< sf::Sprite* >(&*(body[label]) ))
		{
			sprite->setOrigin( sprite->getGlobalBounds().width / 2.f, sprite->getGlobalBounds().height / 2.f );
		}
	}
	void setCenter()
	{
		for(auto& element: body)
		{
			this->setCenter( element.first );
		}
	}

	/**
	* @brief draws object
	* @param window window where object will be drawn
	*/
	void draw( sf::RenderWindow& window );

	/**
	* @brief assign type
	* @param label - label for recognizing drawable object
	* @param T - type to assign
	*/
	template<class T>
	void appendType( const std::string& label )
	{
		body[label] = std::make_shared<T>();
	}

	template<class T>
	void appendType()
	{
		this->appendType<T>("default");
	}

	/**
	* @brief gets object as T
	* @param T - type to assign
	* @param label - label for recognizing drawable object
	* @return reference to Type
	*/
	template<class T>
	T& getAs( const std::string& label )
	{
		return *dynamic_cast<T*>(&*(body[label]));
	}

	template<class T>
	T& getAs()
	{
		return this->getAs<T>("default");
	}

	/**
	 * @brief returns container of the whole body
	 * @return std::vector with references
	 */

	template<class T>
	std::vector<T*> getAllElementsAs()
	{
		std::vector<T*> container = {};

		for(auto& element: body)
		{
			container.emplace_back(dynamic_cast<T*>(&*(element.second)));
		}

		return container;
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
	for(auto& element: body)
	{
		window.draw( *element.second );
	}
}

inline void ProperBody::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for(auto& element: body)
	{
		target.draw( *element.second, states );
	}
}
