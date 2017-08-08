#include <fstream>
#include "DatabaseJson.h"
#include "../constants.h"
#include "../Error/RessourceException.h"
#include "../Error/InitializationException.h"



DatabaseJson::DatabaseJson()
{
	m_roots.resize(DatabaseJson::e_JsonDatabase::JD_TOTAL);
	m_readers.resize(DatabaseJson::e_JsonDatabase::JD_TOTAL);
}


DatabaseJson::~DatabaseJson()
{
}


// Return the roots with modifying possibilities
std::vector<Json::Value>& DatabaseJson::getRealRoots()
{
	return m_roots;
}


// Return the readers with modifying possibilities
std::vector<Json::Reader>& DatabaseJson::getRealReaders()
{
	return m_readers;
}


int DatabaseJson::loadDatabase(int i, const std::string &filename)
{
	if (i < 0 || i >= DatabaseJson::e_JsonDatabase::JD_TOTAL)
		THROW_GAME("Impossible JDB " + std::to_string(i));

	std::ifstream file(filename);
	if (!file.is_open())
		THROW_RESSOURCE("JDB", filename);

	if (!m_readers.at(i).parse(file, m_roots.at(i), false))
		THROW_INIT("Couldn't parse JDB");

	return 0;
}