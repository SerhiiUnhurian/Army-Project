#ifndef NECROMANCER_ATTACK_H
#define NECROMANCER_ATTACK_H

#include "Attack.h"
#include "../Units/Unit.h"
// class Unit;

class NecromancerAttack : public Attack {
public:
	NecromancerAttack(Unit* owner);
	virtual ~NecromancerAttack();

	virtual void attack(Unit* enemy) override;
	virtual void counterAttack(Unit* enemy) override;
};

#endif // NECROMANCER_ATTACK_H