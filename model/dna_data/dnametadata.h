#ifndef __DNAMETADATA_H__
#define __DNAMETADATA_H__
#include "../dna/dna.h"
#include "../../SharedPtr.h"
#include "../dna/idna.h"
class DnaMetaData
{
public:
	DnaMetaData(shared_ptr<IDna> seq, std::string name, size_t id);
    shared_ptr<IDna> getSharedDnaPtr();
    void decoratePtr(shared_ptr<IDna>);
	size_t getId();
	std::string getName();
	DnaSeq* getDna();
	
private:
	shared_ptr<IDna>  m_dna;
	std::string m_name;
	size_t m_id;
	
	
};

inline DnaMetaData::DnaMetaData(shared_ptr<IDna> seq, std::string name, size_t id):m_dna(seq),m_name(name),m_id(id)
{}

inline size_t DnaMetaData::getId()
{
	return m_id;
}

inline std::string DnaMetaData::getName()
{
	return m_name;
}


inline DnaSeq*  DnaMetaData::getDna()
{
	return (DnaSeq*)m_dna.get();
}

inline void DnaMetaData::decoratePtr(shared_ptr<IDna> ptr)
{
    m_dna = ptr;
}

inline shared_ptr<IDna> DnaMetaData::getSharedDnaPtr()
{
    return m_dna;
}
#endif


