/*
mvxxx 2017
https://github.com/mvxxx
*/

#pragma once

#include <memory>

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/View.hpp>
#include <SFML/System/Vector2.hpp>

#include "states/State.hpp"
#include "renderer/renderer.hpp"

class Scene
{
	/* ===Objects=== */
public:
	Renderer renderer;
protected:
private:
	std::unique_ptr<State> state;

	std::shared_ptr<sf::RenderWindow> window;
	/* ===Methods=== */
public:

	Scene( const std::string& title, const sf::Vector2f& dimensions );

	bool isOpen() const;

	void close() const;

	void drawAll();

	void clear() const;

	void display() const;

	std::shared_ptr<sf::RenderWindow> getWindow() const;

protected:
private:
};