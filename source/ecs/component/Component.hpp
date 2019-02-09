/*
mvxxx 2019
https://github.com/mvxxx
*/

#pragma once

#include <memory>
#include "../entity/Entity.hpp"



namespace mv
{
	/**
	* @brief component class
	* currently not used
	*/
	class Component
	{
		/* ===Objects=== */
	public:
	protected:
	private:

		//parent of component
		std::shared_ptr<Entity> owner;
		/* ===Methods=== */
	public:
		/**
		* @brief ctor
		* @param ptr - pointer to parent
		*/
		Component( std::shared_ptr<Entity> ptr )
			:owner( ptr )
		{ }

		/**
		* @brief share pointer to parent
		  @return shared pointer to owner
		*/
		std::shared_ptr<Entity> getOwner() const
		{
			return owner;
		}
	protected:
	private:
	};
}