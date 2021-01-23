#include "open_file_error.h"
const char* OpenFileError::what()
{
    return "Can't open this file";
}
