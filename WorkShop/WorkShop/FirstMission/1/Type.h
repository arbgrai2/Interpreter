#pragma once
#include <iostream>

class Type
{
public:
	Type();
	virtual ~Type();
	bool getIsTemp();
	void setIsTemp(bool isTemp);
	virtual bool isPrintable() const = 0;
	virtual std::string toString() const = 0;
private:
	bool _isTemp;
};
