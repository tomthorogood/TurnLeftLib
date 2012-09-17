/*
 * Evaluation.h
 *
 *  Created on: Sep 15, 2012
 *      Author: tom
 */

#ifndef EVALUATION_H_
#define EVALUATION_H_

#include "TestValue.h"
#include <stdarg.h>
typedef TestValue (*fn)(va_list*);

class Evaluation
{
	ResultType::type __type;
	TestValue __result;
	TestValue (*__run)(va_list* args);
public:
	Evaluation(ResultType::type type, fn function);

	Evaluation& run(size_t nargs, ...);

	inline TestValue* getResult() {return &__result;}
	inline ResultType::type getResultType() { return __type;}

	virtual ~Evaluation() {};
};

/* Example Usage:
 *
 * TestValue foo(va_list* _args)
 * {
 * 	va_list args = *_args;
 * 	MyObject obj;
 * 	TestValue result;
 *
 * 	int i = va_arg(args, int);
 * 	int s = va_arg(args, std::string);
 * 	float r = obj.test_int_string(i, s);
 * 	result.float = r;
 * 	return result;
 * }
 *
 * Evaluation evaluation(ResultType::t_flt, &foo);
 * TestValue* result = evaluation.run(2, 5, "foo").getResult();
 * float flt_result1 = result->as_float;
 * result = evaluation.run(2,3,"bar").getResult();
 * float flt_result2 = result->as_float;
 *
 */


#endif /* EVALUATION_H_ */
