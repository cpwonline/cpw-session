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

int Permission::get_identifier() const
{
	return identifier_;
}

std::string Permission::get_name() const
{
	return name_;
}

std::string Permission::get_desription() const
{
	return desription_;
}

bool Permission::get_passed() const
{
	return passed_;
}

void Permission::set_identifier(int identifier)
{
	identifier_ = identifier;
}

void Permission::set_name(std::string name)
{
	name_ = name;
}

void Permission::set_desription(std::string desription)
{
	desription_ = desription;
}

void Permission::set_passed(bool passed)
{
	passed_ = passed;
}