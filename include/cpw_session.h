/*
 * cpw_session.h
 * 
 * Copyright 2021 CPW Online <support@cpwonline.org>
 * 
 * This program is free software; see the License file for more details.
 * 
 * You should have received a copy of the License along with this program.
 * 
 */


#include <string>
#include <set>

#include "session.h"
#include "access_control.h"
#include "permission.h"
#include "level.h"

#ifndef CPW_SESSION_H
#define CPW_SESSION_H

class CPWSession
{
	public:
		CPWSession();
		CPWSession(std::string user_name);
		virtual ~CPWSession();
		
	public:
		Session* get_current_session() const;
		AccessControl* get_current_access_control() const;
	
	private:
		Session* current_session_;
		AccessControl* current_access_control_;
};

#endif /* CPW_SESSION_H */ 
