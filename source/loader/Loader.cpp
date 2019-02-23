#include "Loader.hpp"

std::unique_ptr<WorldWrapper_t> Loader::loadMap( const std::string& path )
{
	std::ifstream input( path );

	auto data = std::make_unique<WorldWrapper_t>();

	if ( !input.good() )
		return std::move(data);


	int temp;

	//loading dimensions;
	input >> temp;
	data->unitDimensions_x = temp;
	
	input >> temp;
	data->unitDimensions_y = temp;

	while ( input >> temp )
	{
		data->map.emplace_back( temp );
	}

	input >> temp;
	data->firstPlayerPosition.x = temp;
	input >> temp;
	data->firstPlayerPosition.y = temp;
	input >> temp;
	data->secondPlayerPosition.x = temp;
	input >> temp;
	data->secondPlayerPosition.y = temp;

	int number{0};
	input>>number;

	for(int i = 0;i<number;i++)
	{
		input>>temp;
		sf::Vector2i pos;
		Icon::bonus_t bonus;
		pos.x = temp;
		input>>temp;
		pos.y = temp;
		input>>temp;
		bonus = static_cast<Icon::bonus_t>(temp);
		data->iconsData.emplace_back(pos,bonus);
	}

	return std::move(data);
}
