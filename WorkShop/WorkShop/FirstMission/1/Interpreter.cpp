#include "Type.h"
#include "InterpreterException.h"
#include "Parser.h"
#include <iostream>
#include "IndentationException.h"
#include "SyntaxException.h"

#define WELCOME "Welcome to Magshimim Python Interperter version 1.0 by "
#define YOUR_NAME "Arbel Graiver"

int main(int argc,char **argv)
{
	std::cout << WELCOME << YOUR_NAME << std::endl;

	std::string input_string;
	// get new command from user
	try
	{
		std::cout << ">>> ";
		std::getline(std::cin, input_string);
		Helper::trim(input_string);

	}
	catch (SyntaxException& e)
	{
		std::cout << e.what();
	}
	while (input_string != "quit()")
	{
		Helper::trim(input_string);
		try
		{
			Type* type = Parser::getType(input_string);
			
			// parsing command
			try
			{
				type = Parser::parseString(input_string);
				
			}
			catch (IndentationException& e)
			{
				std::cout << e.what() << std::endl;
			}
			if (type != nullptr)
			{
				if (type->isPrintable())
				{
					std::cout << type->toString() << std::endl;
				}
			}
		}
		catch (SyntaxException& e)
		{
			std::cout << e.what() << std::endl;
		}
		// get new command from user
		std::cout << ">>> ";
		std::getline(std::cin, input_string);
	}

	return 0;
}
