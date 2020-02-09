#ifndef STATE_H
#define STATE_H

#include "../Units/Properties.h"
#include <iostream>

class State {
private:
	UnitType m_unitType;
	int m_hitPoints;
	int m_maxHitPoints;
	int m_damage;
	bool m_isUndead;

public:
	State(UnitType unitType, int hp, int dmg, bool isUndead);
	virtual ~State();

	UnitType getUnitType() const;
	int getHitPoints() const;
	int getMaxHitPoints() const;
	int getDamage() const;
	bool isUndead() const;
	void ensureIsAlive() const;

	bool isAlive() const;
	
	void setHitPoints(int newHP);

	void addHitPoints(int hp);
	void reduceHitPoints(int dmg);

	virtual void takeMagicDamage(int dmg);

	friend std::ostream& operator<<(std::ostream& out, const State* state);
};


#endif // STATE_H