#pragma once
class Enemies
{
public:
	Enemies();
	Enemies(const Enemies &enemie, int number = -1);
	~Enemies();

public:

private:
	int m_health;
	int m_maxHealth;
};

