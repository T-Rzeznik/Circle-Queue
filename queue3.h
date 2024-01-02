#pragma once
#include "node.h"

class queue
{
public:
	typedef int value_type;

	void push(const value_type& entry);
	void pop();
	value_type front() const;

	queue();

	queue(const queue& source);
	void operator=(const queue& source);
	~queue();

private:
	node* rear_ptr;
	int count;
};

