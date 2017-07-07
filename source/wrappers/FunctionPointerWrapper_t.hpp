/*
mvxxx 2017
https://github.com/mvxxx
*/

#pragma once

#include <memory>
#include <functional>

template <class T>
struct FunctionPointerWrapper_t
{
public:
	std::shared_ptr<T>& object;
	std::function<void( T& )> function;

	FunctionPointerWrapper_t( std::function<void( T& )> func, std::shared_ptr<T>& obj )
		:object(obj), function(func)
	{}
};
