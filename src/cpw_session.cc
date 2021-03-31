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
	current_access_control_ = new AccessControl();
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