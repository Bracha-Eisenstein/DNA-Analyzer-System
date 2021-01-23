//
// Created by sari on 9/21/20.
//
#include "new_params.h"
#include "../../../errors/invalid_command.h"
void NewParams::init(const std::vector<std::string>& params)
{
    input_validation(params);
    m_seq = params[1];
    m_name = m_data -> getNameDnaByArgs(params);
}

void NewParams::input_validation(const std::vector<std::string>& params)
{
    if((params.size() != 2 && params.size() != 3) ||(params.size() == 3 && params[2][0]!= '@') )
        throw InvalidCommand();
}