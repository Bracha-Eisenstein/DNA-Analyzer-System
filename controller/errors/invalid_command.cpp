#include "invalid_command.h"
const char* InvalidCommand::what()
{
    return "Invalid command.\nYou can type help to know about this command.";
}
