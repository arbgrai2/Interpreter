#pragma once

#include "Sequence.h"

class String : public Sequence
{
public:
	String(std::string string);
	bool isPrintable() const;
	std::string toString() const;
private:
	std::string value;
};