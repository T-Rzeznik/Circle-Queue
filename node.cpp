#include "node.h"
#include <iostream>
using namespace std;

node::value_type node::get_data()
{
	return data_field;
}

node* node::get_link()
{
	return link_field;
}

void node::set_data(value_type entry)
{
	data_field = entry;
}

void node::set_link(node* link_ptr)
{
	link_field = link_ptr;
}

node::node(value_type entry, node* link_ptr)
{
	data_field = entry;
	link_field = link_ptr;
}

void list_head_insert(node*& head_ptr, const node::value_type& entry)
{
	head_ptr = new node(entry, head_ptr);
}

void list_head_remove(node*& head_ptr)
{
	/*
	node* cursor = head_ptr;
	while (cursor->get_link() != head_ptr)   //loops until cursor = the node before rear_ptr;
	{
		cursor = cursor->get_link();
	}
	cursor->set_link(head_ptr->get_link()); //sets the link of the last node to the node infront of the rear_ptr
	*/

	node* remove_ptr;
	remove_ptr = head_ptr;
	head_ptr = head_ptr->get_link(); // head_ptr = (*head_ptr).get_link();
	delete remove_ptr;
}

void list_insert(node*& previous_ptr, const node::value_type& entry)
{
	node* insert_ptr;
	insert_ptr = new node(entry, previous_ptr->get_link());
	previous_ptr->set_link(insert_ptr);
}

void list_remove(node*& previous_ptr)
{
	node* remove_ptr;
	remove_ptr = previous_ptr->get_link();
	previous_ptr->set_link(remove_ptr->get_link());
	delete remove_ptr;
}

void list_display(node*& head_ptr)
{
	node* cursor;
	cursor = head_ptr;
	while (cursor != nullptr)
	{
		cout << cursor->get_data() << endl;
		cursor = cursor->get_link();
	}
}

int list_length(node*& head_ptr)
{
	node* cursor;
	cursor = head_ptr;
	int length = 0;
	while (cursor != nullptr)
	{
		length++;
		cursor = cursor->get_link();
	}
	return length;
}

node* list_search(node* head_ptr, const node::value_type& target)
{
	node* cursor;
	cursor = head_ptr;
	while (cursor != nullptr)
	{
		if ( cursor->get_data() == target)
		{
			return cursor;
		}
		else
			cursor = cursor->get_link();
	}
	return nullptr;
}

node* list_locate(node* head_ptr, int position)
{
	node* cursor = head_ptr;
	int i = 1;
	while ((i<position) && (cursor!=nullptr))
	{
		i++;
		cursor = cursor->get_link();
	}
	return cursor;
}

void list_clear(node*& head_ptr)
{
	while (head_ptr!=nullptr)
	{
		list_head_remove(head_ptr);
	}
}

void list_copy(node* source_ptr, node*& head_ptr)
{
	node* cursor;
	head_ptr = nullptr;
	if (source_ptr == nullptr)
	{
		return;
	}
	list_head_insert(head_ptr, source_ptr->get_data());
	cursor = head_ptr;
	source_ptr = source_ptr->get_link();
	while (source_ptr!=nullptr)
	{
		list_insert(cursor, source_ptr->get_data());
		cursor = cursor->get_link();
		source_ptr = source_ptr->get_link();
	}
}

void list_remove_target(node*& head_ptr, const node::value_type& target)
{
	node* cursor;
	cursor = head_ptr;
	node* pre_cursor;
	pre_cursor = nullptr;
	while (cursor != nullptr)
	{
		if (cursor->get_data() == target)
		{
			if (cursor == head_ptr)
			{
				list_head_remove(head_ptr);
				cursor = head_ptr;
			}
			else
			{
				cursor = cursor->get_link();
				list_remove(pre_cursor);
			}
		}
		else
		{
			pre_cursor = cursor;
			cursor = cursor->get_link();
		}
	}
}