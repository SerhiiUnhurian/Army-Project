#ifndef VAMPIRE_ATTACK_H
#define VAMPIRE_ATTACK_H

#include "Attack.h"

class Unit;

class VampireAttack : public Attack {
public:
	VampireAttack(Unit* owner);
	virtual ~VampireAttack();

	virtual void attack(Unit* enemy);
	virtual void counterAttack(Unit* enemy);
};

#endif // VAMPIRE_ATTACK_H