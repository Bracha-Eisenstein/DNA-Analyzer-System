#ifndef __COMMANDS_CONTAINER_H__
#define __COMMANDS_CONTAINER_H__
#include <list>
#include <map>
#include <string>
#include <memory>
#include <utility>
#include "commands/icommand.h"
#include "commands/iparameters.h"
#include "../model/dna_data/data.h"
class CommandsContainer
{
public:
	~CommandsContainer();
	static void init_commands(Data*);
	static std::pair<ICommand*,IParameters*> getCommand(std::string);
	static std::string getCommandsList();
private:
	static std::map<std::string,std::pair<ICommand*,IParameters*>> commands;

};

#endif
