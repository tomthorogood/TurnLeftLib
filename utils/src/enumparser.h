/*
 * EnumParser.h
 *
 *  Created on: May 25, 2012
 *      Author: tom
 */

#ifndef TL_UTILS_ENUMPARSER_H_
#define TL_UTILSENUMPARSER_H_

#include <map>
#include <string>

#include <Exceptions>

namespace TurnLeft{
namespace Utils{

using Exceptions::UnparseableEnumException;

template <typename T>
class EnumParser
{
protected:
    std::map<std::string, T> enumMap;
public:
	EnumParser(){};
	virtual ~EnumParser(){};
    int parse(const std::string& value);
    void add (T num, const std::string& value)
    {
        enumMap[value] = num;
    }
};

template <typename T>
int EnumParser <T>::parse(const std::string& value)
{
    typedef typename std::map<std::string, T>::const_iterator IValue;
    IValue iValue =	enumMap.find(value);
    if (iValue == enumMap.end())
    {
        throw UnparseableEnumException(value);
    }
    return iValue->second;
}

}}
#endif /* TL_UTILS_ENUMPARSER_H_ */
