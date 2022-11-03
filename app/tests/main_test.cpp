#include "gtest/gtest.h"
#include "gmock/gmock.h"

/*
 *	main
 */

int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

TEST(app_test, dummy_test)
{
	ASSERT_NO_THROW();
}