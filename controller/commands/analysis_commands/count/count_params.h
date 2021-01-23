//
// Created by sari on 9/24/20.
//

#ifndef DNA_COUNT_PARAMS_H
#define DNA_COUNT_PARAMS_H
#include "../../../../model/dna_data/data.h"
#include "../../iparameters.h"
class CountParams: public IParameters
{
public:
    CountParams(Data*);
    /*virtual*/ void init(const std::vector<std::string>&);

    Data *m_data;
    DnaSeq* m_seq_to_find_in;
    DnaSeq* m_seq_to_be_found;

protected:
    /*virtual*/ void input_validation(const std::vector<std::string>&);

};
#endif //DNA_COUNT_PARAMS_H
