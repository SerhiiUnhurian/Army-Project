#include "Healer.h"
#include "SpellCaster.h"
#include "../Units/Properties.h"
#include "../States/State.h"
#include "../States/MagicState.h"
#include "../Attacks/Attack.h"

Healer::Healer(const std::string name, UnitType unitType) 
	: SpellCaster(name, new State(unitType, HP_HEALER, DMG_HEALER, false), new MagicState(MANA_HEALER, false), new Attack(this))
{
}

Healer::~Healer() {}