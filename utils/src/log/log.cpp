/*
 * log.cpp
 *
 *  Created on: May 8, 2012
 *      Author: tom
 */

#include "log.h"
namespace TurnLeft{
namespace Utils{

Log::Log(DEBUG_LEVEL _level=CRITICAL, DEBUG_TYPE _type=COUT, const char* filename=0)
    :   output()
{
    level = _level;
    type = _type;
    if (_type==FILE && filename != 0)
    {
        output.open(filename);
    }
    else if (_type==FILE)
    {
        throw Exceptions::MissingParameterException("Log::Log()", "filename");
    }
}

Log::~Log()
{ } 
void
Log::log(const char* message, DEBUG_LEVEL _level=ANNOYING)
{
    /* For reference:
     *  0: Critical
     *  1: Warn
     *  2: Verbose
     *  3: Annoying
     */

    /* First, determine if we need to deal with this log.
     * If the log level is less than the message level,
     * don't bother.
     */
    if (_level <= level)
    {
        if (type == FILE)
        {
            output << message << "\n";
        }
        else
        {
            std::cout << message << std::endl;
        }
    }
}

DEBUG_LEVEL
Log::getLevel()
{
    return level;
}

DEBUG_TYPE
Log::getType()
{
    return type;
}

void
Log::setLevel(DEBUG_LEVEL _level)
{
    level = _level;
}

void
Log::setType(DEBUG_TYPE _type, const char* filename=0)
{
    type = _type;
    if (type == FILE && filename == 0)
    {
        throw Exceptions::MissingParameterException("Log::setType()", "filename");
    }
    else if (type == FILE)
    {
        output.open(filename);
    }
}


}}
