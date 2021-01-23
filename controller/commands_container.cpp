#include <iostream>
#include <fstream>
#include <utility>
#include "commands/iparameters.h"
#include "commands_container.h"
#include "commands/creation_commands/load/load.h"
#include "commands/icommand.h"
#include "commands/creation_commands/new/new.h"
#include "commands/creation_commands/load/load.h"
#include "commands/creation_commands/load/load_params.h"
#include "commands/management_commands/save/save.h"
#include "commands/control_commands/help/help.h"
#include "commands/manipulation_commands/slice/slice.h"
#include "commands/manipulation_commands/slice/slice_params.h"
#include "commands/analysis_commands/count/count.h"
#include "commands/analysis_commands/count/count_params.h"
#include "commands/analysis_commands/find/find.h"
#include "commands/analysis_commands/find/find_params.h"
#include "errors/command_not_found.h"

std::map<std::string,std::pair<ICommand*,IParameters*>> CommandsContainer::commands;

void CommandsContainer::init_commands(Data* dnaData)
{
    commands["new"] = std::pair<ICommand*,IParameters*>(new New, new NewParams(dnaData));
    commands["load"] = std::pair<ICommand*,IParameters*>(new Load, new LoadParams(dnaData));
    commands["slice"] = std::pair<ICommand*,IParameters*>(new Slice, new SliceParams(dnaData));
    commands["count"] = std::pair<ICommand*,IParameters*>(new Count, new CountParams(dnaData));
    commands["find"] = std::pair<ICommand*,IParameters*>(new Find, new FindParams(dnaData));
//	commands["save"] = new Save(dnaData);
//	commands["help"] = new Help;


}

std::pair<ICommand*,IParameters*> CommandsContainer::getCommand(std::string command)
{
	if (commands.find(command) == commands.end())
		throw CommandNotFound();
	return commands[command];

}

CommandsContainer::~CommandsContainer()
{
	for(std::map<std::string,std::pair<ICommand*,IParameters*> >::iterator it = commands.begin(); it != commands.end(); ++it)
	{
			delete it->second.first;
            delete it->second.second;
			it->second = std::pair<ICommand*,IParameters*> (NULL,NULL);
	}


}

std::string CommandsContainer::getCommandsList()
{
	std::string command_list;
	for(std::map<std::string,std::pair<ICommand*,IParameters*> >::iterator it = commands.begin(); it != commands.end(); ++it)
	{
			command_list+= it->first + "\n";			
	}
	return command_list;

}
