#include <MissingParameterException.h>
TL_EXCEPTIONS_NAMESPACE

MissingParameterException::MissingParameterException (const char* method, const char* parameter)
:   exception()
{
    std::stringstream stream;
    stream << "[MISSING PARAMETER] in method " << method << ": " << parameter;
    errorMessage = stream.str().c_str();
}

inline const char* MissingParameterException::what() const throw()
{
    return this->errorMessage;
}

ECAPSEMAN_SNOITPECXE_LT
