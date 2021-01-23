#include <iostream>
#include "DNAReader.h"
#include "../errors/open_file_error.h"
DNAReader::DNAReader(std::string name)
{
	
    name = "DnaFiles/" + name + ".rawdna";
    myfile.open(name.c_str());

    if (!myfile.is_open())
        throw OpenFileError();
}
std::string  DNAReader::read()
{
    myfile.seekg (0, std::ios::end);
    int length = myfile.tellg();
    myfile.seekg(0);
    char *output = new char[length+1];
    while (!myfile.eof()) {
        myfile >> output;
    }
    return output;
}
DNAReader::~DNAReader()
{
    myfile.close();
}
