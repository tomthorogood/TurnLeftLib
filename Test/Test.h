/*
 * Test.h
 *
 *  Created on: Sep 15, 2012
 *      Author: tom
 */

#ifndef TEST_H_
#define TEST_H_
#include <string>

#include "TestValue.h"
#include "Evaluation.h"
enum ValueType
{
	EXPECTED,
	RESULT
};
class Test
{
private:
	TestValue 			__expect;
	ResultType::type 	__type;

	std::string __name;

protected:
	Evaluation* __evaluation;
	TestValue	__result;
	inline bool compareResults()
	{
		switch(__type)
		{
		case ResultType::t_int:
			return __expect.as_int == __result.as_int;
		case ResultType::t_str:
			return __expect.as_string == __result.as_string;
		case ResultType::t_flt:
			return __expect.as_float == __result.as_float;
		}
		return false;
	}

public:
	Test (std::string name, ResultType::type,TestValue*,Evaluation*);
	virtual ~Test(){}
	virtual bool run () =0;
	inline std::string getName() { return __name;}
	inline TestValue getValue(ValueType type) {
		if (type == EXPECTED) return __expect;
		return __result;
	}
	inline ResultType::type getType() { return __type;}
};

/* Example Usage:
 *
 * class FooTest : public Test
 * {
 * 		bool run()
 * 		{
 *			__result = *__evaluation->run(2, 3, "foo").getResult();
 *			return compareResults();
 * 		}
 * }
 *
 * TestValue expect;
 * expect.as_float(3.0);
 * FooTest test1(&expect, &myEvaluation);
 * bool success = test.run();
 *
 */



#endif /* TEST_H_ */
