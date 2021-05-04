#ifndef _IDNA_H__
#define _IDNA_H__
#include "Nucleotide.h"
#include <cstddef>
class IDna
{
public:
	virtual ~IDna(){}
	virtual const Nucleotide& operator[](size_t) const = 0;
	virtual Nucleotide& operator[](size_t) = 0;
    virtual size_t len() const = 0;
};

#endif //_IDNA_H__

