//
// Created by sari on 9/24/20.
//

#include "count.h"

#include <sstream>
#include "count_params.h"


std::string Count::action(const IParameters& fatherArgs)
{
    const CountParams& args = dynamic_cast<const CountParams&>(fatherArgs);

    std::stringstream ss;
    size_t flag = args.m_seq_to_find_in->count(*args.m_seq_to_be_found);

    if (flag > 0)
        ss << flag;
    else
        ss << "Not Exist";

    return ss.str();
}

std::string Count::help()
{
    return "count: <seq_id> <sub_seq> return the number of instances of the sub-sequence within the larger sequence.\n";
}