#ifndef __SAVE_H__
#define __SAVE_H__
#include "../../icommand.h"
#include  "../../../../model/dna_data/data.h"

class Save:public ICommand
{
public:
	Save(Data*);
	/*virtual*/ std::string action(IParameters*);
	/*virtual*/ std::string help();
private:
	Data* m_data;
};

#endif

