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

	return std::move(data);
}
