#ifndef __DATA_H__
#define __DATA_H__
#include <vector>
#include <map>
#include "dnametadata.h"
#include "../../controller/errors/name_not_found.h"

class Data
{
public:
	~Data();	
	DnaMetaData* getByName(std::string);
	DnaMetaData* getById(size_t);
	std::string getNameDnaByArgs(std::vector<std::string>);
    std::string getDefName();
	bool isSeqNameExist(std::string);
	DnaMetaData* getMetaData(std::string args);
	void NewDna(std::string name, std::string seq);	
	size_t getId();
	void setId();
private:
	std::string getNotExistsName(std::string);
	std::map<std::string,DnaMetaData*> m_names;
	std::map<size_t,DnaMetaData*> m_ids;
	static size_t m_id;
};

inline size_t Data::getId()
{
	return m_id;
}

inline void Data::setId()
{
	m_id++;
}

inline DnaMetaData* Data::getByName(std::string name)
{
	if(m_names.find(name) == m_names.end())
		throw NameNotFound();
	return m_names[name];
}

inline DnaMetaData* Data::getById(size_t id)
{
	return m_ids[id];
}
#endif
