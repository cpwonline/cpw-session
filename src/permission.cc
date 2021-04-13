/*
 * permission.cc
 * 
 * Copyright 2021 CPW Online <support@cpwonline.org>
 * 
 * This program is free software; see the License file for more details.
 * 
 * You should have received a copy of the License along with this program.
 * 
 */


#include "permission.h"


Permission::Permission()
{
	
}

Permission::~Permission()
{
	
}

bool Permission::DAC::get_create() const
{
	return create;
}

bool Permission::DAC::get_read() const
{
	return read;
}

bool Permission::DAC::get_update() const
{
	actions_list_ = new DACList();
	name_ = permission->get_name();
	passed_ = permission->get_passed();
	description_ = permission->get_description();
	actions_list_->set_create(permission->get_actions_list()->get_create());
	actions_list_->set_read(permission->get_actions_list()->get_read());
	actions_list_->set_update(permission->get_actions_list()->get_update());
	actions_list_->set_remove(permission->get_actions_list()->get_remove());
}

bool Permission::DAC::get_remove() const
{
	return remove;
}

void Permission::DAC::set_create(bool create)
{
	this->create = create;
}

void Permission::DAC::set_read(bool read)
{
	this->read = read;
}

void Permission::DAC::set_update(bool update)
{
	this->update = update;
}

void Permission::DAC::set_remove(bool remove)
{
	this->remove = remove;
}

std::string Permission::get_name() const
{
	return name_;
}

bool Permission::get_passed() const
{
	return passed_;
}

std::string Permission::get_description() const
{
	return description_;
}

Permission::DAC Permission::get_actions_list() const
{
	return actions_list_;
}

void Permission::set_name(std::string name)
{
	name_ = name;
}

void Permission::set_passed(bool passed)
{
	passed_ = passed;
}

void Permission::set_description(std::string description)
{
	description_ = description;
}