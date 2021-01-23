//
// Created by sari on 9/24/20.
//
#include <sstream>
#include "find.h"
#include "find.h"
#include "find_params.h"

std::string Find::action(const IParameters& fatherArgs)
{
    const FindParams& args = dynamic_cast<const FindParams&>(fatherArgs);

    std::stringstream ss;
    size_t flag = args.m_seqToFindIn->find(*args.m_seqToFindIn);
    if (flag < args.m_seqToFindIn->len())
        ss << flag + 1;
    else
        ss << "Not Exist";
    return ss.str();
}

std::string Find::help()
{
    return "find <seq name> <sub seq>.\n";
}