#include "NameErrorException.h"

const char* NameErrorException::what() const noexcept
{
	return "NameError : name " , NameErrorException::_name , " is not defined";
}