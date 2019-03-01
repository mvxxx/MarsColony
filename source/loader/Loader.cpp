#include "Loader.hpp"

WorldWrapper_t Loader::loadMap( const std::string& path )
{
	std::ifstream input( path );

	auto data = WorldWrapper_t();

	if ( !input.good() )
		return data;


	int temp;

	//loading dimensions;
	input >> temp;
	data.unitDimensions_x = temp;
	
	input >> temp;
	data.unitDimensions_y = temp;

	for(int i = 0;i < data.unitDimensions_x*data.unitDimensions_y;i++)
	{
	    input >> temp;
		data.map.emplace_back( temp );
	}

	input >> temp;
	data.firstPlayerPosition.x = temp;
	input >> temp;
	data.firstPlayerPosition.y = temp;
	input >> temp;
	data.secondPlayerPosition.x = temp;
	input >> temp;
	data.secondPlayerPosition.y = temp;

	int number{0};
	input>>number;

	for(int i = 0;i<number;i++)
	{
		sf::Vector2i pos;
		input>>temp;
		pos.x = temp;
		input>>temp;
		pos.y = temp;

        IconManager::bonus_t bonus;
        input>>temp;
        bonus = static_cast<IconManager::bonus_t>(temp);

		data.iconsData.emplace_back(bonus,pos);
	}

	return data;
}
