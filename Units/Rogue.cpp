#include "Rogue.h"
#include "Properties.h"
#include "../Attacks/RogueAttack.h"
#include "../States/State.h"
#include "Unit.h"
#include <iostream>

Rogue::Rogue(std::string name, UnitType unitType) 
	: Unit(name, new State(unitType, HP_ROGUE, DMG_ROGUE, false), new RogueAttack(this))
{
}

Rogue::~Rogue() {}
