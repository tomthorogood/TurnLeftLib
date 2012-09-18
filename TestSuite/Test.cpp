/*
 * Test.cpp
 *
 *  Created on: Sep 15, 2012
 *      Author: tom
 */

#include <Test.h>
Test::Test(
		std::string name
		,ResultType::type type
		,TestValue* expected
		,Evaluation* evaluation)
: __expect(*expected), __result()
{
	__evaluation = evaluation;
	__type = type;
	__name = name;
}
