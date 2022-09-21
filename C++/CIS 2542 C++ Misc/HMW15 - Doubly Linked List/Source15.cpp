/*  Author: Brian Ngeunjuntr
	Date: 7/24/22
	Class: CIS-2542
	File: Source15.cpp
	Descr:
		Demonstrates the functionality of doubly linked lists.
*/

#include <iostream>
#include "LinkedList.h"

int main() 
{
	LinkedList a;
	std::cout << a;
	a.insert(-3,20);
	std::cout << a;
	a.insert(12, 10);
	std::cout << a;
	a.insert(0, 30);
	std::cout << a;
	a.push_front(50);
	std::cout << a;
	a.insert(1, 40);
	std::cout << a;
	a.insert(5, 0);
	std::cout << a;
	a.insert(5, 5);
	std::cout << a;
	a.erase(-1);
	std::cout << a;
	a.erase(0);
	std::cout << a;
	a.erase(4);
	std::cout << a;
	a.erase(4);
	std::cout << a;
	a.erase(1);
	std::cout << a;
	
	int x; 
	std::cout << "Enter find value: ";
	std::cin >> x;
	std::cout << a.find(x) << std::endl;

	
	for (int i = -2; i <= 3; i++)
	{
		std::cout << "Index " << i << ": " << a[i] << std::endl;
	}
	

	
	while (a.empty() == false)
	{
		a.pop_front();
		std::cout << a;
	}

	a.pop_front();

	
	return 0;
}
