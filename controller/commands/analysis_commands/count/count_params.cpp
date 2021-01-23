//
// Created by sari on 9/24/20.
//

#include "count_params.h"
#include "../../../errors/invalid_command.h"
CountParams::CountParams(Data *data): m_data(data), m_seq_to_find_in(NULL), m_seq_to_be_found(NULL) {}

void CountParams::init(const std::vector<std::string> &args)
{
    input_validation(args);

    m_seq_to_find_in= m_data->getMetaData(args[1])->getDna();
    m_seq_to_be_found = m_data->getMetaData(args[2])->getDna();
}

void CountParams::input_validation(const std::vector<std::string> &args)
{
    if (args.size() != 3)
    {
        throw InvalidCommand();
    }
}