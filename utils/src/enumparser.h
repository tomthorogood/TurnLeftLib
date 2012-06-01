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

namespace TurnLeft{
namespace Utils{

template <typename T>
class EnumParser
{
protected:
    std::map<std::string, T> enumMap;
public:
	EnumParser(){};
	virtual ~EnumParser(){};
	T parse(const std::string& value)
	{
		typedef typename std::map<std::string, T>::const_iterator IValue;
		IValue iValue =	enumMap.find(value);
		return iValue->second;
	}
    void add (T num, const std::string& value)
    {
        enumMap[value] = num;
    }
};

}}
#endif /* TL_UTILS_ENUMPARSER_H_ */
