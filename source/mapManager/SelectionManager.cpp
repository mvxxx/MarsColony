#include "SelectionManager.hpp"

SelectionManager::SelectionManager( std::shared_ptr<Scene> _scene )
	:scene( _scene )
{
  border = std::make_shared<Border>(scene);
}

void SelectionManager::callSelection()
{
	std::cout << "PRESSED" << std::endl;
 // scene->

}

void SelectionManager::cancelSelection()
{
	std::cout << "RELASED" << std::endl;
}

void SelectionManager::addEntityToManage( std::shared_ptr<mv::Entity> entity )
{
	this->addEntityToManage( entity );
}

void SelectionManager::handleEventTypes(const eventWrapper_t& eventList)
{
	for ( auto&type : eventList.list )
	{
		switch ( type )
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

std::shared_ptr<Border> SelectionManager::getBorder()
{
  return border;
}
