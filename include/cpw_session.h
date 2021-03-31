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


#include "session.h"
#include "access_control.h"

#ifndef CPW_SESSION_H
#define CPW_SESSION_H

class CPWSession
{
	public:
		CPWSession();
		virtual ~CPWSession();
		
	public:
		Session* get_current_session() const;
		AccessControl* get_current_access_control() const;
	
	private:
		Session* current_session_;
		AccessControl* current_access_control_;
};

#endif /* CPW_SESSION_H */ 
