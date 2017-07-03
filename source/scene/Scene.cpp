/*
mvxxx 2017
https://github.com/mvxxx
*/

#include "Scene.hpp"

Scene::Scene( const std::string& title, const sf::Vector2f& dimensions )
{
	window = std::shared_ptr<sf::RenderWindow>( new sf::RenderWindow( sf::VideoMode( dimensions.x, dimensions.y ), title ) );
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

void Scene::clear() const
{
	window->clear();
}

void Scene::display() const
{
	window->display();
}
