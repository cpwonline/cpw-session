/*
 * expiration.cc
 * 
 * Copyright 2021 CPW Online <support@cpwonline.org>
 * 
 * This program is free software; see the License file for more details.
 * 
 * You should have received a copy of the License along with this program.
 * 
 */


#include "expiration.h"


Expiration::Expiration(bool active, int session_duration) :
	active_(active),
	expired_(false)
{
	if(active_)
	{
		session_duration_ = session_duration;
		time_start_ = std::chrono::system_clock::now();
	}
}

Expiration::~Expiration()
{
	
}

bool Expiration::get_active() const
{
	return active_;
}

bool Expiration::get_expired() const
{
	return expired_;
}

std::chrono::minutes Expiration::get_session_duration() const
{
	return session_duration_;
}

std::chrono::time_point<std::chrono::system_clock> Expiration::get_time_start() const
{
	return time_start_;
}

std::chrono::time_point<std::chrono::system_clock> Expiration::get_time_end() const
{
	return time_end_;
}

std::chrono::duration<double> Expiration::get_time_remaining() const
{
	return time_remaining_;
}

void Expiration::ElapsedTime_()
{
	time_end_ = std::chrono::system_clock::now();
	time_remaining_ = session_duration_ - time_end_ - time_start_;
}