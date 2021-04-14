/*
 * cpw_session.cc
 * 
 * Copyright 2021 CPW Online <support@cpwonline.org>
 * 
 * This program is free software; see the License file for more details.
 * 
 * You should have received a copy of the License along with this program.
 * 
 */


#include "cpw_session.h"


CPWSession::CPWSession()
{
	current_session_ = new Session();
	current_access_control_ = new AccessControl(current_session_->get_permissions_colector(), current_session_->get_levels_colector());
}

CPWSession::CPWSession(std::string user_name, bool active, int session_duration)
{
	current_session_ = new Session(active, session_duration);
	current_access_control_ = new AccessControl(current_session_->get_permissions_colector(), current_session_->get_levels_colector());
	current_session_->get_current_user()->set_user_name(user_name);
}

CPWSession::~CPWSession()
{
	delete current_session_;
	delete current_access_control_;
}

Session* CPWSession::get_current_session() const
{
	return current_session_;
}

AccessControl* CPWSession::get_current_access_control() const
{
	return current_access_control_;
}

void CPWSession::NewPermission_(bool enabled, std::string name, std::string description, bool create, bool read, bool update, bool remove)
{
	Permission* temporal_permission = new Permission();
	temporal_permission->set_name(name);
	temporal_permission->set_enabled(enabled);
	temporal_permission->set_description(description);
	temporal_permission->get_actions_list()->set_create(create);
	temporal_permission->get_actions_list()->set_read(read);
	temporal_permission->get_actions_list()->set_update(update);
	temporal_permission->get_actions_list()->set_delete(remove);
	
	current_session_->get_permissions_colector()->emplace(new Permission(temporal_permission));
	delete temporal_permission;
}

void CPWSession::NewLevel_(int identifier, std::string name)
{
	Level* temporal_level = new Level();
	temporal_level->set_identifier(identifier);
	temporal_level->set_name(name);
	
	current_session_->get_levels_colector()->emplace(new Level(temporal_level));
	delete temporal_level;
}

bool CPWSession::Verify_(CPWSession::DACType action_type, std::string permission_name)
{
	auto permission_to_verify = new Permission();
	permission_to_verify->set_name(permission_name);
	
	switch(action_type)
	{
		case DACType::kCreate:
		{
			permission_to_verify->get_actions_list()->set_create(true);
			break;
		}
		case DACType::kRead:
		{
			permission_to_verify->get_actions_list()->set_read(true);
			break;
		}
		case DACType::kUpdate:
		{
			permission_to_verify->get_actions_list()->set_update(true);
			break;
		}
		case DACType::kDelete:
		{
			permission_to_verify->get_actions_list()->set_delete(true);
			break;
		}
		default:
		{
			return false;
		}
	}
	bool result = current_access_control_->VerifyAccess_(permission_to_verify);
	delete permission_to_verify;
	
	return result;
}

bool CPWSession::Verify_(int level_identifier)
{
	auto level_to_verify = new Level();
	level_to_verify->set_identifier(level_identifier);
	
	return current_access_control_->VerifyAccess_(level_to_verify);
}