/*
 * MissingParameterException.h
 *
 *  Created on: May 8, 2012
 *      Author: tom
 */

#ifndef MISSINGPARAMETEREXCEPTION_H_
#define MISSINGPARAMETEREXCEPTION_H_

#include <exception>
#include <string>
#include <sstream>

namespace TurnLeft{
namespace  Exceptions{

/*! \brief The MissingParameterException is thrown in the case of a typically optional
 * parameter being required based the arguments of another parameter.
 */
class MissingParameterException : public std::exception
{
private:
    const char* errorMessage;
public:
    /*! The constructor for the exception.
     * \param method The method which is throwing the error
     * \param parameter The parameter the method cannot find.
     */
    MissingParameterException (const char* method, const char* parameter)
    :   exception()
    {
        std::stringstream stream;
        stream << "[MISSING PARAMETER] in method " << method << ": " << parameter;
        errorMessage = stream.str().c_str();
    }

    /*! \return the Automatically generated error message for this exception. */
    const char* what() const throw()
    {
        return this->errorMessage;
    }
};

}
}


#endif /* MISSINGPARAMETEREXCEPTION_H_ */
