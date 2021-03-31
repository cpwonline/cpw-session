/*
 * user.cc
 * 
 * Copyright 2021 CPW Online <support@cpwonline.org>
 * 
 * This program is free software; see the License file for more details.
 * 
 * You should have received a copy of the License along with this program.
 * 
 */


#include "user.h"


User::User()
{
	
}


User::~User()
{
	
}

std::string User::get_user_name() const
{
	return user_name_;
}

void User::set_user_name(std::string user_name)
{
	user_name_ = user_name;
}