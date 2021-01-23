#ifndef __OPEN_FILE_ERROR_H__
#define __OPEN_FILE_ERROR_H__
#include "dna_exceptions.h"
class OpenFileError : public DnaExecption
{
public:
    const char* what();
};

#endif
