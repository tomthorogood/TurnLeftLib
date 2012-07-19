#include <TurnLeftLib/Exceptions/UnparseableEnumException.h>
#include <string>

namespace TurnLeft{
namespace Exceptions{
using std::exception;
UnparseableEnumException::UnparseableEnumException(const std::string& value)
    : std::exception()
{
    std::string err = value;
    err.append(" is not a parseable enumerated type.");
    errMsg = err.c_str();
}

}//namespace Exceptions
}//namespace TurnLeft
