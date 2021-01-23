//
// Created by sari on 9/24/20.
//

#ifndef DNA_FIND_H
#define DNA_FIND_H
#include "../../icommand.h"

class Find: public ICommand
{
public:
    /*virtual*/ std::string action(const IParameters&);
    /*virtual*/ std::string help();
};
#endif //DNA_FIND_H
