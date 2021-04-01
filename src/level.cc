/*
 * level.cc
 * 
 * Copyright 2021 CPW Online <support@cpwonline.org>
 * 
 * This program is free software; see the License file for more details.
 * 
 * You should have received a copy of the License along with this program.
 * 
 */


#include "level.h"


Level::Level(std::string name) :
	name_(name)
{
	
}

Level::~Level()
{
	
}

int Level::get_identifier() const
{
	return identifier_;
}

std::string Level::get_name() const
{
	return name_;
}

void Level::set_identifier(int identifier)
{
	identifier_ = identifier;
}

void Level::set_name(std::string name)
{
	name_ = name;
}