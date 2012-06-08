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

ECAPSEMAN_SLITU_LT
