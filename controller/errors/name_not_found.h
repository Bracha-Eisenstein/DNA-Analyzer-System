#ifndef __NAME_NOT_FOUND_H__
#define __NAME_NOT_FOUND_H__
#include "dna_exceptions.h" 
class NameNotFound : public DnaExecption
{
public:
	 const char* what();
};

#endif //__NAME_NOT_FOUND_H__
