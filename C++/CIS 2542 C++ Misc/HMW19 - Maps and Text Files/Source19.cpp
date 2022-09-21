/*  Author: Brian Ngeunjuntr
	Date: 8/7/22
	Class: CIS-2542
	File: Source19.cpp
	Descr:
		Finds a hidden sentence in a list of random words using a map.
*/

// Place the contents of the file into an appropriate data structure in the following matter:
	// Grab a pair of strings from the file (unless end of file is reached)
	// Each string is separated by a space
	// The firs string is the key
	// The second string is the value
	// So both the key and value are strings
	// Place the key/value pair into your data structure

#include <map>
#include <fstream>
#include <iostream>

int main()
{
	std::ifstream file("words.txt");
	if (file.fail() == true)
	{
		std::cout << "File didn't open" << std::endl;
		exit(1);
	}

	std::map<std::string, std::string> m;

	while (file.eof() == false)
	{
		std::string a, b;
		file >> a >> b;
		m[a] = b;
	}

	file.close();

	std::string longest;

	for (const std::pair<std::string, std::string>& p : m)
	{
		
		std::string phrase = p.first + " ";
		std::string last = p.second;
		std::map<std::string, std::string>::iterator next = m.find(p.second);
		while (next != m.end())
		{
			phrase += next->first + " ";
			last = next->second;
			next = m.find(next->second);
		}

		if (phrase.size() > longest.size())
		{
			longest = phrase;
		}
	}
	std::cout << longest << std::endl;


	return 0;
}