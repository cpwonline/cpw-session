/*
 * expiration.h
 * 
 * Copyright 2021 CPW Online <support@cpwonline.org>
 * 
 * This program is free software; see the License file for more details.
 * 
 * You should have received a copy of the License along with this program.
 * 
 */


#include <chrono>

#ifndef EXPIRATION_H
#define EXPIRATION_H

class Expiration
{
	public:
		Expiration(bool active, int session_duration = 0);
		virtual ~Expiration();
	
	public:
		bool get_active() const;
		bool get_expired() const;
		std::chrono::duration<double> get_session_duration() const;
		std::chrono::duration<double> get_elapsed_seconds() const;
		std::chrono::duration<double> get_time_remaining() const;
		
	protected:
		std::chrono::time_point<std::chrono::system_clock> get_time_start() const;
		std::chrono::time_point<std::chrono::system_clock> get_time_end() const;
		
	public:
		bool VerifyStatus_();
		void Restart_();
		
	protected:
		void ElapsedTime_();
	
	private:
		bool active_;
		bool expired_;
		std::chrono::duration<double> session_duration_;
		std::chrono::duration<double> elapsed_seconds_;
		std::chrono::duration<double> time_remaining_;
		std::chrono::time_point<std::chrono::system_clock> time_start_;
		std::chrono::time_point<std::chrono::system_clock> time_end_;
};

#endif /* EXPIRATION_H */ 
