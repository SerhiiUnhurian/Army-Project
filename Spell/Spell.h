#ifndef SPELL_H
#define SPELL_H

#include "../States/MagicState.h"
#include <iostream>

class Unit;

class Spell {
protected:
	int m_cost;
	int m_points;

	Spell(int cost, int points);
	virtual ~Spell();
	
public:
	int getCost() const;
	int getPoints() const;

	virtual void apply(Unit* target, float dmgCoeff, float healCoeff) = 0;

	virtual std::ostream& print(std::ostream& out) const = 0;
	friend std::ostream& operator<<(std::ostream& out, const Spell* spell);
};

#endif // SPELL_H