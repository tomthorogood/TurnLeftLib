/*
 * tlstring.cpp
 *
 *  Created on: May 17, 2012
 *      Author: tom
 */

#include "tlstring.h"

namespace TurnLeft{
namespace Utils{

TLString::TLString()
{
	stream << "";
}

TLString::TLString(const char* _ch)
{
	stream << _ch;
}

TLString::TLString(std::string _str)
{
	stream << _str;
}

std::string
TLString::str()
{
	return stream.str();
}

TLString&
TLString::toUpper(bool keepNonAlpha=false)
{
	int len = str().length();
	const char* _ch = str().c_str();
	clr();
	for (int i = 0; i < len; i++)
	{
		if (isalpha(_ch[i]) || keepNonAlpha)
		{
			if (islower(_ch[i]))
			{
				stream << toupper(_ch[i]);
			}
			else
			{
				stream << _ch[i];
			}
		}
	}
	return *this;
}

TLString&
TLString::toLower(bool keepNonAlpha=false)
{
	int len = str().length();
	const char* _ch = str().c_str();
	clr();
	for (int i = 0; i < len; i++)
	{
		if (isalpha(_ch[i]) || keepNonAlpha)
		{
			if (isupper(_ch[i]))
			{
				stream << tolower(_ch[i]);
			}
			else
			{
				stream << _ch[i];
			}
		}
	}
	return *this;
}

TLString&
TLString::filter(char ch)
{
	int len = str().length();
	const char* _ch = str().c_str();
	clr();
	for (int i = 0; i < len; i++)
	{
		if (ch != _ch[i])
		{
			stream << _ch[i];
		}
	}
	return *this;
}

TLString&
TLString::operator+(const char* _rhs)
{
	stream << _rhs;
	return *this;
}

TLString&
TLString::operator+(std::string _rhs)
{
	stream << _rhs;
	return *this;
}

TLString&
TLString::operator+(TLString& _rhs)
{
	stream << _rhs.str();
	return *this;
}

TLString&
TLString::operator+=(const char* _rhs)
{
	stream << _rhs;
	return *this;
}

TLString&
TLString::operator+=(std::string _rhs)
{
	stream << _rhs;
	return *this;
}

TLString&
TLString::operator+=(TLString& _rhs)
{
	stream << _rhs.str();
	return *this;
}


TLString&
TLString::operator<<(const char* _rhs)
{
	stream << _rhs;
	return *this;
}

TLString&
TLString::operator<<(std::string _rhs)
{
	stream << _rhs;
	return *this;
}

TLString&
TLString::operator<<(TLString& _rhs)
{
	stream << _rhs.str();
	return *this;
}

TLString&
TLString::operator= (const char* _rhs)
{
	clr();
	stream << _rhs;
	return *this;
}

TLString&
TLString::operator= (std::string _rhs)
{
	clr();
	stream << _rhs;
	return *this;
}

TLString&
TLString::operator=(TLString& _rhs)
{
	clr();
	stream << _rhs.str();
	return *this;
}

}}
