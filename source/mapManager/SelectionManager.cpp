#include "SelectionManager.hpp"

SelectionManager::SelectionManager( std::shared_ptr<Scene> _scene )
	:scene( _scene )
{
}

void SelectionManager::callSelection()
{
	std::cout << "PRESSED" << std::endl;
}

void SelectionManager::cancelSelection()
{
	std::cout << "RELASED" << std::endl;
}

void SelectionManager::manage()
{
	sf::Event event;
	
	while ( scene->getWindow()->pollEvent( event ) )
	{
		switch ( event.type )
		{
		case sf::Event::MouseButtonPressed:
		{
			callSelection();
			break;
		}
		case sf::Event::MouseButtonReleased:
		{
			cancelSelection();
			break;
		}
		}
	}
}

void SelectionManager::addEntityToManage( std::shared_ptr<mv::Entity> entity )
{
	this->addEntityToManage( entity );
}
