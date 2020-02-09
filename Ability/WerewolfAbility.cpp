#include "../Units/Unit.h"
#include "WerewolfAbility.h"
#include "../States/WolfState.h"
#include "../Units/Properties.h"
#include "../Units/Exceptions.h"

WerewolfAbility::WerewolfAbility(Unit* owner)
	: Ability(owner)
{
}

WerewolfAbility::~WerewolfAbility() {}

void WerewolfAbility::useAbility() {
	if ( !m_owner->isAlive() ) { return; }

	transform();
}

void WerewolfAbility::useAbility(Unit* enemy) {
    const WolfState* currentState = dynamic_cast<const WolfState*>(m_owner->getState());

	if ( m_owner->isAlive() && currentState ) {
	    bite(enemy);
	}
//	else {
//	    throw NotAllowedException();
//	}
}

void WerewolfAbility::transform() {
	const WolfState* currentState = dynamic_cast<const WolfState*>(m_owner->getState());

	if ( currentState == nullptr ) {
		m_owner->setState(new WolfState(WEREWOLF, HP_WOLF, DMG_WOLF, false));
	} else {
		m_owner->setState(new State(WEREWOLF, HP_WEREWOLF, DMG_WEREWOLF, false));
	}
}

void WerewolfAbility::bite(Unit* enemy) {
	if (enemy == m_owner ) { throw InvalidTargetException(); }

	int unitType = enemy->getUnitType();

	if ( unitType != VAMPIRE && unitType != WEREWOLF && unitType != DEMON ) {
		enemy->setState(new State(WEREWOLF, HP_WEREWOLF, DMG_WEREWOLF, false));
		enemy->setAttack(new Attack(enemy));
		enemy->setAbility(new WerewolfAbility(enemy));
	}
}	