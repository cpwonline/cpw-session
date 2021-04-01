/*
 * level.h
 * 
 * Copyright 2021 CPW Online <support@cpwonline.org>
 * 
 * This program is free software; see the License file for more details.
 * 
 * You should have received a copy of the License along with this program.
 * 
 */


#include <string>

#ifndef LEVEL_H
#define LEVEL_H

class Level
{
	public:
		Level(std::string name);
		virtual ~Level();
		
	public:
		int get_identifier() const;
		std::string get_name() const;
		
	public:
		void set_identifier(int identifier);
		void set_name(std::string name);
	
	private:
		int identifier_;
		std::string name_;
};

#endif /* LEVEL_H */ 
