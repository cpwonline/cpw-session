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


Session::Session(bool active, int session_duration)
{
	current_user_ = new User();
	permissions_colector_ = new std::set<Permission*>;
	levels_colector_ = new std::set<Level*>;
	current_expiration_ = new Expiration(active, session_duration);
}

Session::~Session()
{
	delete current_user_;
	
	for(auto it = permissions_colector_->begin(); it != permissions_colector_->end(); ++it)
		delete *it;
	delete permissions_colector_;
	
	for(auto it = levels_colector_->begin(); it != levels_colector_->end(); ++it)
		delete *it;
	delete levels_colector_;
	
	delete current_expiration_;
}

User* Session::get_current_user() const
{
	return current_user_;
}

std::set<Permission*>* Session::get_permissions_colector() const
{
	return permissions_colector_;
}

std::set<Level*>* Session::get_levels_colector() const
{
	return levels_colector_;
}

Expiration* Session::get_current_expiration() const
{
	return current_expiration_;
}