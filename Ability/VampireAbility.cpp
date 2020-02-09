#include "../Units/Unit.h"
#include "VampireAbility.h"
#include "../Units/Properties.h"
#include "../Attacks/VampireAttack.h"
#include "../Units/Exceptions.h"

VampireAbility::VampireAbility(Unit* owner)
	: Ability(owner)
{
}

VampireAbility::~VampireAbility() {}

void VampireAbility::useAbility() { return; }

void VampireAbility::useAbility(Unit* enemy) {
	if ( !m_owner->isAlive() ) { return; }

	bite(enemy);
}

void VampireAbility::bite(Unit* enemy) {
	if (enemy == m_owner ) { throw InvalidTargetException(); }

	int unitType = enemy->getUnitType();

	if ( unitType != VAMPIRE && unitType != WEREWOLF && unitType != DEMON  ) {
		enemy->setState(new State(VAMPIRE, HP_VAMPIRE, DMG_VAMPIRE, true));
		enemy->setAttack(new VampireAttack(enemy));
		enemy->setAbility(new VampireAbility(enemy));
	}
}