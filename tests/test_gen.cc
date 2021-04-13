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

TEST_F(TestGen, PermissionsListTest)
{
	TestObj_->get_current_session()->get_current_user()->set_user_name("josefelixrc7");
	TestObj_->NewPermission_(true, "Menus", "Permissions for menus", true, true, true, false);
	TestObj_->NewPermission_(true, "SubMenus", "Permissions for submenus", true, true, false, false);
	TestObj_->NewPermission_(true, "Accounts", "Permissions for accounts", false, true, false, false);
	TestObj_->NewPermission_(true, "Deals", "Permissions for deals", false, true, true, false);
	
	auto permissions = TestObj_->get_current_session()->get_permissions_colector();
	std::cout << "\nSize: " << permissions->size();
	for(auto it = permissions->begin(); it != permissions->end(); ++it)
	{
		std::cout << "\nname: " << (*it)->get_name() << ", passed: " << (*it)->get_passed() << 
			", description: " << (*it)->get_description() <<
			", DACList: "
				<< (*it)->get_actions_list()->get_create()
				<< (*it)->get_actions_list()->get_read()
				<< (*it)->get_actions_list()->get_update()
				<< (*it)->get_actions_list()->get_remove()
		;
	}
	std::cout << "\n";
}

//-----------------------------------------------------------------------------

int main(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}