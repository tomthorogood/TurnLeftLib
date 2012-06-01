#include <string>

#ifndef TL_UTILS_INLINES_H_
#define TL_UTILS_INLINES_H_

namespace TurnLeft{
namespace Utils{
inline void trimchar (std::string& str, const char& voip=' ')
{
    int lastGoodChar = str.find_last_not_of(voip);
    int firstGoodChar = str.find_first_not_of(voip);
    int lenToEnd = lastGoodChar - firstGoodChar + 1;
    str = str.substr(firstGoodChar,lenToEnd);
}

}}

#endif
