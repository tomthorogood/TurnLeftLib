/* The RandomCharSet provides a way of generating random strings of characters. 
 * Part of the Turn Left C++ Lib.
 */

#ifndef TL_UTILS_RANDOMCHARSET_H_
#define TL_UTILS_RANDOMCHARSET_H_

#include "utils_config.h"
#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <string>
#include <time.h>

TL_UTILS_NAMESPACE

/*! \brief This class provides a simple way of generating random strings of characters.
 * It can also take a constant seed as a parameter, allowing access to previous
 * random strings that were generated.
 */
class RandomCharSet
{
    /*! Generates a digit between 0-9.
     * \param num A number from the random set.
     * \return A digit between 0 and 9.
     */
    inline char digit(int num)
    {
        return (num%10)+48;
    }

    /*! Generates a lowercase character between a-z.
     * \param num A number from the random set.
     * \return a lowercase alpha character.
     */
    inline char lower(int num)
    {
        return (num%26)+97;
    }

    /*! Generates an uppercase character between A-Z.
     * \param num A number from the random set.
     * \return an uppercase alpha character.
     */
    inline char upper(int num)
    {
        return (num%26)+65;
    }
public:
    /*! The default constructor will base the seed on the current time. */
    RandomCharSet()
    {
        srand( time(NULL) );
    }

    /*! The overloaded constructor will take an integer as a seed, which will
     * return the same output as the last time that seed and stringlength were
     * used.
     */
    RandomCharSet(int seed)
    {
        srand(seed);
    }

    /*! The generate method will return a string of random characters in 
     * the following pattern: [upper][digit][lower], repeated as many
     * times as is passed in. 
     * \param num The number of times a random pattern should be appended to
     * the string -- default is 1 (optional param).
     * \return A pseudorandom string of length (num)*3.
     */
    inline std::string generate(int num)
    {
        std::stringstream stream;
        for (int i = 0; i < num; i++)
        {
            stream << upper(rand()) << digit(rand()) << lower(rand());
        }
        return stream.str();
    }
};

ECAPSEMAN_SLITU_LT
#endif
