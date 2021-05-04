#include <iostream>
#include <vector>
#include "cli.h"
#include "../parser.h"
#include "../../controller/errors/dna_exceptions.h"
std::string Cli::input()
{
	std::cout << "cmd >>> ";
	std:: string command;
	std::getline (std::cin, command);
	return command;

}

void Cli::output(std::string output)
{
	std::cout << output << "\n";
}

void Cli::run(const Callback& callback)
{
    while(1)
    {
        try
        {
            std::string input_ = input();
            std::vector<std::string> parsed_input = Parser::parse(input_);
            if(parsed_input[0] == "exit")
                break;
            std::string output_ = callback.execute(parsed_input);
            output(output_);
        }
        catch(DnaExecption& err)
        {
            output(err.what());

        }
    }


}
