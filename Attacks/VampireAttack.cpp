#include "VampireAttack.h"
// #include "Attack.h"
#include "../Units/Unit.h"
#include "../Units/Properties.h"
#include "../Units/Exceptions.h"

#define STEAL_HP_COEFF 0.2

VampireAttack::VampireAttack(Unit* owner) : Attack(owner) {}

VampireAttack::~VampireAttack() {}

void VampireAttack::attack(Unit* enemy) {
	int stealHpAmount = enemy->getHitPoints() * STEAL_HP_COEFF;

	Attack::attack(enemy);

    if ( stealHpAmount > 0 ) {
	    m_owner->addHitPoints(stealHpAmount);
    }
}

void VampireAttack::counterAttack(Unit* enemy) {
	int stealHpAmount = enemy->getHitPoints() * STEAL_HP_COEFF;

	Attack::counterAttack(enemy);

    m_owner->addHitPoints(stealHpAmount);
}