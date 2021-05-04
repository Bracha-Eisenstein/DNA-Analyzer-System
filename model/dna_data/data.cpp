#include <sstream>
#include "data.h"
#include "../../controller/errors/invalid_command.h"

size_t Data:: m_id = 0;

void Data::NewDna(std::string name, std::string seq)
{
	shared_ptr<IDna> dna_seq(new DnaSeq(seq));
	DnaMetaData* new_seq = new DnaMetaData(dna_seq,name,m_id);
	m_names[name] = new_seq;
	m_ids[m_id] = new_seq;
	setId();
}

std::string Data::getNameDnaByArgs(std::vector<std::string> args)
{
	if(args.size() == 3)
		return getNotExistsName(args[2].erase(0,1));
	else
	{
        return getDefName();
	}
}

std::string Data::getDefName()
{
    std::stringstream str;
    str << "def_seq_" << getId();
    return getNotExistsName(str.str());
}
bool Data::isSeqNameExist(std::string name)
{
	if(m_names.find(name) == m_names.end())
	{
		return false;
	}
	return true;
}

Data::~Data()
{
	for(std::map<std::string,DnaMetaData*>::iterator it = m_names.begin(); it != m_names.end(); ++it)
	{
		m_ids.erase(it->second->getId());
		delete it->second;
		it->second = NULL; 		
	}
	

}

std::string Data::getNotExistsName(std::string name)
{
	int counter = 0;
	std::string new_name = name;
	while(m_names.find(new_name)!= m_names.end())
	{
		std::stringstream str;
		str << new_name<< "_" << counter;
		counter++;
		new_name = str.str();
	}
	return new_name;
}


DnaMetaData* Data::getMetaData(std::string args)
{
    if ((args[0]) == '@')
        return getByName(args.erase(0, 1));
        
    if ((args[0]) == '#')
        return getById(size_t(std::atoi(args.erase(0, 1).c_str())));
    throw InvalidCommand();
}




