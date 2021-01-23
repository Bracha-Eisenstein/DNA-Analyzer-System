#include "help.h"
#include "../commands_container.h"
#include "../errors/invalid_command.h"
std::string Help::action(IParameters* args)
{
//	if(args.size() > 2)
//		throw InvalidCommand();
//	if(args.size() == 1)
//		return CommandsContainer::getCommandsList();
//	ICommand* command = CommandsContainer::getCommand(args[1]);
//	return command -> help();
    return "";
}


std::string Help::help()
{
    return "help:\n If <command> is not provided, help lists all the available commands.\n"
           "If a valid command is provided, it shows a short explanation of it.\n"
           "<>: parameters []: optional parameters.\n"
           "help [<command>]";
}
