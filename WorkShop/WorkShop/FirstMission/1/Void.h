#pragma once

#include "Type.h"

class Void : public Type
{
public:
	Void(void);
	bool isPrintable() const;
	std::string toString() const;
};