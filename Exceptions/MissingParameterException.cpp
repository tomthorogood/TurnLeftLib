
#include <TurnLeftLib/TurnLeft.h>
#include <TurnLeftLib/Exceptions/MissingParameterException.h>

#include <string>
#include <sstream>
namespace TurnLeft{
namespace Exceptions{

using std::exception;

MissingParameterException::MissingParameterException (const char* method, const char* parameter)
:   exception()
{
    std::stringstream stream;
    stream << "[MISSING PARAMETER] in method " << method << ": " << parameter;
    std::string strm_str = stream.str();
    errorMessage = strm_str.c_str();
}

inline const char* MissingParameterException::what() const throw()
{
	return this->errorMessage;
}


}//namespace Exceptions
}//namespace TurnLeft
