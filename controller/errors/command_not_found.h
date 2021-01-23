
#ifndef CODE_COMMANDNOTFOUND_H
#define CODE_COMMANDNOTFOUND_H

#include "dna_exceptions.h"

class CommandNotFound: public DnaExecption
{
public:
    const char* what();
};




#endif //CODE_COMMANDNOTFOUND_H
