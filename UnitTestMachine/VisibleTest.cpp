#include "pch.h"

#include "../source/ecs/component/Visible.hpp"

/**
* @brief VisibleTest -> Visible.hpp -> basicFunctionality test
*/
TEST(VisibleTest, basicFunctionality)
{
	Visible v;
	EXPECT_FALSE(v.isVisible());
	v.setVisible(true);
	EXPECT_TRUE(v.isVisible());
}