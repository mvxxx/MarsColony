/*
mvxxx 2017
https://github.com/mvxxx
*/

#pragma once

#include <memory>
#include <functional>

/**
* @brief function pointer wrapper
*/
template <class T>
struct FunctionPointerWrapper_t
{
public:
	//pointer to object
	std::shared_ptr<T> object;

	//function from STD
	std::function<void( T& )> function;

	/**
	* @brief classic ctor
	* param func - function pointer
	* param  obj - pointer to object
	*/
	FunctionPointerWrapper_t( const std::function<void( T& )>& func,const std::shared_ptr<T> obj )
		:object(obj), function(func)
	{}
};
