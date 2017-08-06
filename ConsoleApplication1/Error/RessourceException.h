#pragma once
#include "GameException.h"

#define THROW_RESSOURCE(str, fname) throw RessourceException(str, __LINE__, __FILE__, __func__, fname)

class RessourceException :
	public GameException
{
public:
	RessourceException(const std::string &description, const int &line, const std::string &file, const std::string &func, const std::string &filename, e_ExceptionLevel level = e_ExceptionLevel::EXCEPTION_WARNING) throw();
};

