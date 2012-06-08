#ifndef PACKED_DATA_H_
#define PACKED_DATA_H_

#include "utils_config.h"

TL_UTILS_NAMESPACE

template <typename T>
class PackedData {
private:
    T flags;
public:
    PackedData() 
    {
        flags = 0;
    }

    PackedData(T init)
    {
        flags = init;
    }

    inline bool isset (int mask)
    {
        return flags & mask == mask;
    }

    inline void set (int bit)
    {
        flags |= bit;
    }

    inline void unset (int bit)
    {
        flags -= bit;
    }

    inline T value ()
    {
        return flags;
    }

    inline bool operator== (const T& other)
    {
        return other == flags;
    }

    inline bool operator== (const PackedData<T>& other)
    {
        return other == flags;
    }
};

ECAPSEMAN_SLITU_LT
#endif /*PACKED_DATA_H_ */
