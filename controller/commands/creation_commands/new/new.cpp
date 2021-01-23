#include <sstream>
#include "new.h"




std::string New::action(const IParameters& parameters)
{
        const NewParams& params = dynamic_cast<const NewParams&>(parameters) ;
        params.m_data->NewDna(params.m_name, params.m_seq);
        std::stringstream ss;
        ss << "["<<params.m_data->getByName(params.m_name)->getId()<<"]  "<<params.m_name<<": "<<params.m_seq;
        return ss.str();
}


std::string New::help()
{
    return "new:\n Creates a new sequence\n"
           "<>: parameters []: optional parameters.\n"
           "new <sequence> [@<sequence_name>]";
}


