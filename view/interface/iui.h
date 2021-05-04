//
// Created by sari on 9/21/20.
//

#ifndef DNA_IUI_H
#define DNA_IUI_H
#include "../../controller/callback.h"
class Iui
{
public:
    Iui(){}
    virtual std::string input() = 0;
    virtual void output(std::string) = 0;
    virtual void run(const Callback& callback)=0;
};
#endif //DNA_IUI_H
