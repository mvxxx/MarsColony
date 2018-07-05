#include "Entity.hpp"

mv::Entity::Entity()
{
}

mv::Entity::Entity(const Entity & other) :
	componentWrappers(other.componentWrappers)
{
}

mv::Entity::Entity(Entity && other) :
	componentWrappers(other.componentWrappers)
{
	other.componentWrappers.clear();
}

mv::Entity::~Entity()
{
	componentWrappers.clear();
}

bool mv::Entity::operator==(const Entity & other)
{
	if (componentWrappers.size() != other.componentWrappers.size())
		return false;

	for (int i = 0; i < componentWrappers.size(); i++)
	{
		if (!(componentWrappers[i] == other.componentWrappers[i]))
			return false;
	}

	return true;
}

mv::Entity& mv::Entity::operator=(const Entity & other)
{
	mv::Entity temp(other); //call of copy ctor
	*this = std::move(temp); //reuse move assignment operator
	return *this;
}

mv::Entity& mv::Entity::operator=(Entity && other)
{
	if (&other != this)
	{
		componentWrappers = other.componentWrappers;
	}
	
	return *this;
}
