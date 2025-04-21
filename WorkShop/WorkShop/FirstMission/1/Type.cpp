#include "Type.h"

Type::Type() : _isTemp(false)
{
}

Type::~Type() = default;

bool Type::getIsTemp()
{
	return _isTemp;
}

void Type::setIsTemp(bool isTemp)
{
	_isTemp = isTemp;

}
