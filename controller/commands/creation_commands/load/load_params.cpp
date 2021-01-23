//
// Created by sari on 9/22/20.
//

#include "load_params.h"
#include "../../../errors/invalid_command.h"

void LoadParams::init(const std::vector<std::string>& params)
{
    input_validation(params);
    m_file_name = params[1];
    m_seq_name = m_data -> getNameDnaByArgs(params);

}

void LoadParams::input_validation(const std::vector<std::string>& params)
{
        if((params.size() != 2 && params.size() != 3) ||(params.size() == 3 && params[2][0]!= '@') )
		    throw InvalidCommand();
}