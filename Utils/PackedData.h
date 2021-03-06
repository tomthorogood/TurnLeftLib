#ifndef PACKED_DATA_H_
#define PACKED_DATA_H_

namespace TurnLeft
{
namespace Utils
{
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

}//namespace Utils
}//namespace TurnLeft
#endif /*PACKED_DATA_H_ */
