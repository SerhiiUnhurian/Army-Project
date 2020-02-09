#include "Necromancer.h"
#include "State.h"
#include "NecromancerState.h"

#define MAGIC_DMG_COEFF 1.2

NecromancerState::NecromancerState(UnitType unitType, int hp, int dmg, bool isUndead)
	: State(unitType, hp, dmg, isUndead)
{
}

NecromancerState::~NecromancerState() {}

// void reduceHitPoints(int hp) {
// 	State::reduceHitPoints(hp);

// 	// if ( !isAlive() && !m_observables.empty() ) {
// 	// 	auto it = m_observables.begin();

// 	// 	while ( it != m_observables.end() ) {
// 	// 		*it->unsubscribe(this);
// 			// it++;
// 	// 	}
// 	// }
// }

// void NecromancerState::takeMagicDamage(int dmg) {
// 	reduceHitPoints(dmg*MAGIC_DMG_COEFF);
// }