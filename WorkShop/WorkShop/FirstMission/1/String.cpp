#include "String.h"

String::String(std::string string) : Sequence(), value(string)
{
}

bool String::isPrintable() const
{
    return true;
}

std::string String::toString() const
{
    return value; // need to return this with '' and not "" always
}
