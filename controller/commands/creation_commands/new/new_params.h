//
// Created by sari on 9/21/20.
//

#ifndef DNA_NEW_PARAMS_H
#define DNA_NEW_PARAMS_H
#include <string>
#include <vector>
#include "../../iparameters.h"
#include "../../../../model/dna_data/data.h"
class NewParams: public IParameters
{
public:
    NewParams(Data*);
    std::string m_seq;
    std::string m_name;
    Data* m_data;
    void init(const std::vector<std::string>&);

private:
    /*virtual*/ void input_validation(const std::vector<std::string>&);
};

inline NewParams::NewParams(Data* data):m_seq(""),m_name(""),m_data(data){}

#endif //DNA_NEW_PARAMS_H
