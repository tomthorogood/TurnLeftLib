/*
 * randomcharset.cpp
 *
 *  Created on: Jul 17, 2012
 *      Author: tom
 */

#include <TurnLeftLib/Utils/randomcharset.h>
#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <string>
#include <time.h>
namespace TurnLeft
{
namespace Utils
{


RandomCharSet::RandomCharSet()
{
	srand( time(NULL) );
}

RandomCharSet::RandomCharSet(int seed)
{
	srand(seed);
}

std::string RandomCharSet::generate(int num)
{
	std::stringstream stream;
	for (int i = 0; i < num; i++)
	{
		stream << upper(rand()) << digit(rand()) << lower(rand());
	}
	return stream.str();
}

inline char RandomCharSet::digit(int num)
{
	return (num%10)+48;
}

inline char RandomCharSet::lower(int num)
{
	return (num%26)+97;
}

inline char RandomCharSet::upper(int num)
{
	return (num%26)+65;
}

}//namespace Utils
}//namespace TurnLeft
