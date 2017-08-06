#include "ValueException.h"



ValueException::ValueException(const std::string &description, const int &line, const std::string &file, const std::string &func, e_ExceptionLevel level) : 
	GameException(description, line, file, func, level)
{
	append("Wrong value given");
}