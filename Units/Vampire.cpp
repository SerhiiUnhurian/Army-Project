#include "Vampire.h"
#include "Properties.h"
#include "../Attacks/VampireAttack.h"
#include "../Ability/VampireAbility.h"
#include "../States/State.h"
#include "Unit.h"
#include <iostream>

Vampire::Vampire(std::string name, UnitType unitType)
	: Unit(name, new State(unitType, HP_VAMPIRE, DMG_VAMPIRE, true), new VampireAttack(this), new VampireAbility(this))
{
}

Vampire::~Vampire() {}
