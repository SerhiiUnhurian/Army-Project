#ifndef BERSERKER_H
#define BERSERKER_H

#include "Unit.h"
#include <iostream>

class Berserker final : public Unit {
public:
	Berserker(std::string name, UnitType unitType);
	virtual ~Berserker();
};

#endif // BERSERKER_H