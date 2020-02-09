#include "WolfState.h"
#include "State.h"

//#define MAGIC_DMG_COEFF 1.2

WolfState::WolfState(UnitType unitType, int hp, int dmg, bool isUndead)
	: State(unitType, hp, dmg, isUndead)
{
}

WolfState::~WolfState() {}

void WolfState::takeMagicDamage(int dmg) {
    float magicDmgCoeff = 1.2;
	reduceHitPoints(dmg*magicDmgCoeff);
}
