/*
 * inlines.cpp
 *
 *  Created on: Jul 17, 2012
 *      Author: tom
 */

#include <TurnLeftLib/Utils/inlines.h>
namespace TurnLeft
{

namespace Utils
{

inline void trimchar (std::string& str, const char& voip)
{
    int lastGoodChar = str.find_last_not_of(voip);
    int firstGoodChar = str.find_first_not_of(voip);
    int lenToEnd = lastGoodChar - firstGoodChar + 1;
    str = str.substr(firstGoodChar,lenToEnd);
} //trimchar

inline CharArray str_to_uchar (std::string input)
{
	char* copy = (char*) calloc(input.length(),sizeof(char));
	strcpy(copy, input.c_str());
	CharArray ucopy =
			reinterpret_cast <CharArray> (copy);
	return ucopy;
} //str_to_uchar

inline std::string uchar_to_str (CharArray input)
{
	c_str c_in =
			reinterpret_cast <c_str> (input);
	return std::string(c_in);
} //uchar_to_str

}//namespace Utils
}//namespace TurnLeft
