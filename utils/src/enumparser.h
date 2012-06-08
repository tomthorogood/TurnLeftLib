/*
 * EnumParser.h
 *
 *  Created on: May 25, 2012
 *      Author: tom
 */

#ifndef TL_UTILS_ENUMPARSER_H_
#define TL_UTILS_ENUMPARSER_H_

#include "config.h"
#include <map>
#include <string>
#include <TurnLeftLib/Exceptions>

TL_UTILS_NAMESPACE

using Exceptions::UnparseableEnumException;

/*! The EnumParser is a simple class which takes an enumerated type as 
 * its template parameter. It is then possible to parse enumerated types
 * from strings, using the parse method.
 */
template <typename T>
class EnumParser
{
protected:
    /*! This is the map which will be used to parse strings. */
    std::map<std::string, T> enumMap;

public:
	EnumParser(){};
	virtual ~EnumParser(){};
    /*! Takes a constant reference to a string as its parameter,
     * returning an integer representing the enumerated type.
     */
    int parse(const std::string& value)
    {
        typedef typename std::map<std::string, T>::const_iterator IValue;
        IValue iValue =	enumMap.find(value);
        if (iValue == enumMap.end())
        {
            throw UnparseableEnumException(value);
        }
        return iValue->second;
    }

    /*! Takes a constant reference to a string as its paraemeter,
     * returning the enumerated value.
     */
    T parseEnum(const std::string& value)
    {
        typedef typename std::map<std::string, T>::const_iterator IValue;
        IValue iValue = enumMap.find(value);
        if (iValue == enumMap.end())
        {
            throw UnparseableEnumException(value);
        }
        return iValue->second;
    }
    
    /*! An aliased way to add things into the parser. 
     * Takes the enumerated value and the string representing it.
     */
    inline void add (T num, const std::string& value)
    {
        enumMap[value] = num;
    }
};

ECAPSEMAN_SLITU_LT
#endif /* TL_UTILS_ENUMPARSER_H_ */
