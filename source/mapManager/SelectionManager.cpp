#include "SelectionManager.hpp"

SelectionManager::SelectionManager( std::shared_ptr<Scene> _scene )
	:scene( _scene )
{
  frame = std::make_shared<Frame>(scene);
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
      frame->activateSelection(Utilities::mouseWorldPosition(scene,Scene::viewType_t::DEFAULT));
			break;
		}
		case sf::Event::MouseButtonReleased:
		{
      frame->deactivateSelection();
      break;
		}

    case sf::Event::MouseMoved:
    {
      frame->updateSelection(Utilities::mouseWorldPosition(scene, Scene::viewType_t::DEFAULT));
	  break;
    }
		}
	}
}

std::shared_ptr<Frame> SelectionManager::getFrame()
{
  return frame;
}
