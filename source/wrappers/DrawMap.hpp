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

	layerPack_t gameDrawLayers;
	layerPack_t UIDrawLayers;
};
