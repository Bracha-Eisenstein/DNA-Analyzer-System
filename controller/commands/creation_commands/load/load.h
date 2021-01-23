#ifndef __LOAD_H__
#define __LOAD_H__
#include  "../../icommand.h"
#include "../../iparameters.h"
#include  "../../../../model/dna_data/data.h"

class Load:public ICommand
{
public:
	Load(){};
	/*virtual*/ std::string action(const IParameters&);
	/*virtual*/ std::string help();
private:
	Data* m_data;
	ICommand* m_create_dna;
};

#endif
