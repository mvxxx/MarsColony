/*
mvxxx 2017
https://github.com/mvxxx
*/

#pragma once
#include <map>
#include <vector>
#include <memory>
#include "../ecs/entity/Entity.hpp"

/**
* @brief draw map wrapper
*/
struct DrawMap
{
	using layerID_t = unsigned int;
	using layerPack_t = std::map< layerID_t, std::vector<std::shared_ptr<std::vector<std::shared_ptr<mv::Entity>>>>>;

	/**
	* @brief type of render
	*/
	enum class renderType_t
	{
		DEFAULT,
		UI
	};

	//layer database
	std::map<renderType_t, layerPack_t> layerPackData;

	/**
	* @brief classic ctor
	*/
	DrawMap()
	{
		layerPackData[renderType_t::DEFAULT] = layerPack_t();
		layerPackData[renderType_t::UI] = layerPack_t();
	}
};
