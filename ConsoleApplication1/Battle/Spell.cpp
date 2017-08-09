#include "Spell.h"
#include "../Error/ValueException.h"



Spell::Spell()
{
}


Spell::~Spell()
{
}


// Return the id
int Spell::getId() const
{
	return m_id;
}


// Return the name
std::string Spell::getName() const
{
	return m_name;
}


// Modify the id
int Spell::setId(const int &id)
{
	if (id <= 0)
		THROW_VALUE(std::to_string(id));

	m_id = id;

	return id;
}


// Modify the name
int Spell::setName(const std::string &name)
{
	m_name = name;

	return 0;
}