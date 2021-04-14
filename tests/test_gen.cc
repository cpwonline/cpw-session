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
		std::cout << "\nname: " << (*it)->get_name() << ", enabled: " << (*it)->get_enabled() << 
			", description: " << (*it)->get_description() <<
			", DACList: "
				<< (*it)->get_actions_list()->get_create()
				<< (*it)->get_actions_list()->get_read()
				<< (*it)->get_actions_list()->get_update()
				<< (*it)->get_actions_list()->get_delete()
		;
	}
	std::cout << "\n";
}

TEST_F(TestGen, LevelsListTest)
{
	TestObj_->get_current_session()->get_current_user()->set_user_name("josefelixrc7");
	std::cout << "\n Session username: " << 
		TestObj_->get_current_session()->get_current_user()->get_user_name() << "\n"
	;
	TestObj_->NewLevel_(2, "Developer");
	TestObj_->NewLevel_(5, "Manager");
	TestObj_->NewLevel_(5, "Technical");
	
	auto levels = TestObj_->get_current_session()->get_levels_colector();
	for(auto it = levels->begin(); it != levels->end(); ++it)
	{
		std::cout << "\nId: " << (*it)->get_identifier() << ", name: " << (*it)->get_name();
	}
	std::cout << "\n";
}

TEST_F(TestGen, VerifyPermissionsTest)
{
	TestObj_->get_current_session()->get_current_user()->set_user_name("josefelixrc7");
	TestObj_->NewPermission_(true, "Menus", "Permissions for menus", true, true, true, false);
	TestObj_->NewPermission_(false, "SubMenus", "Permissions for submenus", true, true, false, false);
	TestObj_->NewPermission_(true, "Accounts", "Permissions for accounts", false, true, false, false);
	TestObj_->NewPermission_(true, "Deals", "Permissions for deals", false, true, true, false);
	
	ASSERT_EQ(true, TestObj_->Verify_(CPWSession::DACType::kCreate, "Menus"));
	ASSERT_EQ(false, TestObj_->Verify_(CPWSession::DACType::kRead, "SubMenus"));
	ASSERT_EQ(false, TestObj_->Verify_(CPWSession::DACType::kUpdate, "Pages"));
	ASSERT_EQ(true, TestObj_->Verify_(CPWSession::DACType::kRead, "Deals"));
	ASSERT_EQ(false, TestObj_->Verify_(CPWSession::DACType::kDelete, "Accounts"));
}

TEST_F(TestGen, VerifyLevelsTest)
{
	TestObj_->get_current_session()->get_current_user()->set_user_name("josefelixrc7");
	TestObj_->NewLevel_(2, "Developer");
	TestObj_->NewLevel_(5, "Manager");
	TestObj_->NewLevel_(6, "Technical");
	
	ASSERT_EQ(true, TestObj_->Verify_(2));
	ASSERT_EQ(true, TestObj_->Verify_(5));
	ASSERT_EQ(true, TestObj_->Verify_(6));
	ASSERT_EQ(false, TestObj_->Verify_(7));
	ASSERT_EQ(false, TestObj_->Verify_(7));
}

//-----------------------------------------------------------------------------

int main(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}