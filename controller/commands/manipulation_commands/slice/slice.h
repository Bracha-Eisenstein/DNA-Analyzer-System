//
// Created by sari on 9/21/20.
//

#ifndef DNA_SLICE_H
#define DNA_SLICE_H
#include "../../icommand.h"

class Data;

class Slice: public ICommand
{
public:
    Slice(){};
    /*virtual*/ std::string action(const IParameters&);
    /*virtual*/ std::string help();

};
#endif //DNA_SLICE_H
