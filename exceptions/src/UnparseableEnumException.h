

#ifndef TL_EXCEPTIONS_UNPARSEABLE_ENUM_H_
#define TL_EXCEPTIONS_UNPARSEABLE_ENUM_H_

#include <exception>
namespace TurnLeft{
namespace Exceptions{

class UnparseableEnumException : public std::exception
{
private:
    const char* errMsg;
public:
    UnparseableEnumException(const std::string& value)
        : exception()
    {
        std::string err = value;
        err.append(" is not a parseable enumerated type.");
        errMsg = err.c_str();
    }

    const char* what() const throw()
    {
        return this->errMsg;
    }
};

}}

#endif
