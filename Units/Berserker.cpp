#include "Berserker.h"
#include "../States/BerserkerState.h"

Berserker::Berserker(std::string name, UnitType unitType)
	: Unit(name, new BerserkerState(unitType, HP_BERSERKER, DMG_BERSERKER, false), new Attack(this))
{
}

Berserker::~Berserker() {}

