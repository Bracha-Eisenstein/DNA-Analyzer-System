//
// Created by sari on 9/22/20.
//

#ifndef DNA_SLICE_PARAMS_H
#define DNA_SLICE_PARAMS_H
#include "../../iparameters.h"
#include "../../../../model/dna_data/data.h"
#include "../../../../model/dna_data/dnametadata.h"
#include "../with_colon.h"
class SliceParams : public IParameters
{
public:
    SliceParams(Data*);
    Data* m_data;
    DnaMetaData* m_seq_data;
    size_t m_start;
    size_t m_end;
    WithColon* m_colon;
    /*virtual*/ void init(const std::vector<std::string>&);

private:
    /*virtual*/ void input_validation(const std::vector<std::string>&);
};
inline SliceParams::SliceParams(Data *data):m_data(data),m_seq_data(NULL),m_start(0),m_end(0),m_colon(NULL) {}
#endif //DNA_SLICE_PARAMS_H
