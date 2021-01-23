//
// Created by sari on 9/21/20.
//

#include "slice.h"
#include <sstream>

#include "../../../../model/dna_data/data.h"
#include "../../../../model/dna/dna_decorators/slice_decorator.h"
#include "../../../errors/invalid_command.h"
#include "slice_params.h"

std::string Slice::action(const IParameters& parameters)
{
    const SliceParams& params = dynamic_cast<const SliceParams&>(parameters) ;

   if (params.m_colon == NULL) {
       shared_ptr<IDna> d(new SliceDecorator(params.m_seq_data->getSharedDnaPtr(), params.m_start, params.m_end));
       params.m_seq_data->decoratePtr(d);
       std::cout << "hi";

         std::stringstream ss;
        ss << "[" << params.m_data->getByName(params.m_seq_data->getName())->getId() << "]  " << params.m_seq_data->getName() << ": " << (*params.m_seq_data->getDna()) << std::endl;
    return ss.str();
    }
   return "success slice";
}

std::string Slice::help()
{
    return "slice <seq> <from_ind> <to_ind> [: [@<new_seq_name>|@@]]";
}

