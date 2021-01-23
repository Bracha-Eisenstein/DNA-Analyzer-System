#ifndef CODE_NEW_H
#define CODE_NEW_H

#include <string>
#include <iostream>
#include <vector>
#include "../../icommand.h"
#include "new_params.h"
class Data;

class New: public ICommand
{
public:
    New(){};
    /*virtual*/ std::string action(const IParameters&);
    /*virtual*/ std::string help();

};



#endif //CODE_NEW_H
