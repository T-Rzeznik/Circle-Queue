#include "queue3.h"
#include <cassert>
using namespace std;

void queue::push(const value_type& entry)
{
	if (rear_ptr == nullptr) {
		rear_ptr = new node(entry, nullptr);
		rear_ptr->set_link(rear_ptr); // Point to itself in a circular manner
	}
	else {
		node* new_node = new node(entry, rear_ptr->get_link());
		rear_ptr->set_link(new_node);
		rear_ptr = new_node;
	}
	count++;
}

void queue::pop()
{
		assert(count > 0);
		if (rear_ptr->get_link() == rear_ptr) {
			delete rear_ptr;
			rear_ptr = nullptr;
		}
		else {
			node* temp = rear_ptr->get_link();
			rear_ptr->set_link(temp->get_link());
			delete temp;
		}
		count--;
	}

queue::value_type queue::front() const
{
	assert(count > 0);
	return rear_ptr->get_link()->get_data();
}

queue::queue()
{
	count = 0;
	rear_ptr = nullptr;
}

queue::queue(const queue& source)
{
	count = source.count;

	if (source.rear_ptr == nullptr) {
		rear_ptr = nullptr;
		return;
	}

	rear_ptr = new node(source.rear_ptr->get_data(), nullptr);
	node* source_current = source.rear_ptr->get_link();
	node* new_current = rear_ptr;

	while (source_current != source.rear_ptr) {
		new_current->set_link(new node(source_current->get_data(), nullptr));
		new_current = new_current->get_link();
		source_current = source_current->get_link();
	}

	new_current->set_link(rear_ptr);
}

void queue::operator=(const queue& source)
{
	if (this == &source) {
		return;
	}

	this->~queue();
	count = source.count;

	if (source.rear_ptr == nullptr) {
		rear_ptr = nullptr;
		return;
	}

	rear_ptr = new node(source.rear_ptr->get_data(), nullptr);
	node* source_current = source.rear_ptr->get_link();
	node* new_current = rear_ptr;

	while (source_current != source.rear_ptr) {
		new_current->set_link(new node(source_current->get_data(), nullptr));
		new_current = new_current->get_link();
		source_current = source_current->get_link();
	}

	new_current->set_link(rear_ptr);
}

queue::~queue()
{
	while (rear_ptr != nullptr) {
		node* temp = rear_ptr->get_link();
		if (temp == rear_ptr) {
			delete rear_ptr;
			rear_ptr = nullptr;
		}
		else {
			rear_ptr->set_link(temp->get_link());
			delete temp;
		}
	}
}
