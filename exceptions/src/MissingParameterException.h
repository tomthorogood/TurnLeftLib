/*
 * MissingParameterException.h
 *
 *  Created on: May 8, 2012
 *      Author: tom
 */

#ifndef MISSINGPARAMETEREXCEPTION_H_
#define MISSINGPARAMETEREXCEPTION_H_

#include <exception>

namespace TurnLeft{
namespace  Exceptions{

class MissingParameterException : public std::exception
{
private:
    const char* errorMessage;
public:
    MissingParameterException (const char* method, const char* parameter)
    :   exception()
    {
        std::stringstream stream;
        stream << "[MISSING PARAMETER] in method " << method << ": " << parameter;
        errorMessage = stream.str().c_str();
    }
    const char* what() const throw()
    {
        return this->errorMessage;
    }
};

}
}


#endif /* MISSINGPARAMETEREXCEPTION_H_ */
