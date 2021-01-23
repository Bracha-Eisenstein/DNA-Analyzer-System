//
// Created by sari on 9/22/20.
//

#include "slice_params.h"
#include "../../../errors/invalid_command.h"

void SliceParams::init(const std::vector<std::string>& params)
{
    input_validation(params);
    delete m_colon;
    m_seq_data = m_data ->getMetaData(params[1]);
    m_start = size_t(std::atoi(params[2].c_str()));
    m_end = size_t(std::atoi(params[3].c_str()));
    if(params.size() == 6)
    {
        m_colon = new WithColon(params[5]);
    }
    else if(params.size() == 5)
        m_colon = new WithColon(m_data->getDefName());
    else
        m_colon = NULL;
}

void SliceParams::input_validation(const std::vector<std::string>& params)
{
        if (params.size() < 4 || params.size() > 6 || (params.size() > 4 && params[4] != ":"))
            throw InvalidCommand();
}