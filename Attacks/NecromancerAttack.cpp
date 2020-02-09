#include "NecromancerAttack.h"
#include "Attack.h"
#include "../Units/Unit.h"
#include "../Units/Exceptions.h"
#include "../Interface/Observer.h"
#include "../Interface/Observable.h"

#include "../Spellcasters/Necromancer.h"

NecromancerAttack::NecromancerAttack(Unit* owner) : Attack(owner) {}

NecromancerAttack::~NecromancerAttack() {}

void NecromancerAttack::attack(Unit* enemy) {
	Necromancer* nec = dynamic_cast<Necromancer*>(m_owner);
	nec->attach(enemy);

	Attack::attack(enemy);
}

void NecromancerAttack::counterAttack(Unit* enemy) {
	Necromancer* nec = dynamic_cast<Necromancer*>(m_owner);
	nec->attach(enemy);

	Attack::counterAttack(enemy);
}
