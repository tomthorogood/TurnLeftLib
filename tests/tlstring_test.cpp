/*
 * tlstring_test.cpp
 *
 *  Created on: May 17, 2012
 *      Author: tom
 */


#include <TurnLeftLib/utils/TLString>
#include <TurnLeftLib/utils/test.h>


int main()
{
	unittest::Test <std::string> strtest;

	TurnLeft::Utils::TLString str1;
	TurnLeft::Utils::TLString str2("Allons-y!");
	TurnLeft::Utils::TLString str3("Exterminate.");

	strtest.name("str()").expect("Allons-y!").test( str2.str() );
	strtest.name("str()").expect("Exterminate.").test(str3.str());

	str1 = str2;
	str1 = str2 + str3;
	strtest.name("op=,op+,str()").expect("Allons-y!Exterminate.").test(str1.str());
	strtest.name("tolower()").expect("allonsyexterminate").test(str1.toLower().str());
	strtest.name("toupper(true)").expect("ALLONS-Y!").test( str2.toUpper(true).str());
	strtest.name("filter('e')").expect("allonsyxtrminat").test( str1.filter('e').str());
}
