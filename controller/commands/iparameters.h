//
// Created by sari on 9/21/20.
//

#ifndef DNA_IPARAMETERS_H
#define DNA_IPARAMETERS_H
#include <vector>
#include <string>

class IParameters
{
public:
    virtual ~IParameters(){}
    virtual void init(const std::vector<std::string>&)=0;

protected:
    virtual void input_validation(const std::vector<std::string>&)=0;
};
#endif //DNA_IPARAMETERS_H
