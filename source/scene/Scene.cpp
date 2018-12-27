/*
mvxxx 2017
https://github.com/mvxxx
*/

#include "Scene.hpp"
#include "../Config.hpp"
#include "../mapManager/SelectionManager.hpp"

Scene::Scene( const std::string& title, const sf::Vector2f& dimensions)
	:viewSpeed( 10.f ),
	motionSensitivity( 50.f ),
	zoomSpeed( 0.05f )
{
	window = std::shared_ptr<sf::RenderWindow>(
		new sf::RenderWindow( 
			sf::VideoMode( static_cast<unsigned int>(dimensions.x), static_cast<unsigned int>(dimensions.y) ), 
			title) );

	views[viewType_t::DEFAULT] = std::make_shared<sf::View>();
	views[viewType_t::UI] = std::make_shared<sf::View>();

	window->setView( *views[viewType_t::DEFAULT] );
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
	renderer.drawAll( *window, views[viewType_t::DEFAULT], views[viewType_t::UI] );
}

std::shared_ptr<sf::RenderWindow> Scene::getWindow() const
{
	return window;
}

void Scene::moveViewRight()
{
	moveDefaultView( direction_t::RIGHT );
}

void Scene::moveViewLeft()
{
	moveDefaultView( direction_t::LEFT );
}

void Scene::moveViewTop()
{
	moveDefaultView( direction_t::TOP );
}

void Scene::moveViewDown()
{
	moveDefaultView( direction_t::DOWN );
}

void Scene::handleEventTypes( const eventWrapper_t& eventList )
{
	for ( auto&type : eventList.list )
	{
		switch ( type.eventInfo )
		{
			case sf::Event::Closed:
			{
				this->close();
				break;
			}

			case sf::Event::MouseWheelMoved:
			{
				for(auto& add :type.additionals)
				{
					if(add == "-z")
					{
						this->zoom( Scene::zoom_t::ZOOM );
					}
					else if(add == "-d")
					{
						this->zoom( Scene::zoom_t::DECREASE );
					}
				}

				break;
			}
		}
	}
}

void Scene::clear() const
{
	window->clear();
}

void Scene::display() const
{
	window->display();
}

void Scene::zoom( const zoom_t& type )
{
	window->setView( *views[viewType_t::DEFAULT] );

	if ( type == zoom_t::ZOOM )
		views[viewType_t::DEFAULT]->zoom( 1 + zoomSpeed );
	else
		views[viewType_t::DEFAULT]->zoom( 1 - zoomSpeed );

	window->setView( *views[viewType_t::UI] );
}

void Scene::setView(viewType_t type)
{
	window->setView( *views[type] );
}


void Scene::moveDefaultView( direction_t direction )
{
	window->setView( *views[viewType_t::DEFAULT] );
	switch ( direction )
	{
	case direction_t::TOP:
	{
		views[viewType_t::DEFAULT]->move( 0, -viewSpeed );
		break;
	}
	case direction_t::RIGHT:
	{
		views[viewType_t::DEFAULT]->move( viewSpeed, 0 );
		break;
	}
	case direction_t::DOWN:
	{
		views[viewType_t::DEFAULT]->move( 0, viewSpeed );
		break;
	}
	case direction_t::LEFT:
	{
		views[viewType_t::DEFAULT]->move( -viewSpeed, 0 );
		break;
	}
	}
	window->setView( *views[viewType_t::UI] );
}

void Scene::moveDefaultView(const sf::Vector2f &vec)
{
    window->setView( *views[viewType_t::DEFAULT] );
	views[viewType_t::DEFAULT]->move(vec);
    window->setView( *views[viewType_t::UI] );
}
