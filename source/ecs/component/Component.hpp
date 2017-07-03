/*
mvxxx 2017
https://github.com/mvxxx
*/

#pragma once

#include <memory>
#include "ecs/entity/Entity.hpp"

namespace mv
{
	class Component
	{
		/* ===Objects=== */
	public:
	protected:
	private:
		std::shared_ptr<Entity> owner;
		/* ===Methods=== */
	public:
		Component( std::shared_ptr<Entity> ptr )
			:owner( ptr )
		{ }

		std::shared_ptr<Entity> getOwner() const
		{
			return owner;
		}
	protected:
	private:
	};
}