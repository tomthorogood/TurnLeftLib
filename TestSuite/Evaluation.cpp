/*
 * Evaluation.cpp
 *
 *  Created on: Sep 15, 2012
 *      Author: tom
 */

#include "Evaluation.h"
#include <stdlib.h>
#include <stdarg.h>
#include <iostream>

Evaluation::Evaluation (ResultType::type type, fn function)
{
	__type = type;
	__run = function;
    
}

Evaluation& Evaluation::run(size_t nargs, ...)
{
	va_list args;
	va_start(args, nargs);

	__result = __run(&args);

	va_end(args);
	return *this;
}
