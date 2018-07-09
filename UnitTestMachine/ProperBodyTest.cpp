#include "pch.h"

#include "../source/ecs/component/ProperBody.hpp"
#include "../source/logger/Logger.hpp"

#include "SFML/Graphics/Texture.hpp"
#include "SFML/Graphics/CircleShape.hpp"
#include "SFML/Graphics/RectangleShape.hpp"

/**
* @brief ProperBodyTest -> ProperBody.hpp -> visible test
*/
TEST(ProperBodyTest, visible)
{
	ProperBody pb;
	EXPECT_TRUE(pb.isVisible());
	pb.setVisible(false);
	EXPECT_FALSE(pb.isVisible());
	pb.setVisible(true);
	EXPECT_TRUE(pb.isVisible());
}

/**
* @brief ProperBodyTest -> ProperBody.hpp -> collidable test
*/
TEST(ProperBodyTest, collidable)
{
	ProperBody pb;
	EXPECT_FALSE(pb.collidable);
	pb.collidable = !pb.collidable;
	EXPECT_TRUE(pb.collidable);
}

/**
* @brief ProperBodyTest -> ProperBody.hpp -> control type test
*/
TEST(ProperBodyTest, controlType)
{
	ProperBody* pb = new ProperBody;
	pb->appendType<sf::Sprite>();
	EXPECT_EQ(typeid(pb->getAs<sf::Sprite>()).hash_code(), typeid(sf::Sprite).hash_code());
	delete pb;

	//ERROR -> sf::Texture does not inherit for sf::Drawable
	/*ProperBody* pb2 = new ProperBody;
	pb2->appendType<sf::Texture>();
	EXPECT_TRUE(typeid(pb2->getAs<sf::Sprite>()).hash_code() == typeid(sf::Sprite).hash_code());
	delete pb2;*/

	ProperBody* pb3 = new ProperBody;
	pb3->appendType<sf::CircleShape>();
	EXPECT_TRUE(typeid(pb3->getAs<sf::CircleShape>()).hash_code() == typeid(sf::CircleShape).hash_code());
	delete pb3;
}


/**
* @brief ProperBodyTest -> ProperBody.hpp -> setCenter test
*/
TEST(ProperBodyTest, setCenter)
{
	ProperBody pb;
	pb.appendType<sf::Sprite>();
	pb.getAs<sf::Sprite>().setTextureRect(sf::IntRect(0,0,150,100));

	EXPECT_EQ(pb.getAs<sf::Sprite>().getGlobalBounds().width,150);
	EXPECT_EQ(pb.getAs<sf::Sprite>().getGlobalBounds().height, 100);

	pb.setCenter();
	EXPECT_EQ(pb.getAs<sf::Sprite>().getOrigin().x, 75);
	EXPECT_EQ(pb.getAs<sf::Sprite>().getOrigin().y, 50);
}