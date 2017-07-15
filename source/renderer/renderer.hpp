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
	using layer_t = unsigned int;

	//using entityCollection_t = std::shared_ptr<std::vector<std::shared_ptr<mv::Entity>>>;

	std::map < layer_t, std::vector<std::shared_ptr<std::vector<std::shared_ptr<mv::Entity>>>>> drawLayers;

	/* ===Methods=== */
public:
	bool addCollection( std::shared_ptr<std::vector<std::shared_ptr<mv::Entity>>> collection, layer_t numberOfLayer );
	void drawAll( sf::RenderWindow& window );
	bool addSingle( const std::shared_ptr<mv::Entity>& , layer_t numberOfLayer );

protected:
private:
	bool hasProperBody( std::shared_ptr<std::vector<std::shared_ptr<mv::Entity>>> collection  );
	bool hasProperBody( std::shared_ptr<mv::Entity> entity );
};
