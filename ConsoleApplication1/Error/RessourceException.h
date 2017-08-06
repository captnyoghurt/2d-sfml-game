#pragma once
#include "GameException.h"


class RessourceException :
	public GameException
{
public:
	RessourceException(const std::string &description, const int &line, const std::string &file, const std::string &func, const std::string &filename, e_ExceptionLevel level = e_ExceptionLevel::EXCEPTION_WARNING) throw();
};

