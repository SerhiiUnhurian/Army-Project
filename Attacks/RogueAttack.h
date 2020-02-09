#ifndef ROGUE_ATTACK_H
#define ROGUE_ATTACK_H

#include "Attack.h"

class Unit;

class RogueAttack : public Attack {
public:
	RogueAttack(Unit* owner);
	virtual ~RogueAttack();

	virtual void attack(Unit* enemy) override;
};

#endif // ROGUE_ATTACK_H