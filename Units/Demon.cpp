#include "Demon.h"
#include "Properties.h"
#include <iostream>

Demon::Demon(const std::string name, UnitType unitType, Unit* master) 
	: Unit(name, new State(unitType, HP_DEMON, DMG_DEMON, false), new Attack(this)), m_master(master )
{
}

Demon::~Demon() {};

// Unit* Demon::getMaster() const {
// 	return m_master;
// }