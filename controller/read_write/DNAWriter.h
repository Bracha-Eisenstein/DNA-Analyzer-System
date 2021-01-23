#ifndef DNA_DNAWRITERTXT_H
#define DNA_DNAWRITERTXT_H
#include <fstream>
#include "../../model/dna/dna.h"
	
class IDNA;
class DNAWriter
{
    public:
        DNAWriter(std::string);
        void Write(const DnaSeq*);
        ~DNAWriter();
    private:
        // composition
        std::ofstream myfile;
};
	
#endif
