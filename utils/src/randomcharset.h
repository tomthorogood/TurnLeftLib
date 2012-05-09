#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <string>
#include <time.h>

#ifndef RANDOMCHARSET_H_
#define RANDOMCHARSET_H_

namespace TurnLeft
{namespace Utils{

class RandomCharSet
{
    char digit(int);
    char lower(int);
    char upper(int);
public:
    RandomCharSet();
    RandomCharSet(int seed);
    std::string generate();
    std::string generate(int);
};

RandomCharSet::RandomCharSet()
{
    srand( time(NULL) );
}

RandomCharSet::RandomCharSet(int seed)
{
    srand(seed);
}

char RandomCharSet::digit(int num)
{
    return (num%10)+48;
}

char RandomCharSet::lower(int num)
{
    return (num%26)+97;
}

char RandomCharSet::upper(int num)
{
    return (num%26)+65;
}

std::string RandomCharSet::generate()
{
    std::stringstream stream;
    stream << upper(rand()) << digit(rand()) << lower(rand());
    return stream.str();
}

std::string RandomCharSet::generate(int num)
{
    std::stringstream stream;
    for (int i = 0; i < num; i++)
    {
        stream << upper(rand()) << digit(rand()) << lower(rand());
    }
    return stream.str();
}

}} /*Utils/FinancialFirsts*/
#endif
