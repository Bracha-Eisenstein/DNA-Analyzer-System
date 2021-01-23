#include "DNAWriter.h"
#include "../../model/dna/dna.h"
#include "../errors/open_file_error.h"
DNAWriter::DNAWriter(std::string name)
{
    name = "DnaFiles/" + name +".rawdna";
    myfile.open(name.c_str());
    if (!myfile.is_open())
	throw OpenFileError();
}
void DNAWriter::Write(const DnaSeq* other)
{
    for (size_t i = 0; i<other->len(); ++i)
	myfile << (other)[i];
}
DNAWriter::~DNAWriter()
{
    myfile.close();
}


