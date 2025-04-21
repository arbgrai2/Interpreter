#include "Integer.h"
#include <sstream>
#include "Helper.h"

Integer::Integer(int integer) : Type(), value(integer)
{
}

bool Integer::isPrintable() const
{
    return true;
}

std::string Integer::toString() const
{
    return std::to_string(value);
}
