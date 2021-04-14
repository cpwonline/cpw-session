/*
 * permission.h
 * 
 * Copyright 2021 CPW Online <support@cpwonline.org>
 * 
 * This program is free software; see the License file for more details.
 * 
 * You should have received a copy of the License along with this program.
 * 
 */


#include <string>

#include "dac_list.h"

#ifndef PERMISSION_H
#define PERMISSION_H

class Permission
{
	public:
		Permission();
		Permission(const Permission* permission);
		virtual ~Permission();
	
	public:
		std::string get_name() const;
		bool get_enabled() const;
		std::string get_description() const;
		DACList* get_actions_list() const;
	
	public:
		void set_name(std::string name);
		void set_enabled(bool enabled);
		void set_description(std::string description);
		
	private:
		std::string name_;
		bool enabled_;
		std::string description_;
		DACList* actions_list_;
};

#endif /* PERMISSION_H */ 
