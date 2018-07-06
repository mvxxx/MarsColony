#include <functional>
#include <typeinfo>

#include "pch.h"
#include "wrappers/point.hpp"
#include "wrappers/WorldWrapper.hpp"
#include "wrappers/FunctionPointerWrapper_t.hpp"
#include "wrappers/EventWrapper.hpp"
#include "wrappers/DrawMap.hpp"
#include "wrappers/componentWrapper.hpp"

/**
* @brief WrappersTest -> point.hpp test
*/
TEST(WrapperTest, Point) 
{
	{
		Point_t<int> point(0,0);
		EXPECT_EQ(point.x, 0);
		EXPECT_EQ(point.y, 0);
	}
	{
		Point_t<int> point(10, 15);
		EXPECT_EQ(point.x, 10);
		EXPECT_EQ(point.y, 15);

		point.x = 7;
		point.y = 8;

		EXPECT_EQ(point.x, 7);
		EXPECT_EQ(point.y, 8);
	}
}

/**
* @brief WrapperTest -> WorldWrapper.hpp test
*/
TEST(WrapperTest, WorldWrapper)
{
	WorldWrapper_t worldWrapper;
	worldWrapper.unitDimensions_x = 4;
	worldWrapper.unitDimensions_y = 3;
	EXPECT_EQ(worldWrapper.unitDimensions_x, 4);
	EXPECT_EQ(worldWrapper.unitDimensions_y, 3);
	worldWrapper.map = { 1,2,3,4,5,6,7,8,9,10,11,12 };
	std::vector<int> anotherMap = { 1,2,3,4,5,6,7,8,9,10,11,12 };
	EXPECT_EQ(worldWrapper.map,anotherMap);
}

class PointerTest
{
public:
	void testMethod()
	{
		changed = true;
	}

	bool changed = false;
};

/**
* @brief WrapperTest -> FunctionPointerWrapper_t.hpp test
*/
TEST(WrapperTest, FunctionPointer)
{
	auto pTest = std::make_shared<PointerTest>();
	EXPECT_FALSE(pTest->changed);
	FunctionPointerWrapper_t<PointerTest> fpWrapper(std::function<void(PointerTest&)>(&PointerTest::testMethod) ,pTest);
	fpWrapper.function(*fpWrapper.object);
	EXPECT_TRUE(pTest->changed);
}

/**
* @brief WrapperTest -> EventWrapper.hpp test
*/
TEST(WrapperTest, EventWrapper)
{
	eventWrapper_t ev;
	EXPECT_TRUE(ev.list.empty());
	int i = 3;
	while (i--)
	{
		ev.list.emplace_back();
	}
	
	EXPECT_TRUE(ev.list.size() == 3);
}

/**
* @brief WrapperTest -> DrawMap.hpp test
*/
TEST(WrapperTest, DrawMap)
{
	DrawMap dm;
	EXPECT_EQ(dm.layerPackData[DrawMap::renderType_t::DEFAULT], DrawMap::layerPack_t());
	EXPECT_EQ(dm.layerPackData[DrawMap::renderType_t::UI], DrawMap::layerPack_t());
}

/**
* @brief WrapperTest -> componentWrapper.hpp test
*/
TEST(WrapperTest, ComponentWrapper)
{
	componentWrapper_t c1(std::make_shared<PointerTest>(), 10);
	componentWrapper_t c2(std::make_shared<PointerTest>(), 15);

	EXPECT_EQ(c1.id, 10);
	EXPECT_EQ(c2.id, 15);
	EXPECT_FALSE(c1==c2);

	c2.id = 10;

	EXPECT_TRUE(c1 == c2);
}