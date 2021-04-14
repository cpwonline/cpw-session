/*
 * dac_list.cc
 * 
 * Copyright 2021 CPW Online <support@cpwonline.org>
 * 
 * This program is free software; see the License file for more details.
 * 
 * You should have received a copy of the License along with this program.
 * 
 */


#include "dac_list.h"


DACList::DACList()
{
	
}

DACList::~DACList()
{
	
}

bool DACList::get_create() const
{
	return create_;
}

bool DACList::get_read() const
{
	return read_;
}

bool DACList::get_update() const
{
	return update_;
}

bool DACList::get_delete() const
{
	return delete_;
}

void DACList::set_create(bool create)
{
	create_ = create;
}

void DACList::set_read(bool read)
{
	read_ = read;
}

void DACList::set_update(bool update)
{
	update_ = update;
}

void DACList::set_delete(bool remove)
{
	delete_ = remove;
}
