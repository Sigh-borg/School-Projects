/*  Author: Brian Ngeunjuntr
	Date: 7/24/22
	Class: CIS-2542
	File: LinkedList.cpp
	Descr:
		Implementaiton file for the class LinkedList.
*/

#include "LinkedList.h"

LinkedListNode::LinkedListNode(int val, LinkedListNode* prev, LinkedListNode* n)
	: data(val), previous(prev), next(n)
{

}

LinkedList::LinkedList()
	: head(nullptr)
{
	
}

LinkedList::~LinkedList()
{
	while (empty() == false)
	{
		pop_front();
	}
}

void LinkedList::push_front(int val)
{
	//  If the LinkedList is empty, push_front functions differently.
	if (empty() == true)
		// If the list is empty, create a new LinkedListNode pointer with the value.
	{
		head = new LinkedListNode(val);
			// *previous points to nullptr because head is the first Link in the chain and there is no previous Link.
			// *head points to the new node that we're adding to the front
	}
	else
	{
		// If the list has at least one element, create a new LinkedListNode pointer with the value and the previous list.
		LinkedListNode* NewNode = new LinkedListNode(val, nullptr, head);
			
		head->previous = NewNode;
			// *previous points to the previous node.

		head = NewNode;
		// head = new LinkedListNode (val, NewNode, head);
			// *head points to the new node 
			
	}
}

void LinkedList::pop_front()
{
	if (empty() == false)
	{
		
		
		if (size() == 1)
		{
			// One element
			delete head;
			head = nullptr;
		}
		else
		{
			// More than one element
			LinkedListNode* ToDelete = head;
				// Create pointer to the current head.

			head->next->previous = nullptr;
				// Go into the previous node and set *previous to nullptr (because the previous node is the second value,
				// and will now become the first)

			head = head->next;
				// Set the current head to the previous node because the current head will be deleted.

			delete ToDelete;
		}
		


		
	}
}

int LinkedList::operator[](int index)
{
	if ((index < 0) || (index >= size()))
	{
		return std::numeric_limits<int>::min();
			// Returns the smallest integer value to be stored (~ -2 billion).
			// This syntax is used in case of changes to the amount of bits in an int.
	}

	LinkedListNode* current = head;

	for (int i = 0; i < index; i++)
	{
		current = current->next;
	}

	return current->data;
}

bool LinkedList::empty()
{
	return head == nullptr;
}

int LinkedList::size() const
{
	int count = 0;
	LinkedListNode* current = head;
	while (current != nullptr)
	{
		++count;
		current = current->next;
	}
	return count;
}

void LinkedList::insert(int index, int val)
{
	if (empty() == true || index <= 0)
	{
		// Place at first element
		push_front(val);
	} 
	else if (index >= size())
	{
		// Place at last element
		LinkedListNode* prev = nullptr;
		LinkedListNode* current = head;
		while (current!= nullptr)
		{
			prev = current;
			current = current->next;
		}
		// prev is pointing to last node

		LinkedListNode* newNode = new LinkedListNode(val, prev);
		prev->next = newNode;

	}
	else if (index > 0)
	{
		// Place in between
		LinkedListNode* current = head;
		for (int i = 0; i < index; i++)
		{
			current = current->next;
		}

		LinkedListNode* newNode = new LinkedListNode(val, current->previous, current);
		current->previous->next = newNode;
		current->previous = newNode;

	}



}

void LinkedList::erase(int index)
{
	if (index <= 0 || size() <= 1)
	{
		pop_front();
	}
	else if (index >= size() - 1)
	{
		// There must be a previous element
		LinkedListNode* prev = nullptr;
		LinkedListNode* current = head;
		while (current != nullptr)
		{
			prev = current;
			current = current->next;
		}
		// prev is pointing to last node
		prev->previous->next = nullptr;
		delete prev;
	}
	else if (index > 0)
	{
		// There must be both a previous and next element.

		LinkedListNode* current = head;
		for (int i = 0; i < index; i++)
		{
			current = current->next;
		}

		current->previous->next = current->next;
		current->next->previous = current->previous;
		delete current;
	}
}

int LinkedList::find(int val)
{
	int index = 0;
	LinkedListNode* current = head;

	while (current != nullptr)
	{
		if (val == current->data)
		{
			return index;
		}

		++index;
		current = current->next;
	}

	return -1;
}

std::ostream& operator<<(std::ostream& ostr, const LinkedList& rhs)
{
	ostr << "LIST: ";
	LinkedListNode* current = rhs.head;
	while (current != nullptr)
	{
		ostr << " " << current->data;

		current = current->next;
	}

	ostr << " SIZE: " << rhs.size() << std::endl;

	return ostr;
}
