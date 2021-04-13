/*
 * access_control.cc
 * 
 * Copyright 2021 CPW Online <support@cpwonline.org>
 * 
 * This program is free software; see the License file for more details.
 * 
 * You should have received a copy of the License along with this program.
 * 
 */


#include "access_control.h"


AccessControl::AccessControl(std::set<Permission*>* permissions_colector, std::set<Level*>* levels_colector)
{
	permissions_colector_ = permissions_colector;
	levels_colector_ = levels_colector;
}

AccessControl::~AccessControl()
{
	
}

std::set<Permission*>* AccessControl::get_permissions_colector() const
{
	return permissions_colector_;
}

std::set<Level*>* AccessControl::get_levels_colector() const
{
	return levels_colector_;
}