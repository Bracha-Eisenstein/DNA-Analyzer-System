#ifndef __CLI_H__
#define __CLI_H__
#include <string>
#include "iui.h"
#include "../../controller/callback.h"
class Cli : public Iui
{
public:
	Cli(){}
	/*virtual*/ std::string input();
	/*virtual */ void output(std::string);
    /*virtual */ void run(const Callback& callback);


};
#endif
