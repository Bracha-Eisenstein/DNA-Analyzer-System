//
// Created by sari on 9/22/20.
//

#include "callback.h"
#include "commands/icommand.h"
#include "commands_container.h"

std::string Callback::execute(std::vector<std::string>& parsed_input)const
{
    std::pair<ICommand*,IParameters*>command = CommandsContainer::getCommand(parsed_input[0]);
    command.second->init(parsed_input);
    std::string output_ = command.first -> action(*command.second);
    return output_;

}