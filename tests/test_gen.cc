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

TEST_F(TestGen, UserNameTest)
{
	std::string user_name = "josefelixrc7";
	TestObj_->get_current_session()->get_current_user()->set_user_name(user_name);
	ASSERT_EQ(user_name, TestObj_->get_current_session()->get_current_user()->get_user_name());
	std::cout << "\n Session username: " << 
		TestObj_->get_current_session()->get_current_user()->get_user_name()
		<< "\n"
	;
}


//-----------------------------------------------------------------------------

int main(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}