#ifndef MAGIC_STATE_H
#define MAGIC_STATE_H

#include <iostream>

class MagicState {
protected:
	int m_mana;
	int m_maxMana;
	float m_dmgCoeff;
	float m_healCoeff;

public:
	MagicState(int mana, bool isCombatant);
	virtual ~MagicState();

	int getMana() const;
	int getMaxMana() const;
	float getDmgCoeff() const;
	float getHealCoeff() const;

	void addMana(int mana);
	void reduceMana(int mana);
	
	 bool ensureHasMana(int mana) const;

	friend std::ostream& operator<<(std::ostream& out, const MagicState* magicState);

    void increaseMana(int i);
};

#endif // MAGIC_STATE_H
