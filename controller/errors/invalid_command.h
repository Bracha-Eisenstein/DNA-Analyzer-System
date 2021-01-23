#ifndef __INVALID_COMMAND_H__
#define __INVALID_COMMAND_H__
#include "dna_exceptions.h"

class InvalidCommand: public DnaExecption
{
public:
    const char* what();
};




#endif //__INVALID_COMMAND__
