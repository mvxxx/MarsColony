#include "Border.hpp"

Border::Border(std::shared_ptr<Scene> scene)
{
	constexpr int8_t ammountOfCorners = 7;

	selection.setPrimitiveType( sf::Lines );
	for ( size_t i = 0; i <= ammountOfCorners; i++ )
	{
		selection.append( sf::Vertex( Math::mouseWorldPosition(scene)) );
		selection[i].color = sf::Color::Yellow;
	}
}




