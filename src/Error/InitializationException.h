#pragma once
#include "GameException.h"

#define THROW_INIT(str) throw InitializationException(str, __LINE__, __FILE__, __func__);

class InitializationException :
	public GameException
{
public:
	InitializationException(const std::string &description, const int &line, const std::string &file, const std::string &func, e_ExceptionLevel level = e_ExceptionLevel::EXCEPTION_ERROR);
};

