//
// Created by sari on 9/22/20.
//

#ifndef DNA_LOAD_PARAMS_H
#define DNA_LOAD_PARAMS_H
#include <string>
#include <vector>
#include "../../../../model/dna_data/data.h"
#include "../../iparameters.h"
class LoadParams: public IParameters
{
public:
    LoadParams(Data*);
    std::string m_file_name;
    std::string m_seq_name;
    Data* m_data;
    /*virtual*/ void init(const std::vector<std::string>&);

private:
    /*virtual*/ void input_validation(const std::vector<std::string>&);
};

inline LoadParams::LoadParams(Data *data): m_file_name(""),m_seq_name(""),m_data(data) {}

#endif //DNA_LOAD_PARAMS_H
