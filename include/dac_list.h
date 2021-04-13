/*
 * dac_list.h
 * 
 * Copyright 2021 CPW Online <support@cpwonline.org>
 * 
 * This program is free software; see the License file for more details.
 * 
 * You should have received a copy of the License along with this program.
 * 
 */


#ifndef DAC_LIST_H
#define DAC_LIST_H

class DACList
{
	public:
		DACList();
		virtual ~DACList();
	
	public:
		bool get_create() const;
		bool get_read() const;
		bool get_update() const;
		bool get_remove() const;
		
	public:
		void set_create(bool create);
		void set_read(bool read);
		void set_update(bool update);
		void set_remove(bool remove);
		
	private:
		bool create_, read_, update_, remove_;
};

#endif /* DAC_LIST_H */ 
