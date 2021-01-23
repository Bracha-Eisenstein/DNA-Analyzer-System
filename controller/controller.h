#include <cstddef>
#include <iostream>
#include "../view/interface/iui.h"
#include "../model/dna_data/data.h"
#include "callback.h"

class Controller
{
public:
	Controller(Iui* cli,Data* dnaData);
	~Controller();
	void run();
	void start(){std::cout<<"start\n";}
	void exit(){std::cout<<"exit\n";}
private:
	Iui* m_ui;
	Data* m_dnaData;
	Callback* m_callback;

};












