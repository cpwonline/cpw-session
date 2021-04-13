/*
 * access_control.h
 * 
 * Copyright 2021 CPW Online <support@cpwonline.org>
 * 
 * This program is free software; see the License file for more details.
 * 
 * You should have received a copy of the License along with this program.
 * 
 */

#include <set>

#include <permission.h>
#include <level.h>

#ifndef ACCESS_CONTROL_H
#define ACCESS_CONTROL_H

class AccessControl
{
	public:
		AccessControl();
		virtual ~AccessControl();
	
	private:
		std::set<Permission*>* permissions_colector_;
		std::set<Level*>* levels_colector_;
};

#endif /* ACCESS_CONTROL_H */ 
