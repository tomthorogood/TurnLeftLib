#include <MissingParameterException.h>
TL_EXCEPTIONS_NAMESPACE

MissingParameterException::MissingParameterException (const char* method, const char* parameter)
:   exception()
{
    std::stringstream stream;
    stream << "[MISSING PARAMETER] in method " << method << ": " << parameter;
    errorMessage = stream.str().c_str();
}


ECAPSEMAN_SNOITPECXE_LT
