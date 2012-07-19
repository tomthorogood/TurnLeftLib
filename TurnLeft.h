/*
 * TurnLeftLib_Forward.h
 *
 *  Created on: Jul 17, 2012
 *      Author: tom
 */

#ifndef TURNLEFTLIB_FORWARD_H_
#define TURNLEFTLIB_FORWARD_H_


#include <TurnLeftLib/Utils/HungryVector.h>
#include <TurnLeftLib/Utils/PackedData.h>
#include <TurnLeftLib/Utils/PtrArray.h>
namespace TurnLeft
{
	namespace Utils
	{
		typedef unsigned char* CharArray;
		typedef const char* c_str;

		class CommonWords;
		class Explosion;
		class Log;
		class RandomCharSet;
		class WordAggregator;
	}

	namespace Exceptions
	{
		class FileNotFoundException;
		class UnparseableEnumException;
		class MissingParameterException;
	}
}



#endif /* TURNLEFTLIB_FORWARD_H_ */
