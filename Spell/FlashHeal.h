#ifndef FLASH_HEAL_H
#define FLASH_HEAL_H

#include "Spell.h"

class Unit;

class FlashHeal : public Spell {
public:
	FlashHeal();
	virtual ~FlashHeal();

	virtual void apply(Unit* target, float dmgCoeff, float healCoeff);

	virtual std::ostream& print(std::ostream& out) const override;
};

#endif // FLASH_HEAL_H