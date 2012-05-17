/*! \file tlstring.h
 * A Turn Left implementation of a string. Works with a stringstream
 * to automatically concatenate and handle strings.
 */

#ifndef TL_UTILS_TLSTRING_H_
#define TL_UTILS_TLSTRING_H_

#include <sstream>
#include <string>

namespace TurnLeft{
namespace Utils{

class TLString
{
private:

    /*! Mostly, the TLString class will operate using a stringstream
     * buffer. Therefore, this is a key piece to be included...
     */
    std::stringstream stream;

public:
    /*! The TLString can be declared without any arguments, which
     * is just fine. It will default to the empty string.
     */
    TLString();

    /*! If a const char* is passed into the constructor, it will simply
     * be read into the stringstream and immediately become part of the string.
     */
    TLString(const char*);
    /*! If a std::string is passed into the constructor, it will simply
     * be read into the stringstream and immediately become part of the string.
     */
    TLString(std::string);
    /*! Returns a std::string representation of this object. */
    std::string str();

    /*! Sets this object to the empty string (equivalent to also doing:
     * TLStrObj = "";). Chainable.
     */
    TLString& clr();
    /*! Converts the entire string to lower case. Chainable.
     * \param keepNonAlpha If set to true, will not filter out non-alpha
     * characters. Default is false!*/
    TLString& toLower(bool);
    /*! Converts the entire string to upper case. Chainable.
     * \param keepNonAlpha If set to true, will filter out non-alpha
     * characters. Default is false! */
    TLString& toUpper(bool);
    /*! Removes any instance of the passed character from the string. Chainable
     * @param ch The character to be removed from the string
     */
    TLString& filter(char);

    TLString& operator+ (const char* rhs);
    TLString& operator+ (std::string rhs);
    TLString& operator+ (TLString& rhs);

    TLString& operator+= (const char* rhs);
    TLString& operator+= (std::string rhs);
    TLString& operator+= (TLString& rhs);

    TLString& operator<< (const char* rhs);
    TLString& operator<< (std::string rhs);
    TLString& operator<< (TLString& rhs);

    TLString& operator= (const char* rhs);
    TLString& operator= (std::string rhs);
    TLString& operator= (TLString& rhs);

};
}}

#endif
