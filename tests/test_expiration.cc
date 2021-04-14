#include <iostream>
#include <string>

#include "gtest/gtest.h"

#include "cpw_session.h"

class TestExpiration : public ::testing::Test
{
	protected:
		void SetUp() override;
		void TearDown() override;

		CPWSession* TestObj_;
};

//-----------------------------------------------------------------------------

void TestExpiration::SetUp()
{
	TestObj_ = new CPWSession("josefelixrc7", true, 50);
}

void TestExpiration::TearDown()
{
	delete TestObj_;
}

//-----------------------------------------------------------------------------

TEST_F(TestExpiration, ExpiredTest)
{
	auto exp = TestObj_->get_current_session()->get_current_expiration();
	while(!TestObj_->Expired_())
	{
		std::cout << "\n"
			<< "Session duration: " << exp->get_session_duration().count()
			<< ", elapsed seconds: " << exp->get_elapsed_seconds().count()
			<< ", time remaining: " << exp->get_time_remaining().count()
		;
		getchar();
	}
}

//-----------------------------------------------------------------------------

int main(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}