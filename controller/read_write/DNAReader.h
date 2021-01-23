#ifndef CODE_DNAREADER_H
#define CODE_DNAREADER_H
#include <fstream>
class DNA;

class DNAReader
{
public:
    DNAReader(std::string name);
    std::string read();
    ~DNAReader();
private:
    std::ifstream myfile;
};


#endif //CODE_DNAREADER_H
