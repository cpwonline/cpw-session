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
		Level();
		virtual ~Level();
	
	private:
		int identifier_;
		std::string name_;
};

#endif /* LEVEL_H */ 
