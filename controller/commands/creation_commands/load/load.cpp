#include <sstream>
#include "../../../read_write/DNAReader.h"
#include "load.h"
#include "load_params.h"



std::string Load::action(const IParameters& parameters)
{
    const LoadParams& params = dynamic_cast<const LoadParams&>(parameters) ;
    DNAReader reader(params.m_file_name);
    std::string seq  = reader.read();
    params.m_data->NewDna(params.m_seq_name,seq);
    std::stringstream ss;
    ss << "["<<params.m_data->getByName(params.m_seq_name)->getId()<<"]  "<<params.m_seq_name<<": "<<seq;
    return ss.str();
}


std::string Load::help()
{
    return "load:\n Loads the sequence from the file\n"
           "<>: parameters []: optional parameters.\n"
           "load <file_name>  [@<sequence_name>]";
}
