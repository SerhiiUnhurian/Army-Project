#include "Soldier.h"
#include "Properties.h"
#include <iostream>

Soldier::Soldier(const std::string name, UnitType unitType) 
	: Unit(name, new State(unitType, HP_SOLDIER, DMG_SOLDIER, false), new Attack(this))
{
}

Soldier::~Soldier() {}