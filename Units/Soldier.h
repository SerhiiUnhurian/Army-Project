#ifndef SOLDIER_H
#define SOLDIER_H

#include "Unit.h"
#include <iostream>

class Soldier : public Unit {
public:
	Soldier(const std::string name, UnitType unitType);
	virtual ~Soldier();
};

#endif // SOLDIER_H