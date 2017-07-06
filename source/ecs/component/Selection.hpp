/*
mvxxx 2017
https://github.com/mvxxx
*/

#pragma once

#include <SFML/System/Vector2.hpp>
#include "Math.hpp"

class Selection
{
	/* ===Objects=== */
public:
protected:
private:
	sf::VertexArray selection;
	/* ===Methods=== */
public:
	void init( std::shared_ptr<Scene> scene );
	sf::VertexArray& getBorder();
protected:
private:
};

inline void Selection::init(std::shared_ptr<Scene> scene)
{
	constexpr int8_t ammountOfCorners = 7;

	selection.setPrimitiveType( sf::Lines );
	for ( size_t i = 0; i <= ammountOfCorners; i++ )
	{
		selection.append( sf::Vertex( Math::mouseWorldPosition( scene ) ) );
		selection[i].color = sf::Color::Yellow;
	}
}

inline sf::VertexArray& Selection::getBorder()
{
	return selection;
}

