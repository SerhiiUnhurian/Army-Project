#include "PriestAttack.h"
#include "Attack.h"
#include "../Units/Unit.h"
#include "../Units/Exceptions.h"

PriestAttack::PriestAttack(Unit* owner) : Attack(owner) {}
PriestAttack::~PriestAttack() {}

void PriestAttack::attack(Unit* enemy) {
    m_owner->ensureIsAlive();

    if (enemy == m_owner ) { throw InvalidTargetException(); }

	if ( enemy->getState()->isUndead() == true ) {
		enemy->takeDamage(m_owner->getDamage() * 2);

		if ( enemy->isAlive() ) { 
	    	enemy->counterAttack(m_owner);
	    }
		return;
	}

    Attack::attack(enemy);
}

void PriestAttack::counterAttack(Unit* enemy) {
	if (  enemy->getState()->isUndead() == true ) {
		enemy->takeDamage(m_owner->getDamage());
		return;
	}

	Attack::counterAttack(enemy);
}
