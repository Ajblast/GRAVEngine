#include <gtest/gtest.h>
#include "GRAVRuntime/Application.h"

// TODO: Application Tests
// Can create application
// Can Create Window
// Can Push Layer
// Can Push Overlay
// Can Close Application

TEST(GRAVRuntime, PassingTest)
{
	SUCCEED() << "Intentionally passed test";
}
TEST(GRAVRuntime, FailingTest)
{
	FAIL() << "Intentionally failed test";
}
