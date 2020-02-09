#ifndef ROGUE_H
#define ROGUE_H

#include "Unit.h"
#include <iostream>

class Rogue final: public Unit {
public:
	Rogue(std::string name, UnitType unitType);
	virtual ~Rogue();
};

#endif // ROGUE_H