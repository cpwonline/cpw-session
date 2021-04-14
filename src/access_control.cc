/*
 * access_control.cc
 * 
 * Copyright 2021 CPW Online <support@cpwonline.org>
 * 
 * This program is free software; see the License file for more details.
 * 
 * You should have received a copy of the License along with this program.
 * 
 */


#include "access_control.h"


AccessControl::AccessControl(std::set<Permission*>* permissions_colector, std::set<Level*>* levels_colector)
{
	permissions_colector_ = permissions_colector;
	levels_colector_ = levels_colector;
}

AccessControl::~AccessControl()
{
	
}

std::set<Permission*>* AccessControl::get_permissions_colector() const
{
	return permissions_colector_;
}

std::set<Level*>* AccessControl::get_levels_colector() const
{
	return levels_colector_;
}

bool AccessControl::VerifyAccess_(Permission* permission_to_verify)
{
	auto find_permission = [permission_to_verify](const Permission* permission)
	{ 
		return permission_to_verify->get_name() == permission->get_name(); 
	};
	
	auto result = std::find_if(permissions_colector_->begin(), permissions_colector_->end(), find_permission);
	
	if(result != permissions_colector_->end())
	{
		if(!(*result)->get_enabled()) return false;
		
		return SeeTrueAttribute_(permission_to_verify, *result);
	}
	else
		return false;
}

bool AccessControl::VerifyAccess_(Level* level_to_verify)
{
	auto find_level = [level_to_verify](const Level* level)
	{ 
		return level_to_verify->get_identifier() == level->get_identifier(); 
	};
	auto result = std::find_if(levels_colector_->begin(), levels_colector_->end(), find_level);
	
	if(result != levels_colector_->end()) 
		return true;
	else
		return false;
}

bool AccessControl::SeeTrueAttribute_(Permission* permission_to_verify, Permission* permission_found)
{
	if(permission_to_verify->get_actions_list()->get_create())
		return permission_found->get_actions_list()->get_create() == true;
	else if(permission_to_verify->get_actions_list()->get_read())
		return permission_found->get_actions_list()->get_read() == true;
	else if(permission_to_verify->get_actions_list()->get_update())
		return permission_found->get_actions_list()->get_update() == true;
	else if(permission_to_verify->get_actions_list()->get_delete())
		return permission_found->get_actions_list()->get_delete() == true;
	else
		return false;
}