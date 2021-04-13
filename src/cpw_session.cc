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

CPWSession::CPWSession(std::string user_name)
{
	CPWSession();
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

void CPWSession::NewPermission_(bool passed, std::string name, std::string description, bool create, bool read, bool update, bool remove)
{
	Permission* temporal_permission = new Permission();
	temporal_permission->set_name(name);
	temporal_permission->set_passed(passed);
	temporal_permission->set_description(description);
	temporal_permission->get_actions_list()->set_create(create);
	temporal_permission->get_actions_list()->set_read(read);
	temporal_permission->get_actions_list()->set_update(update);
	temporal_permission->get_actions_list()->set_remove(remove);
	
	current_session_->get_permissions_colector()->emplace(new Permission(temporal_permission));
	delete temporal_permission;
}
}