/*
mvxxx 2019
https://github.com/mvxxx
*/

#pragma once

#include "../external/SFML/include/SFML/Graphics/Color.hpp"
#include "../external/SFML/include/SFML/System/Vector2.hpp"

namespace mv
{
	namespace constants
	{

		namespace scene
		{
			constexpr auto ZOOM_SPEED = 0.05f;
		}

		namespace mob
		{
			constexpr auto DEFAULT_SPEED = 1.f;
		}

		namespace loop
		{
			const auto TIME_PER_FRAME = 1.f / 60.f;
		}

		namespace mouse
		{
			constexpr auto FREQUENCY = 0.2f;
		}
		namespace error
		{
		    namespace ecs
            {
		        constexpr auto BODY_DOES_NOT_CONTAIN_EL = "Body doesn't contain element with given label!";
            }

			namespace renderer
			{
				constexpr auto T_CAN_NOT_BE_DRAWN = "RENDERER: T can't be drawn. Check details of given class";
			}

			namespace scene
			{
				constexpr auto T_DOES_NOT_INHERT_FROM_DRAWABLE = "T doesn't inhert from sf::Drawable. It cannont be drawn by this method";
			}

			namespace mapManager
			{
				constexpr auto NEGATIVE_VALUES = "You need to enter a positive values. Dimensions of map/cell cannot be < 0!";
			}

			namespace fileManager
			{
				constexpr auto PATH_IS_NOT_CORRET = "Given path is not correct";
			}

			namespace singleton
			{
				constexpr auto SINGLETON_NOT_INITED = "Singleon must be inited!";
				constexpr auto SINGLETON_INITED = "Singleon has been inited before";
			}

			namespace soundObject
			{
				constexpr auto ALREADY_EXIST = "Sound with given name already exists";
				constexpr auto DOES_NOT_EXIST_IN_SYSTEM = "Sound with given doesn't exist in system";
			}

			namespace collisionManager
			{
		    	constexpr auto ENTITY_WITHOUT_COLLIDABLE = "Entity doesn't contain Collidable component";
		    	constexpr auto ENTITY_WITHOUT_UNITPOSITION = "Entity doesn't contain UnitPosition component";
		    	constexpr auto ENTITY_IN_DATA = "This entity currently is in considered field";
			}

			namespace componentWrapper
			{
				constexpr auto CANNOT_BE_NULLPTR = "Pointer to component can't be nullptr!";
			}
		}

		namespace defaults
		{
			constexpr auto EMPTY = "EMPTY";
			constexpr auto EMPTY_STATE_NUMBER = 0;
			constexpr auto UNNAMED = "unnamed";
			const sf::Vector2f WINDOW_DIMENSIONS = {1280, 720};
			const sf::Vector2u BORDER_TOLERANCE = {100, 100};
			const sf::Vector2f MOUSE_DIMENSIONS = {20, 20};
			const sf::Vector2f CELL_DIMENSION = {64,64};
			const sf::Vector2f WEAPON_DIMENSIONS = {70,70};
            const sf::Vector2f ICON_DIMENSIONS = {70,70};
		}

		namespace path
		{
			constexpr auto CELL_TEXTURE_ATLAS = "data/textures/cellTexture.png" ;
			constexpr auto MAP = "data/defaultMaps/map0.txt";
			constexpr auto PLAYER_TEXTURE_TOP = "data/textures/player_top.png";
			constexpr auto PLAYER_TEXTURE_BOTTOM = "data/textures/player_bottom.png";
			constexpr auto MOUSE_TEXTURE_ATLAS = "data/textures/mouseAtlas.png";
			constexpr auto WEAPON_TEXTURE_ATLAS = "data/textures/weaponAtlas.png";
			constexpr auto ICON_TEXTURE_ATLAS = "data/textures/iconAtlas.png";
		}

		namespace event_flags
		{
			constexpr auto LEFT_MOUSE_BUTTON = "-lmb";
			constexpr auto RIGHT_MOUSE_BUTTON = "-lmb";
			constexpr auto DECREASE_MODE = "-d";
			constexpr auto ZOOM_MODE = "-z";
		}

		namespace id
		{
			constexpr auto sand_red = 0;
			constexpr auto sand_yellow = 1;
			constexpr auto stone = 2;
		}

		namespace weapon
		{
            constexpr auto shift = 0.15f; //shift of weapon towards entity's border in percent
		}
	}
}
