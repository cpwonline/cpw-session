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
	
	private:
		User* current_user_;
		std::list<Permission*> permissions_colector_;
		std::list<Level*> levels_colector_;
		Expiration* current_expiration_;
};

#endif /* SESSION_H */ 
