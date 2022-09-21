/*  Author: Brian Ngeunjuntr
	Date: 7/24/22
	Class: CIS-2542
	File: Source16.cpp
	Descr:
		Demonstrates recursive functions.
*/

#include <iostream>
#include <string>

int Appearances(int value, int search)
{
	// Recurses until it reaches the first digit.
	if (value < 10)
		return value == search;
			// Booleans return 1 (true) or 0 (false)

	return Appearances(value / 10, search) + (value % 10 == search);
		// Every recursion adds a 1 or a 0 to the total result returned for each digit in value.
}

std::string IntegerToBase6(int value)
{
	if (value < 6)
		return std::to_string(value % 6);
	return IntegerToBase6(value / 6) + std::to_string(value % 6);
		// Every recursion concatenates a base 6 digit to the string that is to be returned.
	

}


int main()
{
	std::cout << "1? " << Appearances(0, 0) << std::endl;
	std::cout << "0? " << Appearances(0, 8) << std::endl;
	std::cout << "3? " << Appearances(1000, 0) << std::endl;
	std::cout << "3? " << Appearances(5326822, 2) << std::endl;

	std::cout << "5324422: " << IntegerToBase6(5324422) << std::endl;
	std::cout << "5: " << IntegerToBase6(5) << std::endl;
	std::cout << "6: " << IntegerToBase6(6) << std::endl;
	std::cout << "7: " << IntegerToBase6(7) << std::endl;
	std::cout << "8: " << IntegerToBase6(8) << std::endl;
	std::cout << "36: " << IntegerToBase6(36) << std::endl;
	return 0;
}