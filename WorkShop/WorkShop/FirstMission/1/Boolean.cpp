#include "Boolean.h"

Boolean::Boolean(bool boolean) : Type(), value(boolean)
{
}

bool Boolean::isPrintable() const
{
    return true;
}

std::string Boolean::toString() const
{
    return value == 1 ? "True" : "False";
}
