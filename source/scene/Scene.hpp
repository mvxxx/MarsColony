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

	const float motionSensitivity;
	const float viewSpeed;
protected:
private:

	std::unique_ptr<State> state;

	std::shared_ptr<sf::RenderWindow> window;
	std::shared_ptr<sf::View> view;


	enum class zoom_t
	{
		ZOOM,
		DECREASE
	};

	enum class direction_t
	{
		TOP,
		RIGHT,
		DOWN,
		LEFT
	};

	/* ===Methods=== */
public:

	Scene( const std::string& title, const sf::Vector2f& dimensions );

	bool isOpen() const;

	void close() const;

	void drawAll();

	void clear() const;

	void display() const;

	std::shared_ptr<sf::RenderWindow> getWindow() const;

	void moveViewRight();
	void moveViewLeft();
	void moveViewTop();
	void moveViewDown();

protected:
private:
	void moveView( direction_t direction );
};