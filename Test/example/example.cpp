/*
 * example.cpp
 *
 *  Created on: Sep 15, 2012
 *      Author: tom
 */

#include <TestSuite.h>
#include <iostream>
using namespace std;
using namespace ResultType;

/* One test will be able to test two different methods!
 * Any single test can test any methods so long as those methods take the
 * same argument types (or those that are castable) in the same order.
 * It's also possible to test methods who don't use all of the argument
 * types, provided the first two things are correct. The remainder will simply
 * be ignored.
 */
class PolyTest : public Test
{
public:
	PolyTest (
			string name,
			type t,
			TestValue* v,
			Evaluation* e)
	: Test(name, t, v, e){}

	bool run()
	{
		__result = *__evaluation->run(/*nargs*/ 1, /*arg*/ 10.0).getResult();
		return compareResults();
	}
};

/* Class forward declarations */
class Average;

/* Function declarations */
TestValue v_alpha(va_list* args);
TestValue v_beta(va_list* args);
string itoa(int);


int main()
{
	/* The evaluations take in a result type (int, float, string) and
	 * any method that returns a TestValue and takes a pointer to a va_list.
	 */
	Evaluation e_alpha(t_int, &v_alpha);
	Evaluation e_beta(t_str, &v_beta);

	/* Two test values are initalized to hold the results of the two tests. */
	TestValue ex_alpha;
	TestValue ex_beta;

	/* The values are set for the expected results. */
	ex_alpha.as_float = 10;
	ex_beta.as_string = "10";


	/* The tests themselves are instantiated, each taking a helpful name,
	 * a result type (t_flt, t_str, t_int), the expected result, and the
	 * evaluation.
	 */
	PolyTest t_alpha("Average::getResult", t_flt, &ex_alpha, &e_alpha);
	PolyTest t_beta("itoa()", t_str, &ex_beta, &e_beta);

	/* The test suite takes in any number of Test objects and when run,
	 * generates a report showing which methods passed and which ones failed.
	 */
	TestSuite suite;
	suite.add_test(&t_alpha);
	suite.add_test(&t_beta);
	suite.run();

	/* If you wish to automate tests, you can write the report() data to a file,
	 * and for less verbosity, you can test whether the percent passed is 100
	 * before doing so calling suite.getGrade(), thereby generating a report
	 * only if any test failed.
	 */
	cout << suite.report() << endl;
}

/* ==== Below are all the definitions for things declared above  ==== */

/* An example class that will be tested */
class Average
{
	double result;
public:
	Average(size_t nargs, double args[])
	{
		result =0;
		int sum =0;
		for (size_t i = 0; i < nargs; i++)
		{
			sum += args[i];
		}
		result = (double) sum / (double) nargs;
	}
	inline double getResult() { return result;}
};

/* One of the test value generating methods. This one instantiates an
 * Average object and tests against the parameters set by the tests run()
 * method.
 */
TestValue v_alpha(va_list* args)
{
	TestValue result;
	double a[1];
	a[0] = va_arg(args, double);

	Average avg(1, a);
	result.as_float = avg.getResult();
	return result;
}

/* Another test value generating method which behaves completely differently.
 * This one simply runs the args passed by the run() method of the test through
 * the itoa algorithm to ensure the output is as expected.
 */
TestValue v_beta(va_list* args)
{
	TestValue result;
	double arg = va_arg(args, double);
	int iarg = (int) arg;
	result.as_string = itoa(iarg);
	return result;
}

/* An example method. */
string itoa (int i)
{
	stringstream strm;
	strm << i;
	return strm.str();
}
