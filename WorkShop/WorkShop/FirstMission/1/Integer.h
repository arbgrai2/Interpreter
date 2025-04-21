#pragma once
#include "Type.h"

class Integer : public Type
{
public:
	Integer(int integer);
	bool isPrintable() const;
	std::string toString() const;
private:
	int value;
};