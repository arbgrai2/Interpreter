#include "Parser.h"
#include "Parser.h"
#include "Parser.h"
#include "Parser.h"
#include "Parser.h"
#include "Parser.h"
#include <iostream>
#include "IndentationException.h"
#include "Void.h"
#include "String.h"
#include "Integer.h"
#include "Type.h"
#include "Boolean.h"
#include "SyntaxException.h"
#include "NameErrorException.h"


std::unordered_map<std::string, Type*> Parser::_variables = {};

Type* Parser::parseString(std::string str)
{
	if (str[0] == '\t' || str[0] == ' ')
	{
		throw IndentationException();
	}

	Type* type = getType(str);
	
	if (type != nullptr)
	{
		return type;
	}
	else
	{
		try
		{
		if (makeAssignment(str))
		{
			Void* voidV = new Void();
			return voidV;
		}
		else
		{
			std::cout << getVariableValue(str)->toString() << std::endl;
		}
		}
		catch (NameErrorException& e)
		{
			std::cout << e.what();
		}
	}
	return nullptr;
}

Type* Parser::getType(std::string str)
{
	Helper::trim(str);
	if (Helper::isInteger(str))
	{
		Integer* integer = new Integer(std::stoi(str));
		return integer;
	}
	else if (Helper::isString(str))
	{
		String* string = new String(str);
		return string;
	}
	else if (Helper::isBoolean(str))
	{
		Boolean* boolean = new Boolean(str == "False" ? 0 : 1);
		return boolean;
	}
	else
	{
		return nullptr;
	}
}

void Parser::clean()
{
	for (auto& it : _variables)
	{
		delete it.second;
	}
	_variables.clear();

}

bool Parser::isLegalVarName(std::string str)
{
	if (Helper::isDigit(str[0]))
	{
		return false;
	}
	for (int i = 0; i < str.length(); i++)
	{
		if (!Helper::isLetter(str[i]) && !Helper::isDigit(str[i]) && !Helper::isUnderscore(str[i]))
		{
			return false;
		}
	}
	return true;
}

bool Parser::makeAssignment(std::string str)
{

	std::string key = "";
	std::string second = "";
	if (str.find("=") != std::string::npos)
	{
		for (int i = 0; str[i] != '='; i++)
		{
			key += str[i];
		}

		int eqIndex = str.find("=");
		for (int i = eqIndex + 1; i < str.length(); i++)
		{
			second += str[i];
		}
		Type* value = parseString(second);
		_variables.insert({ key, value });
	}
	else
	{
		return false;
	}
	return true;
}

Type* Parser::getVariableValue(std::string str)
{
	for (auto& key : _variables)
	{
		if (key.first == str)
		{
			return key.second;
		}
	}
	return nullptr;
}

void Parser::copy(std::string str)
{
	std::string key = "";
	std::string second = "";
	if (str.find("=") != std::string::npos)
	{
		for (int i = 0; str[i] != '='; i++)
		{
			key += str[i];
		}

		int eqIndex = str.find("=");
		for (int i = eqIndex + 1; i < str.length(); i++)
		{
			second += str[i];
		}
		Type* value = parseString(second);
		_variables.insert({ key, value });
	}
	if (getVariableValue(second) != nullptr)
	{
		Type* type = parseString(second);
		std::string src = type->toString();
		src = second;
		
	}
	_variables.insert({});
}

