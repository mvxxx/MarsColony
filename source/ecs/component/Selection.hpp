/*
mvxxx 2017
https://github.com/mvxxx
*/

#pragma once

#include <SFML/System/Vector2.hpp>
#include "Math.hpp"

class Selection : public mv::Entity
{
	/* ===Objects=== */
public:
protected:
private:
	/* ===Methods=== */
public:
	Selection();
	void init( std::shared_ptr<Scene> scene );
	sf::VertexArray& getBorder();
protected:
private:
};

inline Selection::Selection()
{
	this->addComponent<ProperBody>();
	this->getComponent<ProperBody>()->appendType<sf::VertexArray>();
}

inline void Selection::init( std::shared_ptr<Scene> scene )
{
	constexpr int8_t ammountOfCorners = 7;

	auto vertexArray = this->getComponent<ProperBody>()->getAs<sf::VertexArray>();

	vertexArray.setPrimitiveType( sf::Lines );
	for ( size_t i = 0; i <= ammountOfCorners; i++ )
	{
		vertexArray.append( sf::Vertex( Math::mouseWorldPosition( scene ) ) );
		vertexArray[i].color = sf::Color::Yellow;
	}
}

inline sf::VertexArray& Selection::getBorder()
{
	return this->getComponent<ProperBody>()->getAs<sf::VertexArray>();
}

