#ifndef WEREWOLF_H
#define WEREWOLF_H

#include "Unit.h"
#include <iostream>

class Werewolf final : public Unit {
public:
	Werewolf(std::string name, UnitType unitType);
	virtual ~Werewolf();
};

#endif // WEREWOLF_H