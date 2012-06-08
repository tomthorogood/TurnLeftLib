#include <TurnLeftLib/src/UnparseableEnumException.h>
TL_EXCEPTIONS_NAMESPACE

UnparseableEnumException::UnparseableEnumException(const std::string& value)
    : std::exception()
{
    std::string err = value;
    err.append(" is not a parseable enumerated type.");
    errMsg = err.c_str();
}

ECAPSEMAN_SNOITPECXE_LT
