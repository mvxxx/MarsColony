/*
mvxxx 2019
https://github.com/mvxxx
*/

#pragma once

#include <map>
#include <functional>

#include "../../external/SFML/include/SFML/Window/Keyboard.hpp"

#include "../scene/Scene.hpp"
#include "../wrappers/FunctionPointerWrapper_t.hpp"

namespace mv
{
	/**
	* @brief Class which manage keys' input
	*/
	template <class T>
	class InputManager
	{
		/* ===Objects=== */
	public:
	protected:
	private:
		//when you press KEY you execute FunctionWrapper
		std::map < sf::Keyboard::Key, FunctionPointerWrapper_t<T>> keyData;
		/* ===Methods=== */
	public:
		/**
		* @brief Checks if keys have been clicked
		*/
		void update();

		/**
		* @bried adds key to database
		*/
		bool addKeyToCheck( sf::Keyboard::Key key, std::function<void( T& )> function, std::shared_ptr<T> object );

		/**
		* @brief remove key from database
		*/
		bool eraseKey( sf::Keyboard::Key key );
	protected:
	private:
	};

	template <class T>
	void InputManager<T>::update()
	{
		for ( auto&var : keyData )
			if ( sf::Keyboard::isKeyPressed( var.first ) )
				var.second.function( *var.second.object );
	}

	template <class T>
	bool InputManager<T>::addKeyToCheck( sf::Keyboard::Key key, std::function<void( T& )> function, std::shared_ptr<T> object )
	{
		keyData.emplace( key, FunctionPointerWrapper_t<T>( function, object ) );

		return true;
	}

	template <class T>
	bool InputManager<T>::eraseKey( sf::Keyboard::Key key )
	{
		keyData.erase( key );
		return false;
	}
}