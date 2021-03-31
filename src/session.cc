/*
 * session.cc
 * 
 * Copyright 2021 CPW Online <support@cpwonline.org>
 * 
 * This program is free software; see the License file for more details.
 * 
 * You should have received a copy of the License along with this program.
 * 
 */


#include "session.h"


Session::Session()
{
	current_user_ = new User();
	permissions_colector_ = new Permission();
	levels_colector_ = new Level();
	current_expiration_ = new Expiration();
}


Session::~Session()
{
	delete current_user_;
	delete permissions_colector_;
	delete levels_colector_;
	delete current_expiration_;
}
}

User* Session::get_current_user() const
{
	return current_user_;
}

std::list<Permission*> Session::get_permissions_colector() const
{
	return permissions_colector_;
}

std::list<Level*> Session::get_levels_colector() const
{
	return levels_colector_;
}

Expiration* Session::get_current_expiration() const
{
	return current_expiration_;
}