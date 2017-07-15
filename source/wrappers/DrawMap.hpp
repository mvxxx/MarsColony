/*
mvxxx 2017
https://github.com/mvxxx
*/

#pragma once
#include <map>
#include <vector>
#include <memory>
#include "ecs/entity/Entity.hpp"

struct DrawMap
{
	using layerID_t = unsigned int;
	using layerPack_t = std::map< layerID_t, std::vector<std::shared_ptr<std::vector<std::shared_ptr<mv::Entity>>>>>;

	enum class renderType_t
	{
		DEFAULT,
		UI
	};

	std::map<renderType_t, layerPack_t> layerPackData;

	DrawMap()
	{
		layerPackData[renderType_t::DEFAULT] = layerPack_t();
		layerPackData[renderType_t::UI] = layerPack_t();
	}
};
