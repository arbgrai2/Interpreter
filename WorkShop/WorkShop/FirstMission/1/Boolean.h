#pragma once
#include "Type.h"

class Boolean : public Type
{
public:
	Boolean(bool boolean);
	bool isPrintable() const;
	std::string toString() const;
private:
	int value;
};