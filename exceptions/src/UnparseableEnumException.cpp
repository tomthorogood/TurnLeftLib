#include <UnparseableEnumException.h>
TL_EXCEPTIONS_NAMESPACE

UnparseableEnumException::UnparseableEnumException(const std::string& value)
    : std::exception()
{
    std::string err = value;
    err.append(" is not a parseable enumerated type.");
    errMsg = err.c_str();
}

inline const char* UnparseableEnumException::what() const throw()
{
    return this->errMsg;
}

ECAPSEMAN_SNOITPECXE_LT
