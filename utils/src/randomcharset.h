/* The RandomCharSet provides a way of generating random strings of characters. 
 * Part of the Turn Left C++ Lib.
 */

#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <string>
#include <time.h>

#ifndef TL_UTILS_RANDOMCHARSET_H_
#define TL_UTILS_RANDOMCHARSET_H_

namespace TurnLeft {
namespace Utils{

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
    char digit(int);

    /*! Generates a lowercase character between a-z.
     * \param num A number from the random set.
     * \return a lowercase alpha character.
     */
    char lower(int);

    /*! Generates an uppercase character between A-Z.
     * \param num A number from the random set.
     * \return an uppercase alpha character.
     */
    char upper(int);
public:
    /*! The default constructor will base the seed on the current time. */
    RandomCharSet();

    /*! The overloaded constructor will take an integer as a seed, which will
     * return the same output as the last time that seed and stringlength were
     * used.
     */
    RandomCharSet(int seed);

    /*! The generate method will return a string of random characters in 
     * the following pattern: [upper][digit][lower], repeated as many
     * times as is passed in. 
     * \param num The number of times a random pattern should be appended to
     * the string -- default is 1 (optional param).
     * \return A pseudorandom string of length (num)*3.
     */
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

std::string RandomCharSet::generate(int num=1)
{
    std::stringstream stream;
    for (int i = 0; i < num; i++)
    {
        stream << upper(rand()) << digit(rand()) << lower(rand());
    }
    return stream.str();
}

}} 
#endif
