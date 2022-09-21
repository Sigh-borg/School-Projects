/*  Author: Brian Ngeunjuntr
	Date: 7/24/22
	Class: CIS-2542
	File: LinkedList.h
	Descr:
		Specification file for the class LinkedList.
*/
#pragma once
#include <iostream>

class LinkedListNode
{
public: 
	LinkedListNode(int val, LinkedListNode* prev = nullptr, LinkedListNode* n = nullptr);

	int data;
	LinkedListNode* previous;
	LinkedListNode* next;
};

class LinkedList
{
public:
	LinkedList();
	~LinkedList();

	void push_front(int val);

	void pop_front();

	friend std::ostream& operator << (std::ostream &ostr, const LinkedList &rhs);

	int operator[](int index);

	bool empty();

	int size() const;

	void insert(int index, int val);

	void erase(int index);

	int find(int val);

private:
	LinkedListNode *head;
};