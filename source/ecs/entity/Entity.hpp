/*
mvxxx 2017
https://github.com/mvxxx
*/

#pragma once

#include <vector>
#include <memory>

#include "wrappers/componentWrapper.hpp"

namespace mv
{
	/**
	* @brief Entity class
	*/
	class Entity
	{
		/* ===Objects=== */
	public:
	protected:
	private:
		//wrappers of components
		std::vector<componentWrapper_t> componentWrappers;
		/* ===Methods=== */
	public:
		/**
		* @brief gets component
		* @return component with given type
		*/
		template<class T>
		std::shared_ptr<T> getComponent() const;

		/**
		* @brief adds component
		* @return true if component with given type has been addded
		* false otherwise
		*/
		template<class T>
		bool addComponent();

		/**
		* @brief check if object has component
		* @return true if component with given type exists
		* false otherwise
		*/
		template<class T>
		bool hasComponent();

		/**
		* @brief remove component
		* @return true if component with given type has been removed
		* false otherwise
		*/
		template<class T>
		bool removeComponent();
	protected:
	private:
	};

	template<class T>
	inline std::shared_ptr<T> Entity::getComponent() const
	{
		for ( auto&cw : componentWrappers )
			if ( cw.id == typeid(T).hash_code() )
				return std::static_pointer_cast<T>(cw.component);

		return nullptr;
	}

	template<class T>
	inline bool Entity::addComponent()
	{
		for ( auto&cw : componentWrappers )
			if ( cw.id == typeid(T).hash_code() )
				return false;

		componentWrappers.push_back( componentWrapper_t( std::make_shared<T>(), typeid(T).hash_code() ) );

		return true;
	}

	template<class T>
	inline bool Entity::hasComponent()
	{

		for ( auto&cw : componentWrappers )
		{
			if ( cw.id == typeid(T).hash_code() )
			{
				return true;
			}
		}
		return false;
	}

	template<class T>
	inline bool Entity::removeComponent()
	{
		for ( auto itr = componentWrappers.begin(); itr != componentWrappers.end(); ++itr )
		{
			if ( itr->id == typeid(T).hash_code() )
			{
				componentWrappers.erase( itr );
				return true;
			}		
		}
		return false;
	}
}