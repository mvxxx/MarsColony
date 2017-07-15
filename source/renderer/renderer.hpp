/*
mvxxx 2017
https://github.com/mvxxx
*/

#pragma once

#include <memory>
#include <vector>
#include <map>

#include "ecs/entity/Entity.hpp"
#include "ecs/component/ProperBody.hpp"

class Renderer
{
	/* ===Objects=== */
public:
protected:
private:
	using layerID_t = unsigned int;

	using layerPack_t = std::map < layerID_t, std::vector<std::shared_ptr<std::vector<std::shared_ptr<mv::Entity>>>>>;

	layerPack_t gameDrawLayers;

	/* ===Methods=== */
public:
	bool addCollection( std::shared_ptr<std::vector<std::shared_ptr<mv::Entity>>> collection, layerID_t numberOfLayer );
	void drawAll( sf::RenderWindow& window );
	bool addSingle( const std::shared_ptr<mv::Entity>& , layerID_t numberOfLayer );

protected:
private:
	bool hasProperBody( std::shared_ptr<std::vector<std::shared_ptr<mv::Entity>>> collection  );
	bool hasProperBody( std::shared_ptr<mv::Entity> entity );
};
