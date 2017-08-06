#pragma once
#include <exception>
#include <string>

#define THROW_GAME(str) throw GameException(str, __LINE__, __FILE__, __func__)

enum e_ExceptionLevel {EXCEPTION_SIMPLE_WARNING, EXCEPTION_WARNING, EXCEPTION_ERROR, EXCEPTION_FATAL_ERROR};

class GameException :
	public std::exception
{
public:
	GameException(const std::string &description, const int &line, const std::string &file, const std::string &func, e_ExceptionLevel level = EXCEPTION_FATAL_ERROR) throw();

	virtual	const char* what() const throw();

	void append(const std::string &desc) throw();

	e_ExceptionLevel getLevel() const throw();
protected:
	std::string m_description;
	e_ExceptionLevel m_level;
};

