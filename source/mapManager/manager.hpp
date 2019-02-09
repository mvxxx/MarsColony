/*
mvxxx 2019
https://github.com/mvxxx
*/

#pragma once

#include <memory>
#include <vector>

/**
* @brief Object for managing T entities
*/
template<class T>
class Manager
{
	/* ===Objects=== */
public:
protected:
	//entities which are being managed
	std::vector<std::shared_ptr<T>> entities;
private:
	/* ===Methods=== */
public:
	/**
	* @brief virtual method for managing entities
	*/
	virtual void manage() = 0;

	/**
	* @brief adds entity to manage
	* @param entity to add
	*/
	virtual void addEntityToManage( std::shared_ptr<T> entity ) = 0;
protected:
private:
};
