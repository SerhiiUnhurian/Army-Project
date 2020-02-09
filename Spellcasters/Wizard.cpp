#include "Wizard.h"
#include "SpellCaster.h"
#include "../Units/Properties.h"
#include "../States/State.h"
#include "../States/MagicState.h"
#include "../Attacks/Attack.h"

Wizard::Wizard(const std::string name, UnitType unitType) 
	: SpellCaster(name, new State(unitType, HP_WIZARD, DMG_WIZARD, false), new MagicState(MANA_WIZARD, true), new Attack(this))
{
}

Wizard::~Wizard() {}