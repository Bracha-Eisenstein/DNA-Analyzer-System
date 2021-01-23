#ifndef __ICOMMAND_H__
#define __ICOMMAND_H__
#include <string>
#include <vector>
#include "iparameters.h"
class ICommand
{
public:
	virtual ~ICommand(){}
	virtual std::string action(const IParameters&)=0;
	virtual std::string help()=0;

};
#endif
