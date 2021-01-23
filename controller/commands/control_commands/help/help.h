#ifndef __HELP_H__
#define __HELP_H__
#include "../../icommand.h"
#include "../../iparameters.h"
class Help: public ICommand
{
public:
	/*virtual*/ std::string action(IParameters*);
	/*virtual*/ std::string help();
};

#endif
