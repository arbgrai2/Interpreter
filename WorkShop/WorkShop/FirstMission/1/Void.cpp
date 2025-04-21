#include "Void.h"

Void::Void(void) : Type()
{
}

bool Void::isPrintable() const
{
    return false;
}

std::string Void::toString() const
{
    return "";
}
