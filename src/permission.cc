/*
 * permission.cc
 * 
 * Copyright 2021 CPW Online <support@cpwonline.org>
 * 
 * This program is free software; see the License file for more details.
 * 
 * You should have received a copy of the License along with this program.
 * 
 */


#include "permission.h"


Permission::Permission(std::string name) :
	name_ = name
{
	
}

Permission::~Permission()
{
	
}

std::string Permission::get_name() const
{
	return name_;
}

bool Permission::get_passed() const
{
	return passed_;
}

std::string Permission::get_desription() const
{
	return desription_;
}

DAC Permission::get_actions_list() const
{
	return actions_list_;
}

void Permission::set_name(std::string name)
{
	name_ = name;
}

void Permission::set_passed(bool passed)
{
	passed_ = passed;
}

void Permission::set_desription(std::string desription)
{
	desription_ = desription;
}