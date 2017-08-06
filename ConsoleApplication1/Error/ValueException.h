#pragma once
#include "GameException.h"



class ValueException :
	public GameException
{
public:
	ValueException(const std::string &description, const int &line, const std::string &file, const std::string &func, e_ExceptionLevel level = e_ExceptionLevel::EXCEPTION_SIMPLE_WARNING);
};

