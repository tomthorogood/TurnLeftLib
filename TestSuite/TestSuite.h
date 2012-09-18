/*
 * TestSuite.h
 *
 *  Created on: Sep 15, 2012
 *      Author: tom
 */

#ifndef TESTSUITE_H_
#define TESTSUITE_H_

#include "Test.h"
#include <vector>
#include <sstream>

class TestSuite
{
	std::vector <Test*> tests;
	std::vector <std::string> failures;
	std::stringstream __report;
	float percent_pass;
	float num_passed;
	float total_tests;
public:
	TestSuite(std::string _name="") : tests() {
		percent_pass =0;
		num_passed =0;
		total_tests =0;
        name = _name;
        if (name == "")
        {
            __report << "Test Suite " << this << std::endl;
        }
        else
        {
            __report << "Test Suite " << name << std::endl;
        }
	}
    std::string name;

	inline void add_test(Test* t) { tests.push_back(t); total_tests++;}

	inline void run()
	{
		__report << "Tests: " << std::endl;
		for (int t =0; t < total_tests; t++)
		{
			bool success = tests[t]->run();

			__report << "\t" << tests[t]->getName() << " expected ";

			switch(tests[t]->getType())
			{
			case ResultType::t_int:
				__report << tests[t]->getValue(EXPECTED).as_int;
				__report << ", got " << tests[t]->getValue(RESULT).as_int;
				break;

			case ResultType::t_str:
				__report << tests[t]->getValue(EXPECTED).as_string;
				__report << ", got " << tests[t]->getValue(RESULT).as_string;
				break;

			case ResultType::t_flt:
				__report << tests[t]->getValue(EXPECTED).as_float;
				__report << ", got " << tests[t]->getValue(RESULT).as_float;
				break;

            case ResultType::t_chr:
                __report << tests[t]->getValue(EXPECTED).as_char;
                __report << ", got " << tests[t]->getValue(RESULT).as_char;
                break;
			}
			__report << std::endl;

			if (success)
			{
				num_passed++;
			}
			else
			{
				failures.push_back(tests[t]->getName());
			}
		}
		__report << std::endl;
		percent_pass = (num_passed / total_tests) *100;
	}

	inline std::string report()
	{

		size_t sz = failures.size();

		__report << "Failed Tests: " << std::endl;

		for (size_t t =0; t < sz; t++)
		{
			__report << "\t" << failures[t] << std::endl;
		}
		__report << std::endl << percent_pass << "% passed." << std::endl;
		return __report.str();
	}

	inline float getGrade() { return percent_pass; }

	virtual ~TestSuite() {

	}
};


#endif /* TESTSUITE_H_ */
