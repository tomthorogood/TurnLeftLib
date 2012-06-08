/*
 * strings.h
 *
 *  Created on: Apr 19, 2012
 *      Author: tom
 */

#ifndef TURNLEFT_UTILS_STRINGS_H_
#define TURNLEFT_UTILS_STRINGS_H_

#include "config.h"
#include <string>
#include <vector>
#include <sstream>
#include <iostream>

TL_UTILS_NAMESPACE

class Explosion
{
    /*! The string to be exploded */
	std::string str;

	/*! The number of words in the string.
	 * \sa explode()*/
	int numWords;

	/*! The array of words in the string.
	 * \sa str
	 */
	std::string strArray[300];

	/*! A pointer to the array, if desired.
	 * \sa getArrayPtr()
	 */
	std::string *arrayPtr;

public:
	Explosion(){};
	
    /*! Standard constructor, takes in the string to be iterated over.
	 * @param a string of up to 300 words.*/
	Explosion(std::string);

	/*! Fills the array parameter with the contents of the exploded array.
	 * @param an array of up to 300 slots.
	 * @return a reference to this object for method chaining
	 * \sa strArray
	 */
	inline Explosion& getArray (std::string[]);

	/*! Splits the string at any instance of the delimiter char, filling the instance array.
	 * @param a character delimiting the string
	 * @return a reference to this object for method chaining
	 * \sa str
	 * \sa strArray
	 */
	Explosion& explode(char delim);

	/*! Returns the pointer to the instance array.
	 * @return a pointer to the instance array
	 * \sa arrayPtr
	 */
	inline std::string *getArrayPtr();

	/*! Retrieves the number of words that were parsed from the input string.
	 * @return the number of words in the input string
	 * \sa numWords
	 */
	inline int getNumWords();
};

ECAPSEMAN_SLITU_LT
#endif /* TURNLEFT_UTILS_STRINGS_H_ */
