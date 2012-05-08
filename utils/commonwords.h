/*
 * commonwords.h
 *
 *  Created on: Apr 18, 2012
 *      Author: tom
 */

#ifndef COMMONWORDS_H_
#define COMMONWORDS_H_
#include <iostream>
#include <fstream>
#include <sstream>

namespace TurnLeft{
namespace Utils{

class CommonWords
{
	const static int MAX_LIBRARY_SIZE = 101;
	int numInput;
	std::string library[MAX_LIBRARY_SIZE];
	bool parsed;
public:
	CommonWords(){};
	CommonWords(const char *filename);
	bool find(std::string);
};
CommonWords::CommonWords(const char *filename)
{
	/* The first time this object type is created,
	 * we'll parse through the library. After that,
	 * there is no need to do so!
	 */
	numInput = 0;
	parsed = false;
	if (!parsed)
	{
		std::string word;
		std::ifstream f;
		f.open(filename);
		while (f)
		{
			if (f.eof()) break;
			std::getline(f, word);
			// Conver to lower case
			for (int i = 0; i < word.length(); i++)
			{ // Convert the word to lowercase
				tolower(word[i]);
			}
			library[numInput] = word;
			numInput++;
		}
	}
}

/*
 * Returns true if the word passed in exists in the library,
 * false otherwise.
 * \precondition The string input must be lowercase with no non-alpha chars.
 */
bool
CommonWords::find(std::string searchValue)
{

	bool found = false;
	for (int i = 0; i < MAX_LIBRARY_SIZE; i++)
	{
		if (searchValue == library[i]) return true;
	}
	return false;
}

}}

#endif /* COMMONWORDS_H_ */
