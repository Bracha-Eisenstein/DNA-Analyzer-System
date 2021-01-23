//
// Created by sari on 9/24/20.
//

#ifndef DNA_FIND_PARAMS_H
#define DNA_FIND_PARAMS_H
#include "../../../../model/dna_data/data.h"
#include "../../iparameters.h"
class FindParams: public IParameters
{
public:
    FindParams(Data*);
    /*virtual*/ void init(const std::vector<std::string>&);

    Data *m_data;
    DnaSeq* m_seqToFindIn;
    DnaSeq* m_seqToBeFound;

protected:
    /*virtual*/ void input_validation(const std::vector<std::string>&);
};

#endif //DNA_FIND_PARAMS_H
