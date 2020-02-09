#include "Attack.h"
#include "../Units/Unit.h"
#include "../Units/Exceptions.h"

Attack::Attack(Unit* owner) : m_owner(owner) {}

Attack::~Attack() {}

void Attack::attack(Unit* enemy) {
	m_owner->ensureIsAlive();
	
	if (enemy == m_owner ) { throw InvalidTargetException(); }

    enemy->takeDamage(m_owner->getDamage());

    if ( enemy->isAlive() ) { 
		enemy->counterAttack(m_owner);
    }
}

void Attack::counterAttack(Unit* enemy) {
	enemy->takeDamage(m_owner->getDamage()/2);
}
