#pragma once
#include "GameException.h"

#define THROW_VALUE(str) throw ValueException(str, __LINE__, __FILE__, __func__);

class ValueException :
	public GameException
{
public:
	ValueException(const std::string &description, const int &line, const std::string &file, const std::string &func, e_ExceptionLevel level = e_ExceptionLevel::EXCEPTION_SIMPLE_WARNING);
};

