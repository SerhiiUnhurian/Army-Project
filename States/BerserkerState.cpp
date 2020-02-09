#include "BerserkerState.h"
 
BerserkerState::BerserkerState(UnitType unitType, int hp, int dmg, bool isUndead) 
	: State(unitType, hp, dmg, isUndead)
{
}

BerserkerState::~BerserkerState() {}

void BerserkerState::takeMagicDamage(int dmg) { return; }
