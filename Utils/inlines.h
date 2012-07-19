#ifndef TL_UTILS_INLINES_H_
#define TL_UTILS_INLINES_H_

#include <TurnLeftLib/TurnLeft.h>
#include <sstream>
#include <stdlib.h>
#include <string.h>
#include <string>


namespace TurnLeft
{
namespace Utils
{


inline CharArray str_to_uchar (std::string input);
inline std::string uchar_to_str (CharArray input);
inline void trimchar (std::string& str, const char& voip=' ');

template <class T>
inline bool isset (const T& test, int mask)
{
    return test & mask == mask;
}

template <class T>
inline bool exor (const T& alpha, const T& beta, const T& value)
{
    return (
            (alpha == value && beta == value) 
            ||
            (alpha != value && beta != value)
           );
}

template <size_t size>
inline std::string uchar_to_int_str (CharArray input)
{
	std::stringstream strm;
	for (int i = 0; i < size; i++)
	{
		int ch = (int) input[i];
		strm << ch << " ";
	}
	return strm.str();
}

template <size_t size>
CharArray int_str_to_uchar (std::string input)
{
	std::stringstream strm;
	int len = input.length();
	CharArray out = (CharArray) calloc (size, sizeof(char));
	int num_sets = 0;

	for (int i = 0; i < len; i++)
	{
		char ch = input.at(i);
		if (ch != ' ')
		{
			strm << ch;
		}
		else
		{
			std::string num_str = strm.str();
			int n = atoi(num_str.c_str());
			out[num_sets] = (unsigned char) n;
			num_sets++;
			strm.str("");
		}
	}
	return out;
}

}//namespace utils
}//namespace TurnLeft
#endif
