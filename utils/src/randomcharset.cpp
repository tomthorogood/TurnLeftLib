#include <randomcharset.h>

TL_UTILS_NAMESPACE

RandomCharSet::RandomCharSet()
{
    srand( time(NULL) );
}

RandomCharSet::RandomCharSet(int seed)
{
    srand(seed);
}

inline char RandomCharSet::digit(int num)
{
    return (num%10)+48;
}

inline char RandomCharSet::lower(int num)
{
    return (num%26)+97;
}

inline char RandomCharSet::upper(int num)
{
    return (num%26)+65;
}

inline std::string RandomCharSet::generate(int num=1)
{
    std::stringstream stream;
    for (int i = 0; i < num; i++)
    {
        stream << upper(rand()) << digit(rand()) << lower(rand());
    }
    return stream.str();
}

ECAPSEMAN_SLITU_LT
