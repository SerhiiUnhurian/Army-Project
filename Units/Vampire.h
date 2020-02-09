#ifndef VAMPIRE_H
#define VAMPIRE_H

#include "Unit.h"
#include <iostream>

enum UnitType;

class Vampire final : public Unit {
public:
	Vampire(std::string name, UnitType unitType);
	virtual ~Vampire();
};

#endif // VAMPIRE_H