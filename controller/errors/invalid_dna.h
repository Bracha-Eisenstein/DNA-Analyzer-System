#ifndef _INVALID_DNA_H__
#define _INVALID_DNA_H__
#include "dna_exceptions.h" 

class InvalidDna : public DnaExecption
{
public:
    const char* what();
};

#endif
