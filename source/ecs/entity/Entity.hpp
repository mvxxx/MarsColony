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
	class Entity
	{
		/* ===Objects=== */
	public:
	protected:
	private:
		std::vector<componentWrapper_t> componentWrappers;
		/* ===Methods=== */
	public:
		template<class T>
		std::shared_ptr<T> getComponent() const;

		template<class T>
		bool addComponent();

		template<class T>
		bool hasComponent();

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