#pragma once

struct link 
{
	link(int value)
		: value(value), next(nullptr), prev(nullptr)
	{
	}

	int value;
	link* next;
	link* prev;
};

 
class LinkedList
{
private:

	link* tail = new link(0);
	link* head = new link(0);
	int count;

public:
	LinkedList();
	~LinkedList();

	void append(int value);
	void prepend(int value);
	void insert(link* previous, int value);

	link Get(int index);
	link* GetHead();

	int GetCount();

	void print();
};
