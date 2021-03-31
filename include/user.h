/*
 * user.h
 * 
 * Copyright 2021 CPW Online <support@cpwonline.org>
 * 
 * This program is free software; see the License file for more details.
 * 
 * You should have received a copy of the License along with this program.
 * 
 */


#include <string>

#ifndef USER_H
#define USER_H

class User
{
	public:
		User();
		virtual ~User();
		
	public:
		std::string get_user_name() const;
	
	public:
		void set_user_name(std::string user_name);
		
	private:
		std::string user_name_;
};

#endif /* USER_H */ 
