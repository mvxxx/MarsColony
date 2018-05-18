#include "SelectionManager.hpp"

SelectionManager::SelectionManager( std::shared_ptr<Scene> _scene )
	:scene( _scene )
{
  border = std::make_shared<Border>(scene);
}

void SelectionManager::callSelection()
{
  border->activateSelection(Math::mouseWorldPosition(scene));
}

void SelectionManager::cancelSelection()
{
  border->deactivateSelection(Math::mouseWorldPosition(scene));
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
		{//TO DO: add right or left button click   
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
