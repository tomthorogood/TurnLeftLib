/*
 * FileNotFondException.h
 *
 *  Created on: May 8, 2012
 *      Author: tom
 */

#ifndef TL_EXCEPTIONS_FILENOTFOUNDEXCEPTION_H_
#define TL_EXCEPTIONS_FILENOTFOUNDEXCEPTION_H_

#include <TurnLeftLib/TurnLeft.h>
#include <exception>


namespace TurnLeft {
/*! \brief The Exceptions namespace encompasses all types and classes within the 
 * TurnLeft namespace that name exceptions that are used in the Turn Left lib.
 */
namespace Exceptions {

/*! \brief The FileNotFoundException is a direct descendant of the std::exception
 * class. It is typically thrown when a module attempts to open a file for 
 * reading, but the is_open test fails.
 */
class FileNotFoundException : public std::exception
{
    /*! The error message is generated when this exception is thrown.
     */
    const char* errorMessage;
public:

    /*! When throwing a FileNotFoundException, the path of the file that
     * could not be found should be passed into the constructor to let the user
     * know exactly WHICH file couldn't be found.
     * \param path The filepath that could not be located.
     */
    FileNotFoundException (const char* path);

    /*! Implementation of the exception::what method that displays the
     * auto-generated error message.
     */
    const char* what() const throw();
};

}//namespace Exceptions
}//namespace TurnLeft

#endif /* FILENOTFONDEXCEPTION_H_ */
