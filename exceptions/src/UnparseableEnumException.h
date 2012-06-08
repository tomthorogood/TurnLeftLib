#ifndef TL_EXCEPTIONS_UNPARSEABLE_ENUM_H_
#define TL_EXCEPTIONS_UNPARSEABLE_ENUM_H_

#include "exc_config.h"
#include <exception>
#include <string>

TL_EXCEPTIONS_NAMESPACE

using std::exception;

class UnparseableEnumException : public exception
{
private:
    const char* errMsg;

public:
    UnparseableEnumException (const std::string& value);
    inline const char* what() const throw()
    {
        return this->errMsg;
    }
};

ECAPSEMAN_SNOITPECXE_LT
#endif
