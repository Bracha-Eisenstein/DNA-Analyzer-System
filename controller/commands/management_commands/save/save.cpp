
#include "save.h"
#include "../read_write/DNAWriter.h"
#include "../errors/invalid_command.h"
Save::Save(Data *data) :m_data(data){}

std::string Save::action(IParameters* args)
{
//    if (args.size() != 2)
//        throw InvalidCommand();
//
//    DnaMetaData *metaData = m_data->getMetaData(args[1]);
//    DNAWriter writer(metaData->getName());
//    writer.Write(metaData->getDna());
//
   return "Saved completly";
}

std::string Save::help()
{
    return "save:\n Saves sequence <seq> to a file\n"
           "<>: parameters []: optional parameters.\n"
           "save <seq> [<filename>]";
}
