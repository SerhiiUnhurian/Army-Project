#include "RogueAttack.h"
#include "Attack.h"
#include "../Units/Unit.h"
#include "../Units/Exceptions.h"

RogueAttack::RogueAttack(Unit* owner) : Attack(owner) {}
RogueAttack::~RogueAttack() {}

void RogueAttack::attack(Unit* enemy) {
	m_owner->ensureIsAlive();
	
	if (enemy == m_owner ) { throw InvalidTargetException(); }

    enemy->takeDamage(m_owner->getDamage());
}
