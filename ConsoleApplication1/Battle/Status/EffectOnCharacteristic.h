#pragma once
class EffectOnCharacteristic
{
public:
	EffectOnCharacteristic(const int &brut = 0, const double &ratio = 1.0);
	~EffectOnCharacteristic();

public:
	// Return the ratio of the bonus
	double getRatio() const;
	// Return the brut bonus
	int getBrut() const;
	// Return the number of turn stayed
	int getNumberOfTurn() const;

	// Modify the ratio of the bonus
	int setRatio(const double &ratio);
	// Modify the brut bonus
	int setBrut(const int &brut);
	// Modify the number of turn stayed
	int setNumberOfTurn(const int &turn);

	// Update the effect
	int update();
private:
	double m_ratio;
	int m_brut;
	int m_numberOfTurn;
};

