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


#ifndef PERMISSION_H
#define PERMISSION_H

class Permission
{
	public:
		Permission();
		virtual ~Permission();
	
	private:
		int identifier_;
		std::string name_;
		std::string desription_;
		bool passed_;
};

#endif /* PERMISSION_H */ 
