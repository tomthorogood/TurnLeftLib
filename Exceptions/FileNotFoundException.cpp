#include <TurnLeftLib/Exceptions/FileNotFoundException.h>
#include <string>
#include <sstream>

namespace TurnLeft{
namespace Exceptions{

using std::exception;
using std::stringstream;
using std::endl;

FileNotFoundException::FileNotFoundException (const char* path)
    : exception()
{
    stringstream stream;
    stream << path << " could not be found!" << endl;
    std::string strm_str = stream.str();
    errorMessage = strm_str.c_str();
}

inline const char* FileNotFoundException::what() const throw()
{
	return this->errorMessage;
}

}//namespace Exceptions
}//namespace TurnLeft
