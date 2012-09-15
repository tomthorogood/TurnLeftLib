/*
 * TestValue.h
 *
 *  Created on: Sep 15, 2012
 *      Author: tom
 */

#ifndef TESTVALUE_H_
#define TESTVALUE_H_

#include <string>

namespace ResultType{
enum type {
	t_int	=0
	,t_flt	=1
	,t_str  =2
};
} //namespace ResultType

struct TestValue
{
	int		as_int;
	float	as_float;
	std::string as_string;

	TestValue()
	{
		as_int =0;
		as_float =0;
		as_string = "";
	}

	TestValue(const TestValue& other)
	{
		as_int = other.as_int;
		as_float = other.as_float;
		as_string = other.as_string;
	}
};



#endif /* TESTVALUE_H_ */
