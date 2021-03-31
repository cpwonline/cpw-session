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
	
	public:
		int get_identifier() const;
		std::string get_name() const;
		std::string get_desription() const;
		bool get_passed() const;
	
	public:
		void set_identifier(int identifier);
		void set_name(std::string name);
		void set_desription(std::string desription);
		void set_passed(bool passed);
		
	private:
		int identifier_;
		std::string name_;
		std::string desription_;
		bool passed_;
};

#endif /* PERMISSION_H */ 
