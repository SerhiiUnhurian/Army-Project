#include "Werewolf.h"
#include "Properties.h"
#include "../Attacks/Attack.h"
#include "../States/State.h"
#include "../Ability/WerewolfAbility.h"
#include "Unit.h"
#include <iostream>

class WolfState;

#define MAGIC_DMG_COEFF 1.2

Werewolf::Werewolf(std::string name, UnitType unitType)
	: Unit(name, new State(unitType, HP_WEREWOLF, DMG_WEREWOLF, false), new Attack(this), new WerewolfAbility(this))
{
}

Werewolf::~Werewolf() {}