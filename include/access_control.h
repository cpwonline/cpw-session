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
#include <algorithm>

#include <permission.h>
#include <level.h>

#ifndef ACCESS_CONTROL_H
#define ACCESS_CONTROL_H

class AccessControl
{
	public:
		AccessControl(std::set<Permission*>* permissions_colector, std::set<Level*>* levels_colector);
		virtual ~AccessControl();
		
	public:
		std::set<Permission*>* get_permissions_colector() const;
		std::set<Level*>* get_levels_colector() const;
		
	public:
		bool VerifyAccess_(Permission* permission_to_verify);
		bool VerifyAccess_(Level* level_to_verify);
		
	private:
		std::set<Permission*>* permissions_colector_;
		std::set<Level*>* levels_colector_;
};

#endif /* ACCESS_CONTROL_H */ 
