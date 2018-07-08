/*
mvxxx 2017
https://github.com/mvxxx
*/

#pragma once

#include <memory>

#include "logger/Logger.hpp"

/**
* @brief wrapper which contains ID and component
* It is used for ECS
*/
struct componentWrapper_t
{
	//pointer to component
	std::shared_ptr<void> component;

	//id
	uint64_t id;

	/**
	* @brief classic ctor
	* @param c - component
	* @param _id - id
	*/
	componentWrapper_t( std::shared_ptr<void> c, uint64_t _id)
		:component( c ), id( _id )
	{
		if (component == nullptr)
		{
			mv::Logger::Log(mv::constants::error::componentWrapper::CANNOT_BE_NULLPTR);
		}
	}

	/**
	* @brief comparison operator
	* Objects are identical if they have the same:
	* - id
	* @param other - object to compare
	* @return true if object are the same, false otherwise
	*/
	bool operator==(const componentWrapper_t& other)
	{
		return id == other.id;
	}
};