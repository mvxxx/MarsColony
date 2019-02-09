/*
mvxxx 2017
https://github.com/mvxxx
*/

#pragma once

#include <vector>
#include <map>
#include <memory>
#include <type_traits>

#include "../../external/SFML/include/SFML/Graphics/Texture.hpp"
#include "../logger/Logger.hpp"


namespace mv
{
	/**
	* @brief basic container of data
	*/
	template <typename T,typename = typename std::enable_if<std::is_base_of<sf::Texture, T>::value>::type>
	class Cache
	{
		/* ===Objects=== */
	public:
	protected:
	private:

		//main struct for keep data
		std::map<std::string, std::shared_ptr<T>> resources;
		/* ===Methods=== */
	public:
		/**
		* @brief gets currently loaded data or loads it to memory 
		* @param path to data
		  @return shared pointer to data
		*/
		std::shared_ptr<T> get(const std::string& path)
        {
            if (path.empty())
            {
                Logger::Log("Cache can't find resource in empty path.", Logger::STREAM::BOTH, Logger::TYPE::WARNING);
            }

            {//Try find resource
                auto result = resources.find(path);
                if (result != resources.end())
                    return result->second;
            }

            {//Try to load it
                T resource;

                if (!resource.loadFromFile(path))
                {
                    Logger::Log("Cache can't find resource in this path.", Logger::STREAM::BOTH, Logger::TYPE::ERROR);
                }

                resources.emplace(path, std::make_shared<T>(resource));

                return resources[path];
            }
        }
	protected:
	private:
	};
}