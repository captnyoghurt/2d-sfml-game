#pragma once
#include "GameException.h"


class InitializationException :
	public GameException
{
public:
	InitializationException(const std::string &description, const int &line, const std::string &file, const std::string &func, e_ExceptionLevel level = e_ExceptionLevel::EXCEPTION_ERROR);
};

