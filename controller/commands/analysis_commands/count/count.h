//
// Created by sari on 9/24/20.
//

#ifndef DNA_COUNT_H
#define DNA_COUNT_H
#include "../../icommand.h"

class Count: public ICommand
{
public:
    /*virtual*/ std::string action(const IParameters&);
    /*virtual*/ std::string help();
};
#endif //DNA_COUNT_H
