#ifndef __DNA_EXCEPTION_H_
#define __DNA_EXCEPTION_H_
#include <exception>

class DnaExecption :public std::exception
{
public:
	DnaExecption(){}
	virtual const char* what()=0;
	/*virtual*/// ~DnaExecption(){}
};

#endif
