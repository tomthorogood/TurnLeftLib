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

inline CharArray str_to_uchar (std::string input)
{

    const char* cinput = input.c_str();
    size_t len = (strlen(cinput) * sizeof(char)) + 1;
    char* copy = (char*) malloc (len);
	strcpy(copy, cinput);
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

inline void stolower (std::string& str)
{
    int len = str.length();
    for (int c = 0; c < len; c++)
    {
        char ch = str.at(c);
        if (isalpha(ch))
        {
            str.at(c) = tolower(ch);
        }
    }
}

inline std::string itoa(int i)
{
    std::stringstream s;
    s << i;
    return i.str();
}

inline void sreplace(std::string& str, char inc, char rep)
{
    int len = str.length();
    for (int c = 0; c < len; c++)
    {
        char sch = str.at(c);
        if (sch == inc) str.at(c) = rep;
    }
}

inline void trimchar (std::string& str, const char& voip=' ')
{
    int lastGoodChar = str.find_last_not_of(voip);
    int firstGoodChar = str.find_first_not_of(voip);
    int lenToEnd = lastGoodChar - firstGoodChar + 1;
    str = str.substr(firstGoodChar,lenToEnd);
} //trimchar

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
