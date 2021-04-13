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

#ifndef PERMISSION_H
#define PERMISSION_H

class Permission
{
	public:
		Permission();
		virtual ~Permission();
	
	public:
		struct DAC
		{
			public:
				bool get_create() const;
				bool get_read() const;
				bool get_update() const;
				bool get_remove() const;
				
			public:
				void set_create(bool create);
				void set_read(bool read);
				void set_update(bool update);
				void set_remove(bool remove);
				
			private:
				bool create, read, update, remove;
		};
	
	public:
		std::string get_name() const;
		bool get_passed() const;
		std::string get_description() const;
		DAC get_actions_list() const;
	
	public:
		void set_name(std::string name);
		void set_passed(bool passed);
		void set_description(std::string description);
		
	private:
		std::string name_;
		bool passed_;
		std::string description_;
		DAC actions_list_;
};

#endif /* PERMISSION_H */ 
