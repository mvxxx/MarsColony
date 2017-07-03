/*
mvxxx 2017
https://github.com/mvxxx
*/

#pragma once

#include <memory>
#include <vector>

template<class T>
class Manager
{
	/* ===Objects=== */
public:
protected:
	std::vector<std::shared_ptr<T>> entities;
private:
	/* ===Methods=== */
public:
	virtual void manage() = 0;

	virtual void addEntityToManage( std::shared_ptr<T> entity ) = 0;
protected:
private:
};
