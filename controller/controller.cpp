#include "controller.h"
#include "commands_container.h"
Controller::Controller(Iui* ui,Data* dnaData):m_ui(ui),m_dnaData(dnaData),m_callback(new Callback)
{
	
	CommandsContainer::init_commands(m_dnaData);
}

void Controller::run(){
    m_ui -> run(*m_callback);
}

Controller::~Controller()
{
    delete m_callback;
}
