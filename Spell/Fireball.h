#ifndef FIREBALL_H
#define FIREBALL_H

#include "Spell.h"

class Unit;

class Fireball : public Spell {
public:
	Fireball();
	virtual ~Fireball();

	virtual void apply(Unit* target, float dmgCoeff, float healCoeff);

	virtual std::ostream& print(std::ostream& out) const override;
};

#endif // FIREBALL_H