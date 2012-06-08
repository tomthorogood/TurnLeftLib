#include <TurnLeftLib/src/FileNotFoundException.h>

TL_EXCEPTIONS_NAMESPACE

FileNotFoundException::FileNotFoundException (const char* path)
    : exception()
{
    std::stringstream stream;
    stream << path << " could not be found!" << std::endl;
    errorMessage = stream.str().c_str();
}


ECAPSEMAN_SNOITPECXE_LT
