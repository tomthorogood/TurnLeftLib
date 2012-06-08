/*
 * strings.cpp
 *
 *  Created on: Apr 19, 2012
 *      Author: tom
 */

#include <strings.h>

TL_UTILS_NAMESPACE

Explosion::Explosion(std::string aString)
{
    str = aString;
    numWords = 0;
}

inline Explosion& Explosion::getArray(std::string arr[])
{
	for (int i = 0; i < numWords; i++)
	{
	    arr[i] = strArray[i];
	}
	return *this;
}

inline std::string* Explosion::getArrayPtr()
{
    return arrayPtr;
}

Explosion& Explosion::explode (char delimiter)
{
    std::stringstream buffer;
	int maxLength = str.length();
	for (int ch = 0; ch < maxLength; ch++)
	{
	    char char_ = str[ch];
	    /*! If the character is a letter, send the lowercase
	     * version to the output buffer.
	     */
	    if (isalpha(char_))
	    {
	        if (isupper(char_)) char_ = tolower(char_);
	        buffer << char_;
	    }
	    /*! If it's a character, send the output buffer to the string array,
	     * and clear the buffer to accept more input.
	     */
	    if (char_ == ' ' || ch == maxLength-1)
	    {
	        std::string asString = buffer.str();
	        strArray[numWords] = asString;
	        numWords++;
	        buffer.str("");
	    }
	}
	return *this;
}

inline int Explosion::getNumWords()
{
    return numWords;
}

ECAPSEMAN_SLITU_LT
