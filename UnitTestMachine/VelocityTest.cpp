#include "pch.h"

#include "../source/ecs/component/Velocity.hpp"

/**
* @brief VelocityTest -> VelocityTest.hpp -> basicFunctionality test
*/
TEST(VelocityTest, basicFunctionality)
{
	Velocity v;
	EXPECT_EQ(v.x, 0);
	EXPECT_EQ(v.y, 0);
	EXPECT_EQ(v.getValue(), 0);

	v.x = 50.f;
	v.y = 75.f;
	EXPECT_EQ(v.x, 50.f);
	EXPECT_EQ(v.y, 75.f);
	EXPECT_EQ(std::round(v.getValue()), 90);

	v.x = 0;
	v.y = 0;
	EXPECT_EQ(v.x, 0);
	EXPECT_EQ(v.y, 0);
	EXPECT_EQ(v.getValue(), 0);
}

/**
* @brief VelocityTest -> VelocityTest.hpp -> operatorTest test
*/
TEST(VelocityTest, operatorTest)
{
	Velocity v;
	EXPECT_EQ(v.x, 0);
	EXPECT_EQ(v.y, 0);

	Velocity v1(20, 30);
	
	v = v + v1;
	EXPECT_EQ(v.x, 20);
	EXPECT_EQ(v.y, 30);
	
	v = v - v1;
	EXPECT_EQ(v.x, 0);
	EXPECT_EQ(v.y, 0);

	v = v * v1;
	EXPECT_EQ(v.x, 0);
	EXPECT_EQ(v.y, 0);

	v.x = 2;
	v.y = 3;
	v = v * v1;
	EXPECT_EQ(v.x, 40);
	EXPECT_EQ(v.y, 90);

	v = v / v1;
	EXPECT_EQ(v.x, 2);
	EXPECT_EQ(v.y, 3);
}