/*
 * FileNotFondException.h
 *
 *  Created on: May 8, 2012
 *      Author: tom
 */

#include <exception>
#include <sstream>

#ifndef TL_EXCEPTIONS_FILENOTFONDEXCEPTION_H_
#define TL_EXCEPTIONS_FILENOTFONDEXCEPTION_H_

namespace TurnLeft {
namespace Exceptions {

class FileNotFoundException : public std::exception
{
    const char* errorMessage;
public:
    FileNotFoundException (const char* path)
    :   exception()
    {
        std::stringstream stream;
        stream << path << " could not be found!" << std::endl;
        errorMessage = stream.str().c_str();
    }
    const char* what() const throw()
    {
        return this->errorMessage;
    }
};

//////////////////////////
} // NAMESPACE EXCEPTIONS
} // NAMESPACE TURNLEFT
//////////////////////////

#endif /* FILENOTFONDEXCEPTION_H_ */
