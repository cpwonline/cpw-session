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


Permission::Permission()
{
	actions_list_ = new DACList();
}

Permission::Permission(const Permission* permission)
{
	actions_list_ = new DACList();
	name_ = permission->get_name();
	enabled_ = permission->get_enabled();
	description_ = permission->get_description();
	actions_list_->set_create(permission->get_actions_list()->get_create());
	actions_list_->set_read(permission->get_actions_list()->get_read());
	actions_list_->set_update(permission->get_actions_list()->get_update());
	actions_list_->set_delete(permission->get_actions_list()->get_delete());
}

Permission::~Permission()
{
	delete actions_list_;
}

std::string Permission::get_name() const
{
	return name_;
}

bool Permission::get_enabled() const
{
	return enabled_;
}

std::string Permission::get_description() const
{
	return description_;
}

DACList* Permission::get_actions_list() const
{
	return actions_list_;
}

void Permission::set_name(std::string name)
{
	name_ = name;
}

void Permission::set_enabled(bool enabled)
{
	enabled_ = enabled;
}

void Permission::set_description(std::string description)
{
	description_ = description;
}