//
// Created by sari on 9/24/20.
//

#include "find_params.h"
#include "../../../errors/invalid_command.h"
FindParams::FindParams(Data *data): m_data(data), m_seqToFindIn(NULL), m_seqToBeFound(NULL) {}

void FindParams::init(const std::vector<std::string> &args)
{
    input_validation(args);

    m_seqToFindIn = m_data->getMetaData(args[1])->getDna();
    m_seqToBeFound = m_data->getMetaData(args[2])->getDna();
}

void FindParams::input_validation(const std::vector<std::string> &args)
{
    if (args.size() != 3)
    {
        throw InvalidCommand();
    }
}