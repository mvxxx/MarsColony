/*
mvxxx 2017
https://github.com/mvxxx
*/

#pragma once

#include <memory>

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
	componentWrapper_t( std::shared_ptr<void> c, uint64_t _id )
		:component( c ), id( _id )
	{
	}
};