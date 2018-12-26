/*
mvxxx 2017
https://github.com/mvxxx
*/

#pragma once
#include "../../external/SFML/include/SFML/Graphics/VertexArray.hpp"
#include "../ecs/component/Visible.hpp"
#include "../ecs/entity/Entity.hpp"
#include "../scene/Scene.hpp"
#include "../Utilities.hpp"

/**
* @brief Represents frame on the scene
*/
class Frame : public mv::Entity, public sf::Drawable
{
	/* ===Objects=== */
public:

	/**
	* @brief Allows distinguishing two types
	*/
  enum class PointType
  {
    START,
    CURRENT
  };

protected:
private:
  //Represents start point
  sf::Vector2f start;

  //Represents current point
  sf::Vector2f current;

	/* ===Methods=== */
public:
	/**
	* @brief Classic ctor
	* @param scene - pointer to scene
	*/
  Frame( const std::shared_ptr<Scene>& scene );

  /**
  * @brief activates selection
  * @param coords - start position
  */
  void activateSelection(const sf::Vector2f& coords);

  /**
  * @brief deactivates selection
  */
  void deactivateSelection();

  /**
  * @brief uptades selection
  * @param coords - current position
  */
  void updateSelection(const sf::Vector2f& coords);

  /**
  * @brief  returns frame
  * @param coords - start position
  */
  const sf::VertexArray& getFrame();

  /**
  * @brief sets point
  * @param coords - position
  * @param status - type of point 
  * @see PointType enum class
  */
  void setPoint(const sf::Vector2f& coords, const PointType& status);
protected:
private:

	/**
	* @brief inits frame, creates frame structure
	* @param scene - pointer to main scene
	*/
  void initFrame(const std::shared_ptr<Scene>& scene);

  /**
  * @brief configures frame
  * uptades frame's structure with current existing CURRENT and START point
  * @param coords - start position
  */
  void configureFrame();

  /**
  * @brief draw 
  * @param target from SFML
  * @param states from SFML
  */
  virtual void draw( sf::RenderTarget& target, sf::RenderStates states ) const;
};


