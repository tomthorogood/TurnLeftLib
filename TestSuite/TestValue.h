/*
 * TestValue.h
 *
 *  Created on: Sep 15, 2012
 *      Author: tom
 */

#ifndef TESTVALUE_H_
#define TESTVALUE_H_

#include <string>
#include <iostream>
namespace ResultType{
enum type {
	t_int	=0
	,t_flt	=1
	,t_str  =2
    ,t_chr  =3
};
} //namespace ResultType

struct TestValue
{
	int		as_int;
	float	as_float;
	std::string as_string;
    char    as_char;

	TestValue()
	{
		as_int      =0;
		as_float    =0;
		as_string   = "";
        as_char     =0;
	}

    TestValue(std::string s)
    {
        as_int      =0;
        as_float    =0;
        as_string   = s;
        as_char     =0;
    }

    TestValue(int i)
    {
        as_int =i;
        as_float = 0;
        as_string = "";
        as_char     =0;
    }

    TestValue(float f)
    {
        as_int =0;
        as_float = f;
        as_string = "";
        as_char     =0;
    }

    TestValue(char c)
    {
        as_int      =0;
        as_float    =0;
        as_string   ="";
        as_char     =c;
    }

	TestValue(const TestValue& other)
	{
		as_int = other.as_int;
		as_float = other.as_float;
		as_string = other.as_string;
        as_char = other.as_char;
	}
};



#endif /* TESTVALUE_H_ */
