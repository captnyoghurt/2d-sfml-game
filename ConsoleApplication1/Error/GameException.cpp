#include "GameException.h"


GameException::GameException(const std::string &description, const int &line, const std::string &file, const std::string &func, e_ExceptionLevel level) throw() :
	m_description("\n\nException raised : ")
{
	m_level = level;

	switch (level)
	{
	case 0: 
		m_description += "SIMPLE WARNING\n";
		break;
	case 1:
		m_description += "WARNING\n";
		break;
	case 2:
		m_description += "ERROR\n";
		break;
	case 3:
		m_description += "FATAL ERROR\n";
		break;
	default:
		m_description += "UNKNOWN LEVEL OF ERROR\n";
		break;
	}

	m_description = m_description + "Localisation :\n\tFile : " + file + "\n\tLine : " + std::to_string(line) + "\n\tFunction : " + func + "\n";
	m_description = m_description + "Description : \n\t" + description;
}


const char* GameException::what() const throw()
{
	return m_description.c_str();
}


void GameException::append(const std::string &desc) throw()
{
	m_description += ("\n\t" + desc);
}


e_ExceptionLevel GameException::getLevel() const throw()
{
	return m_level;
}