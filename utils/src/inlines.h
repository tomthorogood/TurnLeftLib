#ifndef TL_UTILS_INLINES_H_
#define TL_UTILS_INLINES_H_

#include "utils_config.h"
#include <string>

TL_UTILS_NAMESPACE

inline void trimchar (std::string& str, const char& voip=' ')
{
    int lastGoodChar = str.find_last_not_of(voip);
    int firstGoodChar = str.find_first_not_of(voip);
    int lenToEnd = lastGoodChar - firstGoodChar + 1;
    str = str.substr(firstGoodChar,lenToEnd);
}

template <class T>
inline bool isset (const T& test, int mask)
{
    return test & mask == mask;
}

template <class T>
inline bool exor (const T& alpha, const T& beta, const T& value)
{
    return (
            (alpha == value && beta == value) 
            ||
            (alpha != value && beta != value)
           );
}

ECAPSEMAN_SLITU_LT

#endif
