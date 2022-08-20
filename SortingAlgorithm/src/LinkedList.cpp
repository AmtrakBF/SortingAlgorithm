#include "LinkedList.h"

#include <iostream>

LinkedList::LinkedList()
{
	count = 0;
}

LinkedList::~LinkedList()
{
	link* node = head;
	link* next;
	for (int x = 0; x < count; x++)
	{
		next = node->next;
		delete[] node;
		node = next;
	}
}

void LinkedList::prepend(int value)
{
	link* newNode = new link(value);
	newNode->next = head;
	newNode->prev = nullptr;
	newNode->next->prev = newNode;
	head = newNode;

	++count;

	if (count == 1)
	{
		tail = head;
	}
}

void LinkedList::insert(link* previous, int value)
{
	link* newNode = new link(value);
	newNode->next = previous->next;
	newNode->next->prev = newNode;
	newNode->prev = previous;
	previous->next = newNode;
}


link LinkedList::Get(int index) // O^n
{
	link* buffer = head;
	for (int x = 0; x <= index; x++)
	{
		if (x == index)
			return (*head);
		head = head->next;
	}
}

link* LinkedList::GetHead()
{
	return head;
}

int LinkedList::GetCount()
{
	return count;
}

void LinkedList::append(int value)
{
	link* newTail = new link(value);
	tail->next = newTail;
	newTail->prev = tail;
	newTail->next = nullptr;

	tail = newTail;

	++count;

	if (count == 1)
	{
		head = tail;
	}
}

void LinkedList::print()
{
	link* node = head;
	while (true)
	{
		std::cout << node->value << std::endl;
		if (node->next == nullptr)
			break;
		else
			node = node->next;
	}
}