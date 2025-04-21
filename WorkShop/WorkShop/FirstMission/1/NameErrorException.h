#pragma once
#include "InterpreterException.h"
#include <iostream>

class NameErrorException : public InterpreterException
{
public:
	virtual const char* what() const noexcept;
private:
	std::string _name;
};