/*
 * strings_test.cpp
 *
 *  Created on: Apr 19, 2012
 *      Author: tom
 */

#include "../test.h"
#include "../../utils/strings.h"
#include <vector>
#include <string>

int main()
{
    std::string testArray[5];
	unittest::Test<std::string> strtest;
	unittest::Test<int> inttest;
	std::string myString = "this is a test string";
	TurnLeft::Utils::Explosion explosion(myString);
	explosion.explode(' ').getArray(testArray);
	strtest.expect("this").test(testArray[0]);
    strtest.expect("is").test(testArray[1]);
    strtest.expect("a").test(testArray[2]);
    strtest.expect("test").test(testArray[3]);
    strtest.expect("string").test(testArray[4]);
	return 0;
}
