/*
 * MissingParameterException.h
 *
 *  Created on: May 8, 2012
 *      Author: tom
 */

#ifndef MISSINGPARAMETEREXCEPTION_H_
#define MISSINGPARAMETEREXCEPTION_H_

#include <TurnLeftLib/TurnLeft.h>
#include <exception>


namespace TurnLeft{
namespace Exceptions{

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
    MissingParameterException(const char* method, const char* parameter);

    /*! \return the Automatically generated error message for this exception. */
    const char* what() const throw();
};

}//namespace Exceptions
}//namespace TurnLeftLib
#endif /* MISSINGPARAMETEREXCEPTION_H_ */
