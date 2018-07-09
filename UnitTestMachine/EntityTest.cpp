#include "pch.h"

#include "../source/ecs/entity/Entity.hpp"

/**
* @Brief EntityTest -> Entity.hpp ->comparisonOperator test
*/
TEST(EntityTest, comparisonOperator)
{
	mv::Entity first;
	mv::Entity second;

	EXPECT_TRUE(first == second);

	first.addComponent<int>();
	EXPECT_FALSE(first == second);

	second.addComponent<int>();
	EXPECT_TRUE(first == second);

	first.addComponent<float>();
	first.addComponent<char>();
	second.addComponent<char>();
	second.addComponent<float>();
	EXPECT_TRUE(first == second);
}

/**
* @Brief EntityTest -> Entity.hpp ->moveCtor test
*/
TEST(EntityTest, moveCtor)
{
	mv::Entity first;

	first.addComponent<int>();
	*first.getComponent<int>() = 10;

	EXPECT_EQ(*first.getComponent<int>(), 10);

	mv::Entity second(std::move(first));

	EXPECT_EQ(*second.getComponent<int>(), 10);
	EXPECT_EQ(first.getComponent<int>(), nullptr);
}


/**
* @Brief EntityTest -> Entity.hpp ->copyCtor test
*/
TEST(EntityTest, copyCtor)
{
	mv::Entity first;

	first.addComponent<int>();
	*first.getComponent<int>() = 10;

	EXPECT_EQ(*first.getComponent<int>(), 10);

	mv::Entity second(first);

	EXPECT_EQ(*second.getComponent<int>(), 10);
	EXPECT_TRUE(first.getComponent<int>() != nullptr );
	EXPECT_EQ(*first.getComponent<int>(), 10);
}

/**
* @Brief EntityTest -> Entity.hpp ->moveAssignmentOperator test
*/
TEST(EntityTest, moveAssignmentOperator)
{
}

/**
* @Brief EntityTest -> Entity.hpp ->copy assignment operator test
*/
TEST(EntityTest, copyAssignmentOperator)
{
}

/**
* @Brief EntityTest -> Entity.hpp ->getComponent test
*/
TEST(EntityTest, getComponent)
{
}

/**
* @Brief EntityTest -> Entity.hpp ->addComponent test
*/
TEST(EntityTest, addComponent)
{
}

/**
* @Brief EntityTest -> Entity.hpp ->removeComponent test
*/
TEST(EntityTest, removeComponent)
{
}

/**
* @Brief EntityTest -> Entity.hpp ->hasComponent test
*/
TEST(EntityTest, hasComponent)
{
}
