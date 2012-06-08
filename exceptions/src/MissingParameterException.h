/*
 * MissingParameterException.h
 *
 *  Created on: May 8, 2012
 *      Author: tom
 */

#ifndef MISSINGPARAMETEREXCEPTION_H_
#define MISSINGPARAMETEREXCEPTION_H_

#include "exc_config.h"
#include <exception>
#include <string>
#include <sstream>

TL_EXCEPTIONS_NAMESPACE

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
    inline const char* what() const throw()
    {
        return this->errorMessage;
    }
};

ECAPSEMAN_SNOITPECXE_LT
#endif /* MISSINGPARAMETEREXCEPTION_H_ */
