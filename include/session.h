/*
 * session.h
 * 
 * Copyright 2021 CPW Online <support@cpwonline.org>
 * 
 * This program is free software; see the License file for more details.
 * 
 * You should have received a copy of the License along with this program.
 * 
 */


#include <list>

#include "user.h"
#include "permission.h"
#include "level.h"
#include "expiration.h"

#ifndef SESSION_H
#define SESSION_H

class Session
{
	public:
		Session();
		virtual ~Session();
		
	public:
		User* get_current_user() const;
		std::list<Permission*> get_permissions_colector() const;
		std::list<Level*> get_levels_colector() const;
		Expiration* get_current_expiration() const;
		
	private:
		User* current_user_;
		std::list<Permission*> permissions_colector_;
		std::list<Level*> levels_colector_;
		Expiration* current_expiration_;
};

#endif /* SESSION_H */ 
