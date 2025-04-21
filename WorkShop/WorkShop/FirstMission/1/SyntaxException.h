#pragma once

class SyntaxException
{
public:
	virtual const char* what() const noexcept;
};