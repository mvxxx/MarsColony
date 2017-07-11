/*
mvxxx 2017
https://github.com/mvxxx
*/

#include "Scene.hpp"

Scene::Scene( const std::string& title, const sf::Vector2f& dimensions )
	:viewSpeed( 0.2f ), motionSensitivity( 50.f )
{
	window = std::shared_ptr<sf::RenderWindow>( new sf::RenderWindow( sf::VideoMode( dimensions.x, dimensions.y ), title ) );
	view = std::make_shared<sf::View>();

	window->setView( *view );
}

bool Scene::isOpen() const
{
	return window->isOpen();
}

void Scene::close() const
{
	window->close();
}

void Scene::drawAll()
{
	renderer.drawAll( *window );
}

std::shared_ptr<sf::RenderWindow> Scene::getWindow() const
{
	return window;
}

void Scene::moveViewRight()
{
	moveView( direction_t::RIGHT );
}

void Scene::moveViewLeft()
{
	moveView( direction_t::LEFT );
}

void Scene::moveViewTop()
{
	moveView( direction_t::TOP );
}

void Scene::moveViewDown()
{
	moveView( direction_t::DOWN );
}

void Scene::clear() const
{
	window->clear();
}

void Scene::display() const
{
	window->display();
}

void Scene::moveView( direction_t direction )
{
	switch ( direction )
	{
	case direction_t::TOP:
	{
		view->move( 0, -viewSpeed );
		break;
	}
	case direction_t::RIGHT:
	{
		view->move( viewSpeed, 0 );
		break;
	}
	case direction_t::DOWN:
	{
		view->move( 0, viewSpeed );
		break;
	}
	case direction_t::LEFT:
	{
		view->move( -viewSpeed, 0 );
		break;
	}
	}
	window->setView( *view );
}
