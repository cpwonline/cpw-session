#include <iostream>
#include <string>

#include "gtest/gtest.h"

#include "cpw_session.h"

class TestGen : public ::testing::Test
{
	protected:
		void SetUp() override;
		void TearDown() override;

		CPWSession* TestObj_;
};

//-----------------------------------------------------------------------------

void TestGen::SetUp()
{
	TestObj_ = new CPWSession();
}

void TestGen::TearDown()
{
	delete TestObj_;
}

//-----------------------------------------------------------------------------

TEST_F(TestGen, TestLib2)
{
	ASSERT_EQ("Hello!", TestObj2_->get_var1());
}


//-----------------------------------------------------------------------------

int main(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}