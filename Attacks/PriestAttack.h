#ifndef PRIEST_ATTACK_H
#define PRIEST_ATTACK_H

#include "Attack.h"

class Unit;

class PriestAttack : public Attack {
public:
	PriestAttack(Unit* owner);
	virtual ~PriestAttack();

	virtual void attack(Unit* enemy) override;
	virtual void counterAttack(Unit* enemy) override;
};

#endif // PRIEST_ATTACK_H